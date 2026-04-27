/*	IO DEFINITIONS FOR STM8 S103 covers F and K family
 *	Copyright (c) 2010 by COSMIC Software
 */

/*	PORTS section
 */
/*	Port A
 */
#define PA_ODR (*(volatile unsigned char *)0x5000)	/* Data Output Latch reg */
#define PA_IDR (*(volatile unsigned char *)0x5001)	/* Input Pin Value reg */
#define PA_DDR (*(volatile unsigned char *)0x5002)	/* Data Direction */
#define PA_CR1 (*(volatile unsigned char *)0x5003)	/* Control register 1 */
#define PA_CR2 (*(volatile unsigned char *)0x5004)	/* Control register 2 */

/*	Port B
 */
#define PB_ODR (*(volatile unsigned char *)0x5005)	/* Data Output Latch reg */
#define PB_IDR (*(volatile unsigned char *)0x5006)	/* Input Pin Value reg */
#define PB_DDR (*(volatile unsigned char *)0x5007)	/* Data Direction */
#define PB_CR1 (*(volatile unsigned char *)0x5008)	/* Control register 1 */
#define PB_CR2 (*(volatile unsigned char *)0x5009)	/* Control register 2 */

/*	Port C
 */
#define PC_ODR (*(volatile unsigned char *)0x500a)	/* Data Output Latch reg */
#define PC_IDR (*(volatile unsigned char *)0x500b)	/* Input Pin Value reg */
#define PC_DDR (*(volatile unsigned char *)0x500c)	/* Data Direction */
#define PC_CR1 (*(volatile unsigned char *)0x500d)	/* Control register 1 */
#define PC_CR2 (*(volatile unsigned char *)0x500e)	/* Control register 2 */

/*	Port D
 */
#define PD_ODR (*(volatile unsigned char *)0x500f)	/* Data Output Latch reg */
#define PD_IDR (*(volatile unsigned char *)0x5010)	/* Input Pin Value reg */
#define PD_DDR (*(volatile unsigned char *)0x5011)	/* Data Direction */
#define PD_CR1 (*(volatile unsigned char *)0x5012)	/* Control register 1 */
#define PD_CR2 (*(volatile unsigned char *)0x5013)	/* Control register 2 */

/*	Port E
 */
#define PE_ODR (*(volatile unsigned char *)0x5014)	/* Data Output Latch reg */
#define PE_IDR (*(volatile unsigned char *)0x5015)	/* Input Pin Value reg */
#define PE_DDR (*(volatile unsigned char *)0x5016)	/* Data Direction */
#define PE_CR1 (*(volatile unsigned char *)0x5017)	/* Control register 1 */
#define PE_CR2 (*(volatile unsigned char *)0x5018)	/* Control register 2 */

/*	Port F
 */
#define PF_ODR (*(volatile unsigned char *)0x5019)	/* Data Output Latch reg */
#define PF_IDR (*(volatile unsigned char *)0x501a)	/* Input Pin Value reg */
#define PF_DDR (*(volatile unsigned char *)0x501b)	/* Data Direction */
#define PF_CR1 (*(volatile unsigned char *)0x501c)	/* Control register 1 */
#define PF_CR2 (*(volatile unsigned char *)0x501d)	/* Control register 2 */

/*	FLASH section
 */
#define FLASH_CR1 (*(volatile unsigned char *)0x505a)	/* Flash Control Register 1 */
#define FLASH_CR2 (*(volatile unsigned char *)0x505b)	/* Flash Control Register 2 */
#define FLASH_NCR2 (*(volatile unsigned char *)0x505c)	/* Flash Complementary Control Reg 2 */
#define FLASH_FPR (*(volatile unsigned char *)0x505d)	/* Flash Protection reg */
#define FLASH_NFPR (*(volatile unsigned char *)0x505e)	/* Flash Complementary Protection reg */
#define FLASH_IAPSR (*(volatile unsigned char *)0x505f)	/* Flash in-appl Prog. Status reg */
#define FLASH_PUKR (*(volatile unsigned char *)0x5062)	/* Flash Program memory unprotection reg */
#define FLASH_DUKR (*(volatile unsigned char *)0x5064)	/* Data EEPROM unprotection reg */

/*	External Interrupt Controller section
 */
#define EXTI_CR1 (*(volatile unsigned char *)0x50a0)	/* Ext Int Ctrl reg 1 */
#define EXTI_CR2 (*(volatile unsigned char *)0x50a1)	/* Ext Int Ctrl reg 2 */

