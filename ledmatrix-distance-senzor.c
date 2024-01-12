#include <mega164a.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <delay.h>
#include "Utility.h"
volatile  unsigned long timerCounter;
volatile  unsigned long result;
volatile  unsigned long count;

interrupt [TIM0_OVF] void ovf_interrupt (void)
{
timerCounter = timerCounter+1; // count the number of overflows             
}

// Declare your global variables her



void main(void)
{result = 0; timerCounter = 0;
Init_UC();
TCCR0B = (0<<CS02)|(0<<CS01)|(1<<CS00); // select internal clock with no prescaling
TCNT0 = 0; // reset counter to zero
TIMSK0 = 1<<TOIE0; // enable timer interrupt
#asm("sei");

while (TRUE)
      {wdogtrig();
      
      PORTA.0 =1; // set high for 10us
      delay_us(10);
      PORTA.0 = 0; // clear  
      TCNT1H = 0;TCNT1L = 0;    /* Clear Timer counter */
      TCCR1B = 0x41;    /* Capture on rising edge, No prescaler*/
      TIFR1 = 1<<ICF1;    /* Clear ICP flag (Input Capture flag) */
      TIFR1 = 1<<TOV1;    /* Clear Timer Overflow flag */
      while ((TIFR1 & (1 << ICF1)) == 0);/* Wait for rising edge */
     TCNT1H = 0;TCNT1L = 0;    /* Clear Timer counter */
     TCCR1B = 0x01;    /* Capture on falling edge, No prescaler */
     TIFR1 = 1<<ICF1;    /* Clear ICP flag (Input Capture flag) */
     TIFR1 = 1<<TOV1;    /* Clear Timer Overflow flag */
     timerCounter = 0;
     while ((TIFR1 & (1 << ICF1)) == 0);  
      
      count =  (timerCounter * 256 + TCNT0);  //timpul curent + cat a fost overflow
      result =  count * 0.00857;  // rezultat masurat in milimetrii 
      DDRD=(1<<DDD7);
      if(result <= 50){DDRD=(0<<DDD7);}
      else if(result >50 && result <=100){OCR2A = 0xFF;}
      else if(result >100 && result <=150){OCR2A = 0x20;} 
      else if(result >150 && result <=200 ){OCR2A = 0x10;} 
      else { OCR2A = 0x00;}
      delay_ms(100);     
      }
}