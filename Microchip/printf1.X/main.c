/*
 * redireccionamiento de la funcion xprintf por puerto serial y trasnmicionde diversas cadenas
 * formateadas via serial (sin interrupciones) usando la funcion xprintf
 * por default la velocidad de ejecucion seria de 12MHz
 */

#include <xc.h>
#include "fuses.h"
#include "types.h"
#include "gpios/gpios.h"
#include "uart/uart.h"
#include "printf/printf.h"

void putc(unsigned char c)
{
    Uart_PutChar(UART_PORT1, c);
}

int main(void)
{
    ANCON0 = 0XFF;  /*Desactivamos las entradas analogicas*/
    ANCON1 = 0XFF;  /*Desactivamos las entradas analogicas*/

    Gpios_PinDirection(GPIOS_PORTC, 6, GPIOS_OUTPUT); /*puerto de tx como salida*/
    (void)Uart_Init(UART_PORT1, 115200); /*velocidad a 115200 bauds*/
    xdev_out(putc);  /*funcion Uart1_PutChar como salida*/

    /*Se recomienda manejar siempre parametros arriba de 16 bits para un correcto funcionamiento*/
    /*cuando se usan constantes se debe forzosamente realizar un castaje, como en este ejemplo*/
    xprintf("Probando funcion printf:\r\n");
    xprintf("%d\r\n", (_S16)1234);                    //"1234"
    xprintf("%6d,%3d%%\r\n", (_S16)-200, (_S16)5);    //"  -200,  5%"
    xprintf("%-6u\r\n", (_S16)100);                   //"100   "
    xprintf("%ld\r\n", 12345678L);                    //"12345678"
    xprintf("%04x\r\n", (_U16)0xA3);                  //"00a3"
    xprintf("%08LX\r\n", (_U32)0x123ABC);             //"00123ABC"
    xprintf("%016b\r\n", (_U16)0x550F);               //"0101010100001111"
    xprintf("%c\r\n", (_U16)'a');                     //"a"

    while (1)
    {

    }
}

