#include <xc.h>
#include "fuses.h"
#include "onewire/onewire.h"
#include "delays/delays.h"
#include "uart/uart.h"
#include "system/system.h"
#include "gpios/gpios.h"

int main ( void )
{
    _U08 array[8];
    _U08 i;

    System_EnablePLL();
    Gpios_PinDirection( GPIOS_PORTC, 6, GPIOS_OUTPUT );
    Uart_Init( UART_PORT1, 9600 );
    Uart_PutString( UART_PORT1, "Leyendo ROM code: ");
    OneWire_bResetPulse( ONEWIRE_PORT0 );
    OneWire_WriteByte( ONEWIRE_PORT0, 0x33 );
    for(i=0;i<8;i++)
    {
        array[i] = OneWire_u8ReadByte( ONEWIRE_PORT0 );
    }
    Uart_PutChar( UART_PORT1, array[1]);
    Uart_PutChar( UART_PORT1, array[2]);
    Uart_PutChar( UART_PORT1, array[3]);
    Uart_PutChar( UART_PORT1, array[4]);
    Uart_PutChar( UART_PORT1, array[5]);
    Uart_PutChar( UART_PORT1, array[6]);
    
    while(1)
    {
        
        Delays_ms( 50 );
    }
}

