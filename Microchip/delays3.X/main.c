/*
 * Rotacion a la izquierda de un bit en el puerto B.
 * solo conecta 8 leds a los pines de todo el puerto B para observar el 
 * funcionamiento del codigo. En caso de tener la tarjeta pepper-pot no tendras
 * que conectar nada, solo observa los leds
 * por default la velocidad de ejecucion seria de 12MHz
*/

#include <p18cxxx.h>
#include "vectors.h"
#include "types.h"
#include "gpios/gpios.h"
#include "delays/delays.h"

#pragma code
void main(void)
{
    _U08 port;      /*declaro variable de 8 bits*/

    ANCON0 = 0XFF;  /*Desativamos las salidas analogicas*/
    ANCON1 = 0XFF;  /*Desativamos las salidas analogicas*/

    Gpios_WriteTris(GPIOS_PORTB, 0x00);                 /*puerto B completo como salida*/
    Gpios_WritePort(GPIOS_PORTB, 0xff);                 /*enciendo todos los leds*/
    Delays_ms(2000);                                    /*retardo 2 segundos*/

    port = 1;       /*inicializo en 1 la variable port, para encender por primera vez los leds*/

    while (1)
    {
        Gpios_WritePort(GPIOS_PORTB, port);     /*escribo en el puerto B el valor rotado*/
        Delays_ms(200);                         /*retardo 200 ms para observar el estado de los leds*/
        port = Gpios_u8ReadPort(GPIOS_PORTB);   /*leo el estado del puerto B*/
        LEFT_8SHIFT(port, 1);                   /*roto a la izquierda una posicion el valor de port*/
        if(port == 0)                           /*si el valor de port llego a cero*/
        {                                       /*se termino de rotar el puerto entero*/
            port = 1;                           /*vuelvo a comenzar la rotacion*/
        }
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