/*	RSTC section
 */
#define RST_SR (*(volatile unsigned char *)0x50b3)	/* Reset Status register */

/*	CLOCK section
 */
#define CLK_ICKCR (*(volatile unsigned char *)0x50c0)	/* Internal Clock Control reg */
#define CLK_ECKCR (*(volatile unsigned char *)0x50c1)	/* External Clock Control reg */
#define CLK_CMSR (*(volatile unsigned char *)0x50c3)	/* Master Status reg */
#define CLK_SWR (*(volatile unsigned char *)0x50c4)	/* Master Switch reg */
#define CLK_SWCR (*(volatile unsigned char *)0x50c5)	/* Switch Control reg */
#define CLK_CKDIVR (*(volatile unsigned char *)0x50c6)	/* Divider register */
#define CLK_PCKENR1 (*(volatile unsigned char *)0x50c7)	/* Peripheral Clock Gating reg 1 */
#define CLK_CSSR (*(volatile unsigned char *)0x50c8)	/* Security System register */
#define CLK_CCOR (*(volatile unsigned char *)0x50c9)	/* Configurable Clock Ctrl reg */
#define CLK_PCKENR2 (*(volatile unsigned char *)0x50ca)	/* Peripheral Clock Gating reg 2 */
#define CLK_CANCCR (*(volatile unsigned char *)0x50cb)	/* Can Clock Control reg */
#define CLK_HSITRIMR (*(volatile unsigned char *)0x50cc)	/* HSI Calibration Trimming reg */
#define CLK_SWIMCCR (*(volatile unsigned char *)0x50cd)	/* SWIM Clock Control reg */

/*	WATCHDOG section
 */
#define WWDG_CR (*(volatile unsigned char *)0x50d1)	/* WWDG Control register */
#define WWDG_WR (*(volatile unsigned char *)0x50d2)	/* WWDG Window register */
#define IWDG_KR (*(volatile unsigned char *)0x50e0)	/* IWDG Key register */
#define IWDG_PR (*(volatile unsigned char *)0x50e1)	/* IWDG Prescaler register */
#define IWDG_RLR (*(volatile unsigned char *)0x50e2)	/* IWDG Reload register */

/*	AWU section
 */
#define AWU_CSR1 (*(volatile unsigned char *)0x50f0)	/* AWU Control/Status reg 1 */
#define AWU_APR (*(volatile unsigned char *)0x50f1)	/* AWU Async Prescale Buffer reg */
#define AWU_TBR (*(volatile unsigned char *)0x50f2)	/* AWU Timebase selection reg */
#define BEEP_CSR (*(volatile unsigned char *)0x50f3)	/* BEEP control/status reg */

/*	SPI section
 */
#define SPI_CR1 (*(volatile unsigned char *)0x5200)	/* SPI Control register 1 */
#define SPI_CR2 (*(volatile unsigned char *)0x5201)	/* SPI Control register 2 */
#define SPI_ICR (*(volatile unsigned char *)0x5202)	/* SPI Interrupt/Ctrl reg */
#define SPI_SR (*(volatile unsigned char *)0x5203)	/* SPI Status register */
#define SPI_DR (*(volatile unsigned char *)0x5204)	/* SPI Data I/O reg */
#define SPI_CRCPR (*(volatile unsigned char *)0x5205)	/* SPI CRC Polynomial reg */
#define SPI_RXCRCR (*(volatile unsigned char *)0x5206)	/* SPI Rx CRC register */
#define SPI_TXCRCR (*(volatile unsigned char *)0x5207)	/* SPI Tx CRC register */

/*	I2C section
 */
#define I2C_CR1 (*(volatile unsigned char *)0x5210)	/* Control register 1 */
#define I2C_CR2 (*(volatile unsigned char *)0x5211)	/* Control register 2 */
#define I2C_FREQR (*(volatile unsigned char *)0x5212)	/* Frequency register */
#define I2C_OARL (*(volatile unsigned char *)0x5213)	/* Own Address reg low */
#define I2C_OARH (*(volatile unsigned char *)0x5214)	/* Own Address reg high */
#define I2C_DR (*(volatile unsigned char *)0x5216)	/* Data Register */
#define I2C_SR1 (*(volatile unsigned char *)0x5217)	/* Status Register 1 */
#define I2C_SR2 (*(volatile unsigned char *)0x5218)	/* Status Register 2 */
#define I2C_SR3 (*(volatile unsigned char *)0x5219)	/* Status Register 3 */
#define I2C_ITR (*(volatile unsigned char *)0x521a)	/* Interrupt Control reg */
#define I2C_CCRL (*(volatile unsigned char *)0x521b)	/* Clock Control reg low */
#define I2C_CCRH (*(volatile unsigned char *)0x521c)	/* Clock Control reg high */
#define I2C_TRISER (*(volatile unsigned char *)0x521d)	/* Trise reg */
#define I2C_PECR (*(volatile unsigned char *)0x521e)	/* Packet Error Checking reg */

