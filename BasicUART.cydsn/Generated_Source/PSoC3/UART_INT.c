/*******************************************************************************
* File Name: UART_INT.c
* Version 2.10
*
* Description:
*  This file provides all Interrupt Service functionality of the UART component
*
* Note:
*  Any unusual or non-standard behavior should be noted here. Other-
*  wise, this section should remain blank.
*
*******************************************************************************
* Copyright 2008-2011, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "UART.h"
#include "CyLib.h"


/***************************************
* Custom Declratations
***************************************/
/* `#START CUSTOM_DECLARATIONS` Place your declaration here */

/* `#END` */

#if( (UART_RX_ENABLED || UART_HD_ENABLED) && \
     (UART_RXBUFFERSIZE > UART_FIFO_LENGTH))

    extern volatile uint8 UART_rxBuffer[];
    extern volatile uint8 UART_rxBufferRead;
    extern volatile uint8 UART_rxBufferWrite;
    extern volatile uint8 UART_rxBufferLoopDetect;
    extern volatile uint8 UART_rxBufferOverflow;
    #if (UART_RXHW_ADDRESS_ENABLED)
        extern volatile uint8 UART_rxAddressMode;
        extern volatile uint8 UART_rxAddressDetected;
    #endif /* End EnableHWAddress */    

    /*******************************************************************************
    * Function Name: UART_RXISR
    ********************************************************************************
    *
    * Summary:
    *  Interrupt Service Routine for RX portion of the UART
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  UART_rxBuffer - RAM buffer pointer for save received data.
    *  UART_rxBufferWrite - cyclic index for write to rxBuffer, 
    *     increments after each byte saved to buffer.
    *  UART_rxBufferRead - cyclic index for read from rxBuffer, 
    *     checked to detect overflow condition.
    *  UART_rxBufferOverflow - software overflow flag. Set to one
    *     when UART_rxBufferWrite index overtakes 
    *     UART_rxBufferRead index.
    *  UART_rxBufferLoopDetect - additional variable to detect overflow.
    *     Set to one when UART_rxBufferWrite is equal to 
    *    UART_rxBufferRead
    *  UART_rxAddressMode - this variable contains the Address mode, 
    *     selected in customizer or set by UART_SetRxAddressMode() API.
    *  UART_rxAddressDetected - set to 1 when correct address received,
    *     and analysed to store following addressed data bytes to the buffer.
    *     When not correct address received, set to 0 to skip following data bytes.
    *
    *******************************************************************************/
    CY_ISR(UART_RXISR)
    {
        uint8 readData;
        uint8 increment_pointer = 0;

        /* User code required at start of ISR */
        /* `#START UART_RXISR_START` */

        /* `#END` */

        readData = UART_RXSTATUS_REG;

        if((readData & (UART_RX_STS_BREAK | UART_RX_STS_PAR_ERROR |
                        UART_RX_STS_STOP_ERROR | UART_RX_STS_OVERRUN)) != 0)
        {
            /* ERROR handling. */
            /* `#START UART_RXISR_ERROR` */

            /* `#END` */
        }

        while(readData & UART_RX_STS_FIFO_NOTEMPTY)
        {
            
            #if (UART_RXHW_ADDRESS_ENABLED)
                if(UART_rxAddressMode == UART__B_UART__AM_SW_DETECT_TO_BUFFER) 
                {
                    if((readData & UART_RX_STS_MRKSPC) != 0u )
                    {  
                        if ((readData & UART_RX_STS_ADDR_MATCH) != 0)
                        {
                            UART_rxAddressDetected = 1u;
                        }
                        else
                        {
                            UART_rxAddressDetected = 0u;
                        }
                    }

                    readData = UART_RXDATA_REG;
                    if(UART_rxAddressDetected != 0u)
                    {   /* store only addressed data */
                        UART_rxBuffer[UART_rxBufferWrite] = readData;
                        increment_pointer = 1u;
                    }
                }
                else /* without software addressing */
                {
                    UART_rxBuffer[UART_rxBufferWrite] = UART_RXDATA_REG;
                    increment_pointer = 1u;
                }
            #else  /* without addressing */
                UART_rxBuffer[UART_rxBufferWrite] = UART_RXDATA_REG;
                increment_pointer = 1u;
            #endif /* End SW_DETECT_TO_BUFFER */
            
            /* do not increment buffer pointer when skip not adderessed data */
            if( increment_pointer != 0u )
            {
                if(UART_rxBufferLoopDetect)
                {   /* Set Software Buffer status Overflow */
                    UART_rxBufferOverflow = 1u;
                }
                /* Set next pointer. */
                UART_rxBufferWrite++;

                /* Check pointer for a loop condition */
                if(UART_rxBufferWrite >= UART_RXBUFFERSIZE)
                {
                    UART_rxBufferWrite = 0u;
                }
                /* Detect pre-overload condition and set flag */
                if(UART_rxBufferWrite == UART_rxBufferRead)
                {
                    UART_rxBufferLoopDetect = 1u;
                    /* When Hardware Flow Control selected */
                    #if(UART_FLOW_CONTROL != 0u)
                    /* Disable RX interrupt mask, it will be enabled when user read data from the buffer using APIs */
                        UART_RXSTATUS_MASK_REG  &= ~UART_RX_STS_FIFO_NOTEMPTY;
                        CyIntClearPending(UART_RX_VECT_NUM); 
                        break; /* Break the reading of the FIFO loop, leave the data there for generating RTS signal */
                    #endif /* End UART_FLOW_CONTROL != 0 */    
                }
            }

            /* Check again if there is data. */
            readData = UART_RXSTATUS_REG;
        }

        /* User code required at end of ISR (Optional) */
        /* `#START UART_RXISR_END` */

        /* `#END` */

        /* PSoC3 ES1, ES2 RTC ISR PATCH  */
        #if(CY_PSOC3_ES2 && (UART_RXInternalInterrupt__ES2_PATCH))
            UART_ISR_PATCH();
        #endif /* End CY_PSOC3_ES2*/
    }

