/*******************************************************************************
* File Name: Rx_Int.c  
* Version 1.50
*
*  Description:
*   API for controlling the state of an interrupt.
*
*
*  Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/


#include <CYDEVICE.H>
#include <CYDEVICE_TRM.H>
#include <CYLIB.H>
#include <Rx_Int.H>


/*******************************************************************************
*  Place your includes, defines and code here 
********************************************************************************/
/* `#START Rx_Int_intc` */

/* `#END` */


/*******************************************************************************
* Function Name: Rx_Int_Start
********************************************************************************
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   void.
*
*
* Return:
*   void.
*
*******************************************************************************/
void Rx_Int_Start(void)
{
    /* For all we know the interrupt is active. */
    Rx_Int_Disable();

    /* Set the ISR to point to the Rx_Int Interrupt. */
    Rx_Int_SetVector(Rx_Int_Interrupt);

    /* Set the priority. */
    Rx_Int_SetPriority(Rx_Int_INTC_PRIOR_NUMBER);

    /* Enable it. */
    Rx_Int_Enable();
}

/*******************************************************************************
* Function Name: Rx_Int_StartEx
********************************************************************************
* Summary:
*  Set up the interrupt and enable it.
*
* Parameters:  
*   address: Address of the ISR to set in the interrupt vector table.
*
*
* Return:
*   void.
*
*******************************************************************************/
void Rx_Int_StartEx(cyisraddress address)
{
    /* For all we know the interrupt is active. */
    Rx_Int_Disable();

    /* Set the ISR to point to the Rx_Int Interrupt. */
    Rx_Int_SetVector(address);

    /* Set the priority. */
    Rx_Int_SetPriority(Rx_Int_INTC_PRIOR_NUMBER);

    /* Enable it. */
    Rx_Int_Enable();
}

/*******************************************************************************
* Function Name: Rx_Int_Stop
********************************************************************************
* Summary:
*   Disables and removes the interrupt.
*
* Parameters:  
*
*
* Return:
*   void.
*
*******************************************************************************/
void Rx_Int_Stop(void) 
{
    /* Disable this interrupt. */
    Rx_Int_Disable();
}

/*******************************************************************************
* Function Name: Rx_Int_Interrupt
********************************************************************************
* Summary:
*   The default Interrupt Service Routine for Rx_Int.
*
*   Add custom code between the coments to keep the next version of this file
*   from over writting your code.
*
*
*
* Parameters:  
*
*
* Return:
*   void.
*
*******************************************************************************/
CY_ISR(Rx_Int_Interrupt)
{
    /*  Place your Interrupt code here. */
    /* `#START Rx_Int_Interrupt` */

    /* `#END` */

    /* PSoC3 ES1, ES2 RTC ISR PATCH  */ 
    #if(CYDEV_CHIP_FAMILY_USED == CYDEV_CHIP_FAMILY_PSOC3)
        #if((CYDEV_CHIP_REVISION_USED <= CYDEV_CHIP_REVISION_3A_ES2) && (Rx_Int__ES2_PATCH ))      
            Rx_Int_ISR_PATCH();
        #endif
    #endif
}

/*******************************************************************************
* Function Name: Rx_Int_SetVector
********************************************************************************
* Summary:
*   Change the ISR vector for the Interrupt. Note calling Rx_Int_Start
*   will override any effect this method would have had. To set the vector before
*   the component has been started use Rx_Int_StartEx instead.
*
*
* Parameters:
*   address: Address of the ISR to set in the interrupt vector table.
*
*
* Return:
*   void.
*
*
*******************************************************************************/
void Rx_Int_SetVector(cyisraddress address) 
{
    CY_SET_REG16(Rx_Int_INTC_VECTOR, (uint16) address);
}

/*******************************************************************************
* Function Name: Rx_Int_GetVector
********************************************************************************
* Summary:
*   Gets the "address" of the current ISR vector for the Interrupt.
*
*
* Parameters:
*   void.
*
*
* Return:
*   Address of the ISR in the interrupt vector table.
*
*
*******************************************************************************/
cyisraddress Rx_Int_GetVector(void) 
{
    return (cyisraddress) CY_GET_REG16(Rx_Int_INTC_VECTOR);
}

/*******************************************************************************
* Function Name: Rx_Int_SetPriority
********************************************************************************
* Summary:
*   Sets the Priority of the Interrupt. Note calling Rx_Int_Start
*   or Rx_Int_StartEx will override any effect this method would have had. 
*	This method should only be called after Rx_Int_Start or 
*	Rx_Int_StartEx has been called. To set the initial
*	priority for the component use the cydwr file in the tool.
*
*
* Parameters:
*   priority: Priority of the interrupt. 0 - 7, 0 being the highest.
*
*
* Return:
*   void.
*
*
*******************************************************************************/
void Rx_Int_SetPriority(uint8 priority) 
{
    *Rx_Int_INTC_PRIOR = priority << 5;
}

/*******************************************************************************
* Function Name: Rx_Int_GetPriority
********************************************************************************
* Summary:
*   Gets the Priority of the Interrupt.
*
*
* Parameters:
*   void.
*
*
* Return:
*   Priority of the interrupt. 0 - 7, 0 being the highest.
*
*
*******************************************************************************/
uint8 Rx_Int_GetPriority(void) 
{
    uint8 priority;


    priority = *Rx_Int_INTC_PRIOR >> 5;

    return priority;
}

/*******************************************************************************
* Function Name: Rx_Int_Enable
********************************************************************************
* Summary:
*   Enables the interrupt.
*
*
* Parameters:
*   void.
*
*
* Return:
*   void.
*
*
*******************************************************************************/
void Rx_Int_Enable(void) 
{
    /* Enable the general interrupt. */
    *Rx_Int_INTC_SET_EN = Rx_Int__INTC_MASK;
}

/*******************************************************************************
* Function Name: Rx_Int_GetState
********************************************************************************
* Summary:
*   Gets the state (enabled, disabled) of the Interrupt.
*
*
* Parameters:
*   void.
*
*
* Return:
*   1 if enabled, 0 if disabled.
*
*
*******************************************************************************/
uint8 Rx_Int_GetState(void) 
{
    /* Get the state of the general interrupt. */
    return (*Rx_Int_INTC_SET_EN & Rx_Int__INTC_MASK) ? 1:0;
}

/*******************************************************************************
* Function Name: Rx_Int_Disable
********************************************************************************
* Summary:
*   Disables the Interrupt.
*
*
* Parameters:
*   void.
*
*
* Return:
*   void.
*
*
*******************************************************************************/
void Rx_Int_Disable(void) 
{
    /* Disable the general interrupt. */
    *Rx_Int_INTC_CLR_EN = Rx_Int__INTC_MASK;
}

/*******************************************************************************
* Function Name: Rx_Int_SetPending
********************************************************************************
* Summary:
*   Causes the Interrupt to enter the pending state, a software method of
*   generating the interrupt.
*
*
* Parameters:
*   void.
*
*
* Return:
*   void.
*
*
*******************************************************************************/
void Rx_Int_SetPending(void) 
{
    *Rx_Int_INTC_SET_PD = Rx_Int__INTC_MASK;
}

/*******************************************************************************
* Function Name: Rx_Int_ClearPending
********************************************************************************
* Summary:
*   Clears a pending interrupt.
*
* Parameters:
*   void.
*
*
* Return:
*   void.
*
*
*******************************************************************************/
void Rx_Int_ClearPending(void) 
{
    *Rx_Int_INTC_CLR_PD = Rx_Int__INTC_MASK;
}