/*	UART1 section
 */
#define UART1_SR (*(volatile unsigned char *)0x5230)	/* Status register */
#define UART1_DR (*(volatile unsigned char *)0x5231)	/* Data register */
#define UART1_BRR1 (*(volatile unsigned char *)0x5232)	/* Baud Rate reg 1 */
#define UART1_BRR2 (*(volatile unsigned char *)0x5233)	/* Baud Rate reg 2 */
#define UART1_CR1 (*(volatile unsigned char *)0x5234)	/* Control register 1 */
#define UART1_CR2 (*(volatile unsigned char *)0x5235)	/* Control register 2 */
#define UART1_CR3 (*(volatile unsigned char *)0x5236)	/* Control register 3 */
#define UART1_CR4 (*(volatile unsigned char *)0x5237)	/* Control register 4 */
#define UART1_CR5 (*(volatile unsigned char *)0x5238)	/* Control register 5 */
#define UART1_GTR (*(volatile unsigned char *)0x5239)	/* Guard Time register */
#define UART1_PSCR (*(volatile unsigned char *)0x523a)	/* Prescaler register */

/*	TIMER 1 section
 */
#define TIM1_CR1 (*(volatile unsigned char *)0x5250)	/* Control register 1 */
#define TIM1_CR2 (*(volatile unsigned char *)0x5251)	/* Control register 2 */
#define TIM1_SMCR (*(volatile unsigned char *)0x5252)	/* Slave Mode Control reg */
#define TIM1_ETR (*(volatile unsigned char *)0x5253)	/* External Trigger reg */
#define TIM1_IER (*(volatile unsigned char *)0x5254)	/* Interrupt Enable reg */
#define TIM1_SR1 (*(volatile unsigned char *)0x5255)	/* Status register 1 */
#define TIM1_SR2 (*(volatile unsigned char *)0x5256)	/* Status register 2 */
#define TIM1_EGR (*(volatile unsigned char *)0x5257)	/* Event Generation reg */
#define TIM1_CCMR1 (*(volatile unsigned char *)0x5258)	/* Capture/Compare Mode reg 1 */
#define TIM1_CCMR2 (*(volatile unsigned char *)0x5259)	/* Capture/Compare Mode reg 2 */
#define TIM1_CCMR3 (*(volatile unsigned char *)0x525a)	/* Capture/Compare Mode reg 3 */
#define TIM1_CCMR4 (*(volatile unsigned char *)0x525b)	/* Capture/Compare Mode reg 4 */
#define TIM1_CCER1 (*(volatile unsigned char *)0x525c)	/* Capture/Compare Enable reg 1 */
#define TIM1_CCER2 (*(volatile unsigned char *)0x525d)	/* Capture/Compare Enable reg 2 */
#define TIM1_CNTRH (*(volatile unsigned char *)0x525e)	/* Counter reg High */
#define TIM1_CNTRL (*(volatile unsigned char *)0x525f)	/* Counter reg Low */
#define TIM1_PSCRH (*(volatile unsigned char *)0x5260)	/* Prescaler reg High */
#define TIM1_PSCRL (*(volatile unsigned char *)0x5261)	/* Prescaler reg Low */
#define TIM1_ARRH (*(volatile unsigned char *)0x5262)	/* Auto-reload reg High */
#define TIM1_ARRL (*(volatile unsigned char *)0x5263)	/* Auto-reload reg Low */
#define TIM1_RCR (*(volatile unsigned char *)0x5264)	/* Repetition Counter reg */
#define TIM1_CCR1H (*(volatile unsigned char *)0x5265)	/* Capture/Compare reg 1 High */
#define TIM1_CCR1L (*(volatile unsigned char *)0x5266)	/* Capture/Compare reg 1 Low */
#define TIM1_CCR2H (*(volatile unsigned char *)0x5267)	/* Capture/Compare reg 2 High */
#define TIM1_CCR2L (*(volatile unsigned char *)0x5268)	/* Capture/Compare reg 2 Low */
#define TIM1_CCR3H (*(volatile unsigned char *)0x5269)	/* Capture/Compare reg 3 High */
#define TIM1_CCR3L (*(volatile unsigned char *)0x526a)	/* Capture/Compare reg 3 Low */
#define TIM1_CCR4H (*(volatile unsigned char *)0x526b)	/* Capture/Compare reg 4 High */
#define TIM1_CCR4L (*(volatile unsigned char *)0x526c)	/* Capture/Compare reg 4 Low */
#define TIM1_BKR (*(volatile unsigned char *)0x526d)	/* Break register */
#define TIM1_DTR (*(volatile unsigned char *)0x526e)	/* Dead Time register */
#define TIM1_OISR (*(volatile unsigned char *)0x526f)	/* Output Idle State reg */

