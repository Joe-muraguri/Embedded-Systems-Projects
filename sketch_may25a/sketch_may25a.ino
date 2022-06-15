#define TIM2     (uint32_t *) 0x40000000  // base address pointer for timer 2
#define RCC  (uint32_t *) 0x40021000   //base address pointer for system clock registers block
#define  RCC_APB1ENR  0x1C   //timer 2 clock enable register offset
#define TIM2EN  0   //bit zero is timer 2 clock enable bit
#define CCMR1 0x18 //CCMR1 register offset from the timer 2 base address
//CC1S is bits 1:0 of CCMR1
#define CC1S0    0    //bit 0 of CCMR1
#define CC1S1    1   //bit 1 of CCMR1
//Note that since the reset value of the register is 0x00000000, we do not need to program CC1S //with 00 as this is the value on reset
#define CCER  0x20  // CCER offset
#define CC1E  0   // CC1E is bit 0 of CCER
#define CC1P  1    // CC1P is bit 1 of CCER
// OC1M: Output compare 1 mode is bits 6:4 of CCMR1
#define OC1M4   4  // bit 4 of CCMR1
#define OC1M5   5  // bit 5 of CCMR1
#define OC1M6   6  // bit 6 of CCMR1
#define SMCR  0x08 // SMCR offset on timer 2
//TS: Trigger selection is bits  6:4
#define TS4    4 //bit 4 of SMCR
#define TS5    5 //bit 5 of SMCR
#define TS6    6 //bit 6 of SMCR
// OC1PE: Output compare 1 preload enable is bit 3 of CCMR1 register
#define    OC1PE  3  // bit 3 of CCMR1
#define CR1  0x00  // CR1 offset
#define CEN 0    // CEN is bit 0 of CR1
#define DIR  4    // DIR is bit 4 of CR1
#define   AFIO  (uint32_t *)  0x40010000 // base address pointer to AFIO
#define    AFIO_MAPR   0x04  //remapping register offset
#define    AFIO_MAPR9 9        // bit 9 of  AFIO_MAPR
#define    AFIO_MAPR8 8        // bit 8 of  AFIO_MAPR
// note that the default value (00)  of the register means there is no need to program if a remap is not required
#define GPIOA   (uint32_t *) 0x40010800 // base address
#define CRL  0x00 // offset
//CNF0 are bits 3:2
#define CNF02  2  //bit 2 of CRL
#define CNF03  3  //bit 3 of CRL
//MODE0 are bits 1:0
#define MODE00  0 // bit 0 of CRL
#define MODE01   1// bit 1 of CRL
#define   RCC_APB2ENR 0x18  // offset from RCC base address
#define   IOPAEN  2  // bit 2 of  RCC_APB2ENR
#define CNT 0x24
#define PSC 0x28
#define ARR 0x2C
#define CCR1 0x34
//bit modifying macros
#define setbit(base_addr, offset, bit)  (*(base_addr + offset)) |= 1<<bit
#define clearbit(base_addr, offset, bit)  (*(base_addr + offset)) &= ~(1<<bit)
//register modifying macros
#define modify_reg(base_addr, offset, value)  (*(base_addr + offset)) = value
// this is to include the standard library c99
#include<stdint.h>
int main()
{
// timer 2 clock enable
setbit( RCC,  RCC_APB1ENR,  TIM2EN) ;  // timer 2 clock
setbit(RCC, RCC_APB2ENR,  IOPAEN) ;    // GPIOA clock

//configuring  properties of ALT timer 2 chan 1: CNF = 10 (push-pull), MODE = 10 (2Mhz speed)
//CNF
setbit(GPIOA,  CRL,  CNF03) ;
clearbit( GPIOA,  CRL,  CNF02) ;
//MODE
setbit(GPIOA,  CRL,  MODE01) ;
setbit(GPIOA,  CRL,  MODE00) ;

//setting up timer 2 channel 1
//CC1S is bits 1:0 of CCMR1 requires 00 for chan 1 as output.
clearbit( TIM2, CCMR1,  CC1S0) ;
clearbit( TIM2, CCMR1,  CC1S1)  ;
//Reset value is also 00 so no need to program

//setting timer 2 output mode
// OC1M: Output compare 1 mode is bits 6:4 of CCMR1 we need the value 011: for toggling the //output when TIMx_CNT=TIMx_CCR1.
clearbit(TIM2,  CCMR1,  OC1M6) ;
setbit(TIM2,  CCMR1,  OC1M5) ;
setbit(TIM2,  CCMR1,  OC1M4) ;

//Enabling channel 1 sets bit 0 of CCER
setbit(TIM2,  CCER,  CC1E) ;

//setting clock toggling speed with prescaler and auto-reload register
//default clock speed is 8Mhz, therefore for 1Hz auto-reload register x prescaler = 8,000,000
//we choose prescaler(PSC) = 8000-1 and auto-reload(ARR) = 1000-1 for counting inclusive zero.

uint32_t PSC_VALUE  =  8000-1 ;
uint32_t ARR_VALUE  = 1000-1 ;
modify_reg(TIM2, PSC, PSC_VALUE ) ;
modify_reg(TIM2, ARR, ARR_VALUE) ;
//counter(CNT) initialisation
uint32_t CNT_VALUE = 0;
modify_reg(TIM2, CNT, CNT_VALUE ) ;
//capture/compare register 1 (CCR1)
uint32_t CCR1_VALUE = 0;
modify_reg(TIM2, CCR1, CCR1_VALUE ) ;
//enabling timer2
setbit(TIM2, CR1, CEN) ;
while(1) ;
}
