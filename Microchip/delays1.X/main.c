/*
 * parpadeo de un led (RA1) a 100ms.
 * solo carga el programa y listo el led ya esta en tu tarjeta, conectado al pin RA1
 * por default la velocidad de ejecucion seria de 12MHz
 */

#include <xc.h>
#include "fuses.h"
#include "types.h"
#include "gpios/gpios.h"
#include "delays/delays.h"


int main(void)
{
    ANCON0 = 0XFF;  /*Desactivamos las entradas analogicas*/
    ANCON1 = 0XFF;  /*Desactivamos las entradas analogicas*/
    Gpios_PinDirection(GPIOS_PORTA, 1, GPIOS_OUTPUT);          /*puerto RA1 como salida*/

    while (1)
    {
        Delays_us(40);                         /*retardo 100 ms para observar el estado del led*/
        Gpios_TogglePin(GPIOS_PORTA, 1);        /*invierto el estado del led conectado al puerto A pin 1*/
    }
}
