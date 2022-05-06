/**
  * TCA0 Generated Driver File
  *
  * @file tca0.c
  *
  * @ingroup tca0
  *
  * @brief This file contains the driver code for TCA0 module.
  *
  * @version TCA0 Driver Version 2.1.1
*/
/*
© [2022] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/


#include "../tca0.h"

const struct TMR_INTERFACE TCA0_Interface = {
    .Initialize = TCA0_Initialize,
    .Start = NULL,
    .Stop = NULL,
    .PeriodCountSet = NULL,
    .TimeoutCallbackRegister = NULL,
    .Tasks = NULL
};

void TCA0_DefaultHighCountCallbackRegister(void);
void (*TCA0_HCNT_isr_cb)(void) = &TCA0_DefaultHighCountCallbackRegister;
void TCA0_DefaultLowCompare0CallbackRegister(void);
void (*TCA0_LCMP0_isr_cb)(void) = &TCA0_DefaultLowCompare0CallbackRegister;
void TCA0_DefaultLowCompare1CallbackRegister(void);
void (*TCA0_LCMP1_isr_cb)(void) = &TCA0_DefaultLowCompare1CallbackRegister;
void TCA0_DefaultLowCompare2CallbackRegister(void);
void (*TCA0_LCMP2_isr_cb)(void) = &TCA0_DefaultLowCompare2CallbackRegister;
void TCA0_DefaultLowCountCallbackRegister(void);
void (*TCA0_LCNT_isr_cb)(void) = &TCA0_DefaultLowCountCallbackRegister;

void TCA0_DefaultHighCountCallbackRegister(void)
{
    //Add your ISR code here
}

void TCA0_DefaultLowCompare0CallbackRegister(void)
{
    //Add your ISR code here
}

void TCA0_DefaultLowCompare1CallbackRegister(void)
{
    //Add your ISR code here
}

void TCA0_DefaultLowCompare2CallbackRegister(void)
{
    //Add your ISR code here
}

void TCA0_DefaultLowCountCallbackRegister(void)
{
    //Add your ISR code here
}

void TCA0_HighCountCallbackRegister(TCA0_cb_t cb)
{
    TCA0_HCNT_isr_cb = cb;
}

void TCA0_LowCompare0CallbackRegister(TCA0_cb_t cb)
{
    TCA0_LCMP0_isr_cb = cb;
}

void TCA0_LowCompare1CallbackRegister(TCA0_cb_t cb)
{
    TCA0_LCMP1_isr_cb = cb;
}

void TCA0_LowCompare2CallbackRegister(TCA0_cb_t cb)
{
    TCA0_LCMP2_isr_cb = cb;
}

void TCA0_LowCountCallbackRegister(TCA0_cb_t cb)
{
    TCA0_LCNT_isr_cb = cb;
}

ISR(TCA0_HUNF_vect)
{
    if (TCA0_HCNT_isr_cb != NULL)
        (*TCA0_HCNT_isr_cb)();
    
    TCA0.SPLIT.INTFLAGS = TCA_SPLIT_HUNF_bm;
}

ISR(TCA0_LCMP0_vect)
{
    if (TCA0_LCMP0_isr_cb != NULL)
        (*TCA0_LCMP0_isr_cb)();
    
    TCA0.SPLIT.INTFLAGS = TCA_SPLIT_LCMP0_bm;
}

ISR(TCA0_LCMP1_vect)
{
    if (TCA0_LCMP1_isr_cb != NULL)
        (*TCA0_LCMP1_isr_cb)();
    
    TCA0.SPLIT.INTFLAGS = TCA_SPLIT_LCMP1_bm;
}

ISR(TCA0_LCMP2_vect)
{
    if (TCA0_LCMP2_isr_cb != NULL)
        (*TCA0_LCMP2_isr_cb)();
    
    TCA0.SPLIT.INTFLAGS = TCA_SPLIT_LCMP2_bm;
}

ISR(TCA0_LUNF_vect)
{
    if (TCA0_LCNT_isr_cb != NULL)
        (*TCA0_LCNT_isr_cb)();
    
    TCA0.SPLIT.INTFLAGS = TCA_SPLIT_LUNF_bm;
}


void TCA0_Initialize(void) {
    
    // SPLITM enabled; 
    TCA0.SPLIT.CTRLD = 0x1;
    
    // HCMP0EN enabled; HCMP1EN disabled; HCMP2EN disabled; LCMP0EN enabled; LCMP1EN disabled; LCMP2EN disabled; 
    TCA0.SPLIT.CTRLB = 0x11;
    
    // HCMP0OV disabled; HCMP1OV disabled; HCMP2OV disabled; LCMP0OV disabled; LCMP1OV disabled; LCMP2OV disabled; 
    TCA0.SPLIT.CTRLC = 0x0;
    
    // CMD NONE; CMDEN NONE; 
    TCA0.SPLIT.CTRLECLR = 0x0;
    
    // CMD NONE; CMDEN NONE; 
    TCA0.SPLIT.CTRLESET = 0x0;
    
    // DBGRUN disabled; 
    TCA0.SPLIT.DBGCTRL = 0x0;
    
    // HCMP0 20; 
    TCA0.SPLIT.HCMP0 = 0x14;
        
    // HCMP1 0; 
    TCA0.SPLIT.HCMP1 = 0x0;
    
    // HCMP2 0; 
    TCA0.SPLIT.HCMP2 = 0x0;
        
    // HCNT 0; 
    TCA0.SPLIT.HCNT = 0x0;
    
    // HPER 82; 
    TCA0.SPLIT.HPER = 0x52;
    
    // HUNF disabled; LCMP0 disabled; LCMP1 disabled; LCMP2 disabled; LUNF disabled; 
    TCA0.SPLIT.INTCTRL = 0x0;
    
    // HUNF disabled; LCMP0 disabled; LCMP1 disabled; LCMP2 disabled; LUNF disabled; 
    TCA0.SPLIT.INTFLAGS = 0x0;
    
    // LCMP0 124; 
    TCA0.SPLIT.LCMP0 = 0x7C;
        
    // LCMP1 0; 
    TCA0.SPLIT.LCMP1 = 0x0;
    
    // LCMP2 0; 
    TCA0.SPLIT.LCMP2 = 0x0;
        
    // LCNT 0; 
    TCA0.SPLIT.LCNT = 0x0;
    
    // LPER 249; 
    TCA0.SPLIT.LPER = 0xF9;
    
    // CLKSEL DIV16; ENABLE enabled; RUNSTDBY disabled; 
    TCA0.SPLIT.CTRLA = 0x9;
    

}

void TCA0_Start(void)
{
    TCA0.SPLIT.CTRLA|= TCA_SPLIT_ENABLE_bm;
}

void TCA0_Stop(void)
{
    TCA0.SPLIT.CTRLA&= ~TCA_SPLIT_ENABLE_bm;
}

void TCA0_WriteLowCount(uint8_t timerVal)
{
    TCA0.SPLIT.LCNT=timerVal;
}

uint8_t TCA0_ReadLowCount(void)
{
    uint8_t readVal;

    readVal = TCA0.SPLIT.LCNT;

    return readVal;
}

void TCA0_WriteHighCount(uint8_t timerVal)
{
    TCA0.SPLIT.HCNT=timerVal;
}

uint8_t TCA0_ReadHighCount(void)
{
    uint8_t readVal;

    readVal = TCA0.SPLIT.HCNT;

    return readVal;
}

void TCA0_EnableInterrupt(void)
{
        TCA0.SPLIT.INTCTRL = 1 << TCA_SPLIT_HUNF_bp /* High Underflow Interrupt Enable: enabled */
	                | 1 << TCA_SPLIT_LCMP0_bp /* Low Compare 0 Interrupt Enable: enabled */
	                | 1 << TCA_SPLIT_LCMP1_bp /* Low Compare 1 Interrupt Enable: enabled */
	                | 1 << TCA_SPLIT_LCMP2_bp /* Low Compare 2 Interrupt Enable: enabled */
	                | 1 << TCA_SPLIT_LUNF_bp; /* Low Underflow Interrupt Enable: enabled */
}
void TCA0_DisableInterrupt(void)
{
    TCA0.SPLIT.INTCTRL = 0 << TCA_SPLIT_HUNF_bp    /* High Underflow Interrupt Enable: disabled */
	                | 0 << TCA_SPLIT_LCMP0_bp /* Low Compare 0 Interrupt Enable: disabled */
	                | 0 << TCA_SPLIT_LCMP1_bp /* Low Compare 1 Interrupt Enable: disabled */
	                | 0 << TCA_SPLIT_LCMP2_bp /* Low Compare 2 Interrupt Enable: disabled */
	                | 0 << TCA_SPLIT_LUNF_bp; /* Low Underflow Interrupt Enable: disabled */
}

