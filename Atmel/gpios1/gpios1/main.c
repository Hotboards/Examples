/*
 * parpadeo de un led (RA1) cada 50000 cuentas.
 * solo carga el programa y listo el led ya esta en tu tarjeta, conectado al pin RA1
 * Por default la velocidad de ejecucion se considera a 8MHz
 * Solo recuerde colocar el fuse CLKDIV8 desprogramado
 */

#include <avr/io.h>
#include "types.h"
#include "gpios/gpios.h"

int main(void)
{
    _U16 i;         /*declaramos variable para contar*/

    Gpios_PinDirection(GPIOS_PORTA, 1, GPIOS_OUTPUT);          /*puerto RA1 como salida*/

    while (1)
    {
        Gpios_TogglePin(GPIOS_PORTA, 1);    /*invierto el estado del led conectado al puerto A pin 1*/
        for(i=0;i<50000;i++);               /*ciclamos el procesador para observar el estado del led*/
    }
}
