/*
 * Parpadeo de tres leds conectados al puerto B en los pines 5,6 y 7
 * El programa parpadea cada led a diferentes tiempos, 5=500ms, 6=200ms y 7=100ms
 * por default la velocidad de ejecucion seria de 8MHz
 */

#include <avr/io.h>
#include "types.h"
#include "gpios/gpios.h"
#include "system/system.h"
#include "swtimers/swtimers.h"


int main(void)
{
    Timers_Init();                      /*inicializamos el driver para genere una interrupcion cada 5ms*/
    Timers_SetTime(0, 100/timers_ms);          /*recargamos el canal 0 con un valor de 100ms*/
    Timers_SetTime(1, 200/timers_ms);          /*recargamos el canal 1 con un valor de 200ms*/
    Timers_SetTime(2, 500/timers_ms);          /*recargamos el canal 2 con un valor de 500ms*/
    
    Gpios_PinDirection(GPIOS_PORTB, 7, GPIOS_OUTPUT);          /*puerto RB7 como salida*/
    Gpios_PinDirection(GPIOS_PORTB, 6, GPIOS_OUTPUT);          /*puerto RB6 como salida*/
    Gpios_PinDirection(GPIOS_PORTB, 5, GPIOS_OUTPUT);          /*puerto RB5 como salida*/

    __ENABLE_INTERRUPTS();   /*se habilitan las interrupciones globales con prioridad*/

    while (1)
    {
        /*parpadeamos el primer led (Puerto B, Pin 7)*/
        if(Timers_u16GetTime(0) == 0)/*preguntamos si la interrupcion decrmento hasta llegar a 0 el canal 0*/
        {
            Timers_SetTime(0, 100/timers_ms);/*se cumplen los 100ms asi que volvemos a recargar el mismo canal */
            Gpios_TogglePin(GPIOS_PORTB, 7);        /*invierto el estado del led conectado al puerto B pin 7*/
        }

        /*parpadeamos el segundo led (Puerto B, Pin 6)*/
        if(Timers_u16GetTime(1) == 0)/*preguntamos si la interrupcion decrmento hasta llegar a 0 el canal 1*/
        {
            Timers_SetTime(1, 200/timers_ms);/*se cumplen los 200ms asi que volvemos a recargar el mismo canal */
            Gpios_TogglePin(GPIOS_PORTB, 6);        /*invierto el estado del led conectado al puerto B pin 6*/
        }

        /*parpadeamos el primer led (Puerto B, Pin 5)*/
        if(Timers_u16GetTime(2) == 0)/*preguntamos si la interrupcion decrmento hasta llegar a 0 el canal 2*/
        {
            Timers_SetTime(2, 500/timers_ms);/*se cumplen los 500ms asi que volvemos a recargar el mismo canal */
            Gpios_TogglePin(GPIOS_PORTB, 5);        /*invierto el estado del led conectado al puerto B pin 5*/
        }
    }
}
