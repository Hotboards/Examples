/*
 * Parpadeo de leds acada 500ms en todo el puerto B.
 * solo conecta 8 leds a los pines de todo el puerto B para observar el 
 * funcionamiento del codigo. Puedes usar la tarjeta pepper-pot
 * por default la velocidad de ejecucion seria de 8MHz
 */

#include <avr/io.h>
#include "types.h"
#include "gpios/gpios.h"
#include "delays/delays.h"

int main(void)
{
    _U08 port = 0;  /*declaro variable para escribir en el puerto*/

    Gpios_WriteTris(GPIOS_PORTB, 0xFF);         /*puerto B completo como salida*/

    while (1)
    {
        port ^= 0xff;                           /*invierto todo el valor del puerto*/
        Gpios_WritePort(GPIOS_PORTB, port);     /*escribo en el puerto B el valor invertido*/
        Delays_ms(500);                         /*retardo 500 ms para observar el estado de los leds*/

    }
}
