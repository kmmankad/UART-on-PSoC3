/*******************************************************************************
* File Name: Rx_Int.h
* Version 1.50
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/
#if !defined(__Rx_Int_INTC_H__)
#define __Rx_Int_INTC_H__


#include <cytypes.h>
#include <cyfitter.h>

#if(CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3)     
    #if(CYDEV_CHIP_REVISION_USED <= CYDEV_CHIP_REVISION_3A_ES2)      
        #include <intrins.h>
        #define Rx_Int_ISR_PATCH() _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
    #endif
#endif


/* Interrupt Controller API. */
void Rx_Int_Start(void);
void Rx_Int_StartEx(cyisraddress address);
void Rx_Int_Stop(void) ;

CY_ISR_PROTO(Rx_Int_Interrupt);

void Rx_Int_SetVector(cyisraddress address) ;
cyisraddress Rx_Int_GetVector(void) ;

void Rx_Int_SetPriority(uint8 priority) ;
uint8 Rx_Int_GetPriority(void) ;

void Rx_Int_Enable(void) ;
uint8 Rx_Int_GetState(void) ;
void Rx_Int_Disable(void) ;

void Rx_Int_SetPending(void) ;
void Rx_Int_ClearPending(void) ;


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Rx_Int ISR. */
#define Rx_Int_INTC_VECTOR            ((reg16 *) Rx_Int__INTC_VECT)

/* Address of the Rx_Int ISR priority. */
#define Rx_Int_INTC_PRIOR             ((reg8 *) Rx_Int__INTC_PRIOR_REG)

/* Priority of the Rx_Int interrupt. */
#define Rx_Int_INTC_PRIOR_NUMBER      Rx_Int__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Rx_Int interrupt. */
#define Rx_Int_INTC_SET_EN            ((reg8 *) Rx_Int__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Rx_Int interrupt. */
#define Rx_Int_INTC_CLR_EN            ((reg8 *) Rx_Int__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Rx_Int interrupt state to pending. */
#define Rx_Int_INTC_SET_PD            ((reg8 *) Rx_Int__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Rx_Int interrupt. */
#define Rx_Int_INTC_CLR_PD            ((reg8 *) Rx_Int__INTC_CLR_PD_REG)



/* __Rx_Int_INTC_H__ */
#endif
