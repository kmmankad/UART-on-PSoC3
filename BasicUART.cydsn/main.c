/* Basic 8-bit UART RX with ISR
 Author : Kartik Mankad
 Date : 16-Nov-2011
 This code is licensed as CC-BY-SA 3.0
 Description : 8bit UART,Reception handled by an ISR.
 Operation:	Standard UART config,9600-8-N-1-No Flow control.
			A Byte Recd triggers an ISR,
			that clears the interrupt and prints to LCD.
 Note:	Buffer size is 1 byte,
 		*** Address Mode is disabled,since this is RS232(not 485)
		Rest of the settings are at their defaults.
*/
#include <device.h>

CY_ISR(Rx_ISR){//ISR for 'On Byte Recd.'
	uint16 GetB;//16bit var for storing GetByte's return.
	UART_ReadRxStatus();//Read it to clear interrupts.
	GetB=UART_GetByte();//MSB has RxStatus Reg,and LSB has the data.
	LCD_PutChar(LO8(GetB));//Print the LSB(Rx'd Data) to the LCD.
}

void main(){
	CYGlobalIntDisable;//Disable interrupts to avoid triggering during setup.
    LCD_Start();// Start LCD.
	UART_Start();// Start UART.
	Rx_Int_Start();//Start the Interrupt.
	Rx_Int_SetVector(Rx_ISR);//Set the Vector to the ISR.
	LCD_PrintString("UART:RX ISR Demo");//Print to the LCD.
	UART_PutString("UART:RX ISR Demo");//Print to Serial Terminal.
	CyDelay(1000);
	LCD_ClearDisplay();//Clear the screen for RX Data.
	CYGlobalIntEnable;//Enable Interrupts,and let the Games begin!
	
    for(;;);
}