/*	TIMER 2 section
 */
#define TIM2_CR1 (*(volatile unsigned char *)0x5300)	/* Control register 1 */
#define TIM2_IER (*(volatile unsigned char *)0x5303)	/* Interrupt Enable reg */
#define TIM2_SR1 (*(volatile unsigned char *)0x5304)	/* Status Register 1 */
#define TIM2_SR2 (*(volatile unsigned char *)0x5305)	/* Status Register 2 */
#define TIM2_EGR (*(volatile unsigned char *)0x5306)	/* Event Generation reg */
#define TIM2_CCMR1 (*(volatile unsigned char *)0x5307)	/* Capture/Compare Mode reg 1 */
#define TIM2_CCMR2 (*(volatile unsigned char *)0x5308)	/* Capture/Compare Mode reg 2 */
#define TIM2_CCMR3 (*(volatile unsigned char *)0x5309)	/* Capture/Compare Mode reg 3 */
#define TIM2_CCER1 (*(volatile unsigned char *)0x530a)	/* Capture/Compare Enable reg 1 */
#define TIM2_CCER2 (*(volatile unsigned char *)0x530b)	/* Capture/Compare Enable reg 2 */
#define TIM2_CNTRH (*(volatile unsigned char *)0x530c)	/* Counter reg High */
#define TIM2_CNTRL (*(volatile unsigned char *)0x530d)	/* Counter reg Low */
#define TIM2_PSCR (*(volatile unsigned char *)0x530e)	/* Prescaler register */
#define TIM2_ARRH (*(volatile unsigned char *)0x530f)	/* Auto-reload reg High */
#define TIM2_ARRL (*(volatile unsigned char *)0x5310)	/* Auto-reload reg Low */
#define TIM2_CCR1H (*(volatile unsigned char *)0x5311)	/* Capture/Compare Reg 1 High */
#define TIM2_CCR1L (*(volatile unsigned char *)0x5312)	/* Capture/Compare Reg 1 Low */
#define TIM2_CCR2H (*(volatile unsigned char *)0x5313)	/* Capture/Compare Reg 2 High */
#define TIM2_CCR2L (*(volatile unsigned char *)0x5314)	/* Capture/Compare Reg 2 Low */
#define TIM2_CCR3H (*(volatile unsigned char *)0x5315)	/* Capture/Compare Reg 3 High */
#define TIM2_CCR3L (*(volatile unsigned char *)0x5316)	/* Capture/Compare Reg 3 Low */

/*	TIMER 4 section
 */
#define TIM4_CR1 (*(volatile unsigned char *)0x5340)	/* Control register 1 */
#define TIM4_IER (*(volatile unsigned char *)0x5343)	/* Interrupt enable reg */
#define TIM4_SR (*(volatile unsigned char *)0x5344)	/* Status register */
#define TIM4_EGR (*(volatile unsigned char *)0x5345)	/* Event Generation reg */
#define TIM4_CNTR (*(volatile unsigned char *)0x5346)	/* Counter register */
#define TIM4_PSCR (*(volatile unsigned char *)0x5347)	/* Prescaler register */
#define TIM4_ARR (*(volatile unsigned char *)0x5348)	/* Auto-reload register */

/*	ADC section
 */
