/*
 * Programa que parpadea un led cada 200ms pero en esta ocasion elevamos la frecuencia de operacion
 * a 48MHz, al haser esto debemos indicarle al bsp que la nueva frecuancia es 20MHz, solo tenemos
 * que definir la siguiente linea de codigo en el archivo "hardware_profile.h"
 * #define BSP_CLOCK        20000000
 * Ademas modificamos el tiempo de base de la interrupcion de los timers para cambiarla de 5ms a 10ms
 * en el mismo archivo "bsp_profile.h"
 * #define TIMERS_BASE_TIME        10
 */

#include <avr/io.h>
#include "types.h"
#include "gpios/gpios.h"
#include "system/system.h"
#include "swtimers/swtimers.h"

int main(void)
{
    Timers_Init();                      /*inicializamos el driver para genere una interrupcion cada 10ms*/
    Timers_SetTime(0, 200/timers_ms);   /*recargamos el canal 0 con un valor de 100ms*/
    
    Gpios_PinDirection(GPIOS_PORTA, 1, GPIOS_OUTPUT);          /*puerto RA1 como salida*/
    
    __ENABLE_INTERRUPTS();   /*se habilitan las interrupciones globales con prioridad*/

    while (1)
    {
        /*parpadeamos el primer led (Puerto A, Pin 1)*/
        if(Timers_u16GetTime(0) == 0)/*preguntamos si la interrupcion decrmento hasta llegar a 0 el canal 0*/
        {
            Timers_SetTime(0, 200/timers_ms);/*se cumplen los 200ms asi que volvemos a recargar el mismo canal */
            Gpios_TogglePin(GPIOS_PORTA, 1);        /*invierto el estado del led conectado al puerto A pin 1*/
        }
    }
}
