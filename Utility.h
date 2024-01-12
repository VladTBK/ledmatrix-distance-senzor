void Init_UC(void);

#define INSTR_PER_US 12                   // instructions per microsecond (depends on MCU clock, 12MHz current)
#define INSTR_PER_MS 12000                // instructions per millisecond (depends on MCU clock, 12MHz current)
#define MAX_RESP_TIME_MS 200      // timeout - max time to wait for low voltage drop (higher value increases measuring distance at the price of slower sampling)
#define DELAY_BETWEEN_TESTS_MS 50 // echo cancelling time between sampling
#ifndef NULL
#define NULL  0
#endif
        
// logix ...
#define TRUE    1
#define FALSE    0 
#define DUMMY    0

#define wdogtrig()            #asm("wdr") // call often if Watchdog timer enabled

#define CR                0x0D
#define LF                0x0A  




// General Defines
#ifndef BIT_SIZE8 
#define BIT_SIZE8 8     
#endif

#ifndef BIT_VALUES8 
#define BIT_VALUES8 256
#endif

#ifndef RXB8
#define RXB8 1
#endif

#ifndef TXB8
#define TXB8 0
#endif

#ifndef UPE
#define UPE 2
#endif

#ifndef DOR
#define DOR 3
#endif

#ifndef FE
#define FE 4
#endif

#ifndef UDRE
#define UDRE 5
#endif

#ifndef RXC
#define RXC 7
#endif

//Flags Defines

#define FRAMING_ERROR (1<<FE)
#define PARITY_ERROR (1<<UPE)
#define DATA_OVERRUN (1<<DOR)
#define DATA_REGISTER_EMPTY (1<<UDRE)
#define RX_COMPLETE (1<<RXC)