#endif /* End UART_RX_ENABLED && (UART_RXBUFFERSIZE > UART_FIFO_LENGTH) */


#if(UART_TX_ENABLED && (UART_TXBUFFERSIZE > UART_FIFO_LENGTH))

    extern volatile uint8 UART_txBuffer[];
    extern volatile uint8 UART_txBufferRead;
    extern uint8 UART_txBufferWrite;


    /*******************************************************************************
    * Function Name: UART_TXISR
    ********************************************************************************
    *
    * Summary:
    * Interrupt Service Routine for the TX portion of the UART
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  UART_txBuffer - RAM buffer pointer for transmit data from.
    *  UART_txBufferRead - cyclic index for read and transmit data 
    *     from txBuffer, increments after each transmited byte.
    *  UART_rxBufferWrite - cyclic index for write to txBuffer, 
    *     checked to detect available for transmission bytes.
    *
    *******************************************************************************/
    CY_ISR(UART_TXISR)
    {

        /* User code required at start of ISR */
        /* `#START UART_TXISR_START` */

        /* `#END` */

        while((UART_txBufferRead != UART_txBufferWrite) && \
             !(UART_TXSTATUS_REG & UART_TX_STS_FIFO_FULL))
        {
            /* Check pointer. */
            if(UART_txBufferRead >= UART_TXBUFFERSIZE)
            {
                UART_txBufferRead = 0u;
            }

            UART_TXDATA_REG = UART_txBuffer[UART_txBufferRead];

            /* Set next pointer. */
            UART_txBufferRead++;
        }

        /* User code required at end of ISR (Optional) */
        /* `#START UART_TXISR_END` */

        /* `#END` */
        
        /* PSoC3 ES1, ES2 RTC ISR PATCH  */
        #if(CY_PSOC3_ES2 && (UART_TXInternalInterrupt__ES2_PATCH))
            UART_ISR_PATCH();
        #endif /* End CY_PSOC3_ES2*/
    }

#endif /* End UART_TX_ENABLED && (UART_TXBUFFERSIZE > UART_FIFO_LENGTH) */


/* [] END OF FILE */
