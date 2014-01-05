/*
 * redireccionamiento de la funcion xprintf por puerto serial y trasnmicionde diversas cadenas
 * formateadas via serial (sin interrupciones) usando la funcion xprintf
 * por default la velocidad de ejecucion seria de 12MHz
 */

#include <p18cxxx.h>
#include "vectors.h"
#include "types.h"
#include "gpios/gpios.h"
#include "uart/uart1.h"
#include "printf/printf.h"

#pragma code
void main(void)
{

    ANCON0 = 0XFF;  /*Desativamos las salidas analogicas*/
    ANCON1 = 0XFF;  /*Desativamos las salidas analogicas*/

    Gpios_PinDirection(GPIOS_PORTC, 6, GPIOS_OUTPUT); /*puerto de tx como salida*/

    (void)Uart1_Init(115200); /*velocidad a 115200 bauds*/
    xdev_out(Uart1_PutChar);  /*funcion Uart1_PutChar como salida*/

    /*Se recomienda manejar siempre parametros arriba de 16 bits para un correcto funcionamiento*/
    /*cuando se usan constantes se debe forzosamente realizar un castaje, como en este ejemplo*/
    xprintf("%d\n", (_S16)1234);                    //"1234"
    xprintf("%6d,%3d%%\n", (_S16)-200, (_S16)5);    //"  -200,  5%"
    xprintf("%-6u\n", (_S16)100);                   //"100   "
    xprintf("%ld\n", 12345678L);                    //"12345678"
    xprintf("%04x\n", (_U16)0xA3);                  //"00a3"
    xprintf("%08LX\n", (_U32)0x123ABC);             //"00123ABC"
    xprintf("%016b\n", (_U16)0x550F);               //"0101010100001111"
    xprintf("%s\n", "String");                      //"String"
    xprintf("%c\n", (_U16)'a');                     //"a"

    while (1)
    {

    }
}




#pragma interrupt YourHighPriorityISRCode
void YourHighPriorityISRCode(void)
{
    /*coloca aquí el código que llevará tu interrupción en caso de usarla*/
}

#pragma interruptlow YourLowPriorityISRCode
void YourLowPriorityISRCode(void)
{
    /*coloca aquí el código que llevará tu interrupción de baja prioridad en caso de usarla*/
}