void TCA0_ClearHUNFInterruptFlag(void)
{
    TCA0.SPLIT.INTFLAGS = TCA_SPLIT_HUNF_bm; /* Clear High-Byte Underflow Interrupt Flag */
}

bool TCA0_IsHUNFInterruptFlagSet(void)
{
    return ((TCA0.SPLIT.INTFLAGS & TCA_SPLIT_HUNF_bm) > 0);
}

void TCA0_ClearLUNFInterruptFlag(void)
{
    TCA0.SPLIT.INTFLAGS = TCA_SPLIT_LUNF_bm; /* Clear Low-Byte Underflow Interrupt Flag */
}

bool TCA0_IsLUNFInterruptFlagSet(void)
{
    return ((TCA0.SPLIT.INTFLAGS & TCA_SPLIT_LUNF_bm) > 0);
}

void TCA0_ClearLCMP0InterruptFlag(void)
{
    TCA0.SPLIT.INTFLAGS = TCA_SPLIT_LCMP0_bm; /* Clear Low-Byte Compare Channel-0 Interrupt Flag */
}

bool TCA0_IsLCMP0InterruptFlagSet(void)
{
    return ((TCA0.SPLIT.INTFLAGS & TCA_SPLIT_LCMP0_bm) > 0);
}

void TCA0_ClearLCMP1InterruptFlag(void)
{
    TCA0.SPLIT.INTFLAGS = TCA_SPLIT_LCMP1_bm; /* Clear Low-Byte Compare Channel-1 Interrupt Flag */
}

bool TCA0_IsLCMP1InterruptFlagSet(void)
{
    return ((TCA0.SPLIT.INTFLAGS & TCA_SPLIT_LCMP1_bm) > 0);
}

void TCA0_ClearLCMP2InterruptFlag(void)
{
    TCA0.SPLIT.INTFLAGS = TCA_SPLIT_LCMP2_bm; /* Clear Low-Byte Compare Channel-2 Interrupt Flag */
}

bool TCA0_IsLCMP2InterruptFlagSet(void)
{
    return ((TCA0.SPLIT.INTFLAGS & TCA_SPLIT_LCMP2_bm) > 0);
}