/*
 * Este programa lee el puerto D por completo y despues escribe su valor en una variable, para
 * posteriormente escribirla en el puerto B
 */

#include <p18cxxx.h>
#include "vectors.h"
#include "types.h"
#include "gpios/gpios.h"

#pragma code
void main(void)
{
    _U08 port;      /*declaramos variable para leer el puerto D*/

    ANCON0 = 0XFF;  /*Desativamos las salidas analogicas*/
    ANCON1 = 0XFF;  /*Desativamos las salidas analogicas*/

    Gpios_WriteTris(GPIOS_PORTB, 0x00);          /*puerto B como salida*/
    Gpios_WriteTris(GPIOS_PORTD, 0xff);          /*puerto D como entradas*/

    while (1)
    {
        port = Gpios_u8ReadPort(GPIOS_PORTD);        /*se lee el puerto D y se almacena en la variable "port"*/
        Gpios_WritePort(GPIOS_PORTB, port);          /*escribimos el valor de "port" en el puerto B*/
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
