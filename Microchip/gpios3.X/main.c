/*
 * El ejemplo requiere la tarjeta pepper conectada a la pepper-pot, tan solo
 * manipula la posicion de los microswitch para alterar el valor de los leds
 * Este programa escribe la parte alta del puerto D en una variable,
 * para depues aplicar un corrimiento de 4 posiciones y
 * posteriormente escribirl el valor en el puerto B
 */

#include <xc.h>
#include "fuses.h"
#include "types.h"
#include "gpios/gpios.h"

int main(void)
{
    _U08 port;      /*declaramos variable para leer el puerto D*/

    ANCON0 = 0XFF;  /*Desativamos las salidas analogicas*/
    ANCON1 = 0XFF;  /*Desativamos las salidas analogicas*/

    Gpios_WriteTris(GPIOS_PORTB, 0x00);          /*puerto B como salida*/
    Gpios_WriteTris(GPIOS_PORTD, 0xff);          /*puerto D como entradas*/

    while (1)
    {
        port = Gpios_u8ReadPort(GPIOS_PORTD);        /*se lee el puerto D y se almacena en la variable "port"*/
        RIGHT_8SHIFT(port, 4);
        Gpios_WritePort(GPIOS_PORTB, port);          /*escribimos el valor de "port" en el puerto B*/
    }
}