#define ADC_DBR ((volatile unsigned char *)0x53e0)    /* data buffer registers */
#define ADC_CSR (*(volatile unsigned char *)0x5400)	/* Control/Status reg */
#define ADC_CR1 (*(volatile unsigned char *)0x5401)	/* Configuration reg 1 */
#define ADC_CR2 (*(volatile unsigned char *)0x5402)	/* Configuration reg 2 */
#define ADC_CR3 (*(volatile unsigned char *)0x5403)	/* Configuration reg 3 */
#define ADC_DRH (*(volatile unsigned char *)0x5404)	/* Data reg high */
#define ADC_DRL (*(volatile unsigned char *)0x5405)	/* Data reg low */
#define ADC_TDRH (*(volatile unsigned char *)0x5406)	/* Schmitt Trigger Disable reg high */
#define ADC_TDRL (*(volatile unsigned char *)0x5407)	/* Schmitt Trigger Disable reg low */
#define ADC_HTRH (*(volatile unsigned char *)0x5408)	/* high threshold reg high */
#define ADC_HTRL (*(volatile unsigned char *)0x5409)	/* high threshold reg low */
#define ADC_LTRH (*(volatile unsigned char *)0x540a)	/* low threshold reg high */
#define ADC_LTRL (*(volatile unsigned char *)0x540b)	/* low threshold reg low */
#define ADC_AWSRH (*(volatile unsigned char *)0x540c)	/* analog watchdog status reg high */
#define ADC_AWSRL (*(volatile unsigned char *)0x540d)	/* analog watchdog status reg low */
#define ADC_AWCRH (*(volatile unsigned char *)0x540e)	/* analog watchdog control reg high */
#define ADC_AWCRL (*(volatile unsigned char *)0x540f)	/* analog watchdog control reg low */

/*	CFG section
 */
#define CFG_GCR (*(volatile unsigned char *)0x7f60)	/* Global Configuration register */

/*	ITC section
 */
#define ITC_SPR1 (*(volatile unsigned char *)0x7f70)	/* Interrupt Software Priority Reg 1 */
#define ITC_SPR2 (*(volatile unsigned char *)0x7f71)	/* Interrupt Software Priority Reg 2 */
#define ITC_SPR3 (*(volatile unsigned char *)0x7f72)	/* Interrupt Software Priority Reg 3 */
#define ITC_SPR4 (*(volatile unsigned char *)0x7f73)	/* Interrupt Software Priority Reg 4 */
#define ITC_SPR5 (*(volatile unsigned char *)0x7f74)	/* Interrupt Software Priority Reg 5 */
#define ITC_SPR6 (*(volatile unsigned char *)0x7f75)	/* Interrupt Software Priority Reg 6 */
#define ITC_SPR7 (*(volatile unsigned char *)0x7f76)	/* Interrupt Software Priority Reg 7 */
#define ITC_SPR8 (*(volatile unsigned char *)0x7f77)	/* Interrupt Software Priority Reg 8 */

/*	SWIM section
 */
#define SWIM_CSR (*(volatile unsigned char *)0x7f80)	/* SWIM Control Status Register */

/*	In-Circuit Debugging section 
 */                                            
#define DM_BK1RE (*(volatile unsigned char *)0x7f90)	/* IC Debugging Breakpoint 1 ESB Reg */
#define DM_BK1RH (*(volatile unsigned char *)0x7f91)	/* IC Debugging Breakpoint 1 High */
#define DM_BK1RL (*(volatile unsigned char *)0x7f92)	/* IC Debugging Breakpoint 1 Low */
#define DM_BK2RE (*(volatile unsigned char *)0x7f93)	/* IC Debugging Breakpoint 2 ESB Reg */
#define DM_BK2RH (*(volatile unsigned char *)0x7f94)	/* IC Debugging Breakpoint 2 High */
#define DM_BK2RL (*(volatile unsigned char *)0x7f95)	/* IC Debugging Breakpoint 2 Low */
#define DM_CR1 (*(volatile unsigned char *)0x7f96)	/* IC Debugging Control register 1 */
#define DM_CR2 (*(volatile unsigned char *)0x7f97)	/* IC Debugging Control register 2 */
#define DM_CSR1 (*(volatile unsigned char *)0x7f98)	/* IC Debugging Control/Status reg 1 */
#define DM_CSR2 (*(volatile unsigned char *)0x7f99)	/* IC Debugging Control/Status reg 2 */
#define DM_ENFCTR (*(volatile unsigned char *)0x7f9a)	/* IC Debugging Function Enable Reg 2 */
