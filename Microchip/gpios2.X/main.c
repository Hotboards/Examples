/*
 * Rotacion a la izquierda de un bit en el puerto B.
 * los leds estan conectados atraves de la tarjeta Pepper-pot
 * en caso de no tener la tarjeta complementaria, solo tienes
 * que agregar los leds
 * Por default la velocidad de ejecucion es de 12MHz
*/

#include <xc.h>
#include "fuses.h"
#include "types.h"
#include "gpios/gpios.h"

int main(void)
{
    _U16 i;
    _U08 port;      /*declaro variable de 8 bits*/

    ANCON0 = 0XFF;  /*Desativamos las salidas analogicas*/
    ANCON1 = 0XFF;  /*Desativamos las salidas analogicas*/

    Gpios_WriteTris(GPIOS_PORTB, 0x00);                 /*puerto B completo como salida*/

    port = 1;       /*inicializo en 1 la variable port, para encender por primera vez los leds*/

    while (1)
    {
        Gpios_WritePort(GPIOS_PORTB, port);     /*escribo en el puerto B el valor rotado*/
        for(i=0;i<50000;i++);                   /*retardo para observar el estado de los leds*/
        port = Gpios_u8ReadPort(GPIOS_PORTB);   /*leo el estado del puerto B*/
        LEFT_8SHIFT(port, 1);                   /*roto a la izquierda una posicion el valor de port*/
        if(port == 0)                           /*si el valor de port llego a cero*/
        {                                       /*se termino de rotar el puerto entero*/
            port = 1;                           /*vuelvo a comenzar la rotacion*/
        }
    }
}
