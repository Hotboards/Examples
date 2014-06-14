/*
 * parpadeo de un led (RA1) a 100ms.
 * solo carga el programa y listo el led ya esta en tu tarjeta, conectado al pin RA1
 * por default la velocidad de ejecucion seria de 8MHz
 */

#include <avr/io.h>
#include "types.h"
#include "gpios/gpios.h"
#include "delays/delays.h"


int main(void)
{
    Gpios_PinDirection(GPIOS_PORTA, 1, GPIOS_OUTPUT);          /*puerto RA1 como salida*/

    while (1)
    {
        Delays_ms(100);                         /*retardo 100 ms para observar el estado del led*/
        Gpios_TogglePin(GPIOS_PORTA, 1);        /*invierto el estado del led conectado al puerto A pin 1*/
    }
}
