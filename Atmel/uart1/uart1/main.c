/*
 * Se manda un msg por serial cada 1seg por el puerto serial 1.
 * para correr este demo debes habrir en tu PC una terminal por serial y setear su velocidad a 115200
 * no flow control y transferencia de 8 bits sin paridad
 * por default la velocidad de ejecucion seria de 8MHz
 */

#include <avr/io.h>
#include "types.h"
#include "uart/uart.h"
#include "delays/delays.h"
#include "gpios/gpios.h"

int main(void)
{
    Gpios_PinDirection(GPIOS_PORTD, 1, GPIOS_OUTPUT); /*pin de tx como salida*/
    (void)Uart_Init(UART_PORT0, 57600); /*se iniclaiza el puerto serial a 115200 baudios*/
    
    while (1)
    {
        Uart_PutString(UART_PORT0, (const _U08*)"Hola mundo\n\r");   /*se manda mensaje por puerto serial*/
        Delays_ms(1000);                    /*se cicla por 1 seg*/
    }
}

