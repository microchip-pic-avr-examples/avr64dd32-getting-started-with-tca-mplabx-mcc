/**
 * TCA0 Generated Driver API Header File
 *
 * @file tca0.h
 *
 * @defgroup tca0 TCA0
 *
 * @brief This header file provides APIs for the TCA0 driver.
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


#ifndef TCA0_H_INCLUDED
#define TCA0_H_INCLUDED

#include "../system/utils/compiler.h"
#include "timer_interface.h"

#ifdef __cplusplus
extern "C" {
#endif
    
/**
 * @ingroup tca0
 * @typedef void TCA0_cb_t
 * @brief Function pointer to callback function called for split timer by TCA. NULL=default value: No callback function is to be used.
 */  
typedef void (*TCA0_cb_t)(void);    

extern const struct TMR_INTERFACE TCA0_Interface;

/**
 * @ingroup tca0
 * @brief Initialize for split mode for TCA interface.
 * @param none
 * @return none
 */ 
void TCA0_Initialize(void);
/**
 * @ingroup tca0
 * @brief API to start the split timer/counter for TCA interface
 * @param none
 * @return none
 */
void TCA0_Start(void);
/**
 * @ingroup tca0
 * @brief API to stop the split timer/counter for TCA interface
 * @param none
 * @return none
 */
void TCA0_Stop(void);
/**
 * @ingroup tca0
 * @brief ISR callback function register to be called for high count Timer 1 interrupt flag is set.
 * @param TCA0_cb_t cb - call back value for Timer 1.
 * @return none
 */ 
void TCA0_HighCountCallbackRegister(TCA0_cb_t cb);
/**
 * @ingroup tca0
 * @brief ISR callback function register to be called for lower byte Compare 0 interrupt flag is set. 
 * @param TCA0_cb_t cb - call back value for Compare 0.
 * @return none
 */ 
void TCA0_LowCompare0CallbackRegister(TCA0_cb_t cb);
/**
 * @ingroup tca0
 * @brief ISR callback function register to be called for lower byte Compare 1 interrupt flag is set. 
 * @param TCA0_cb_t cb - call back value for Compare 1.
 * @return none
 */ 
void TCA0_LowCompare1CallbackRegister(TCA0_cb_t cb);
/**
 * @ingroup tca0
 * @brief ISR callback function register to be called for lower byte Compare 2 interrupt flag is set. 
 * @param TCA0_cb_t cb - call back value for Compare 2.
 * @return none
 */ 
void TCA0_LowCompare2CallbackRegister(TCA0_cb_t cb);
/**
 * @ingroup tca0
 * @brief ISR callback function register to be called for low count Timer2 interrupt flag is set.
 * @param TCA0_cb_t cb - call back value for Timer 2.
 * @return none
 */ 
void TCA0_LowCountCallbackRegister(TCA0_cb_t cb);
/**
 * @ingroup tca0
 * @brief Enable the split Timer/Counter interrupt for TCA interface.
 * @param none
 * @return none
 */
void TCA0_EnableInterrupt(void);
/**
 * @ingroup tca0
 * @brief Disable the split Timer/Counter interrupt for TCA interface.
 * @param none
 * @return none
 */
void TCA0_DisableInterrupt(void);
/**
 * @ingroup tca0
 * @brief API to read the high 8-bit timer/counter1 value for TCA interface.
 * @param none
 * @return uint8_t - timer/counter1 value returns from the TCA0 interface.
 */
uint8_t TCA0_ReadHighCount(void);
/**
 * @ingroup tca0
 * @brief API to write the high 8-bit timer/counter1 value to load for TCA interface
 * @param uint8_t timerVal - Loading the timer1 value for TCA.
 * @return none
 */
void TCA0_WriteHighCount(uint8_t timerVal);
/**
 * @ingroup tca0
 * @brief API to read the low 8-bit timer/counter2 value for TCA interface.
 * @param none
 * @return uint8_t - timer/counter2 value returns from the TCA0 interface.
 */
uint8_t TCA0_ReadLowCount(void);
/**
 * @ingroup tca0
 * @brief API to write the low 8-bit timer/counter2 value to load for TCA interface
 * @param uint8_t timerVal - Loading the timer2 value for TCA.
 * @return none
 */
void TCA0_WriteLowCount(uint8_t timerVal); 
/**
 * @ingroup tca0
 * @brief Clear the high byte underflow interrupt enable, if the flag is set.
 * @param none
 * @return none
 */
void TCA0_ClearHUNFInterruptFlag(void);
/**
 * @ingroup tca0
 * @brief API to check the high byte underflow interrupt flag status for split timer/counter.
 * @param none
 * @retval true  - High byte underflow interrupt flag was set.
 * @retval false - High byte underflow interrupt flag was not set.
 */
bool TCA0_IsHUNFInterruptFlagSet(void);
/**
 * @ingroup tca0
 * @brief Clear the low byte underflow interrupt enable, if the flag is set.
 * @param none
 * @return none
 */
void TCA0_ClearLUNFInterruptFlag(void);
/**
 * @ingroup tca0
 * @brief API to check the low byte underflow interrupt flag status for split timer/counter.
 * @param none
 * @retval true  - High byte underflow interrupt flag was set.
 * @retval false - High byte underflow interrupt flag was not set.
 */
bool TCA0_IsLUNFInterruptFlagSet(void);
/**
 * @ingroup tca0
 * @brief Clear the low byte Compare channel 0 interrupt enable, if the flag is set for TCA.
 * @param none
 * @return none
 */
void TCA0_ClearLCMP0InterruptFlag(void);
/**
 * @ingroup tca0
 * @brief API to check the low byte Compare channe1 0 interrupt flag status for TCA interface.
 * @param none
 * @retval true  - Low byte compare channel 0 interrupt flag was set.
 * @retval false - Low byte compare channel 0 interrupt flag was not set.
 */
bool TCA0_IsLCMP0InterruptFlagSet(void);
/**
 * @ingroup tca0
 * @brief Clear the low byte Compare channel 1 interrupt enable, if the flag is set for TCA.
 * @param none
 * @return none
 */
void TCA0_ClearLCMP1InterruptFlag(void);
/**
 * @ingroup tca0
 * @brief API to check the low byte Compare channe1 1 interrupt flag status for TCA interface.
 * @param none
 * @retval true  - Low byte compare channel 1 interrupt flag was set.
 * @retval false - Low byte compare channel 1 interrupt flag was not set.
 */
bool TCA0_IsLCMP1InterruptFlagSet(void);
/**
 * @ingroup tca0
 * @brief Clear the low byte Compare channel 2 interrupt enable, if the flag is set for TCA.
 * @param none
 * @return none
 */
void TCA0_ClearLCMP2InterruptFlag(void);
/**
 * @ingroup tca0
 * @brief API to check the low byte Compare channe1 2 interrupt flag status for TCA interface.
 * @param none
 * @retval true  - Low byte compare channel 2 interrupt flag was set.
 * @retval false - Low byte compare channel 2 interrupt flag was not set.
 */
bool TCA0_IsLCMP2InterruptFlagSet(void);
#ifdef __cplusplus
}
#endif

#endif /* TCA0_H_INCLUDED */