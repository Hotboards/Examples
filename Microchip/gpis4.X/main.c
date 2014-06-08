/*
 * Ivertimos el estado de tres leds coenctados a RB0, RB1 y RB2 cada que presionemos un boton correspondiente
 * los botones estan conectado a RB5, RB6 y RB7 mediante una resistencia pull-up,
 * polearemos las entradas cada 10ms y evaluaremos si se presiono un boton con un tiempo de debounce
 * de 50ms.
 * en el archivo middleware_profile.h declaramos las siguientes definiciones
 * #define GPIS_N_INPUTS        3 //usaremos tres botones
 * el boton estara situado en el puerto A en el pin 0
 * #define GPIS_B0_P            GPIOS_PORTB
 * #define GPIS_B0_B            5
 *
 * #define GPIS_B1_P            GPIOS_PORTB
 * #define GPIS_B1_B            6
 *
 * #define GPIS_B2_P            GPIOS_PORTB
 * #define GPIS_B2_B            7
 */

#include <xc.h>
#include "fuses.h"
#include "types.h"
#include "gpios/gpios.h"
#include "system/system.h"
#include "swtimers/swtimers.h"
#include "gpis/gpis.h"

int main(void)
{
    System_EnablePLL(); /*Elevamos la frecuencia de operacion a 48MHz*/
    ANCON0 = 0XFF;      /*Desativamos las salidas analogicas*/
    ANCON1 = 0XFF;      /*Desativamos las salidas analogicas*/

    Timers_Init();                      /*inicializamos el driver para genere una interrupcion cada 5ms*/
    Timers_SetTime(0, 10/timers_ms);    /*recargamos el canal 0 con un valor de 100ms*/
    Gpis_Init();                        /*Inicilizamos las entradas donde estan los botones*/
    Gpios_PinDirection(GPIOS_PORTB, 0, GPIOS_OUTPUT);          /*puerto RB0 como salida*/
    Gpios_PinDirection(GPIOS_PORTB, 1, GPIOS_OUTPUT);          /*puerto RB1 como salida*/
    Gpios_PinDirection(GPIOS_PORTB, 2, GPIOS_OUTPUT);          /*puerto RB2 como salida*/

    __ENABLE_INTERRUPTS();   /*se habilitan las interrupciones globales con prioridad*/

    while (1)
    {
        if(Timers_u16GetTime(0) == 0)/*preguntamos si la interrupcion decrmento hasta llegar a 0 el canal 0*/
        {
            Timers_SetTime(0, 10/timers_ms);/*se cumplen los 100ms asi que volvemos a recargar el mismo canal */
            Gpis_Task();                    /*poleamos las 3 entradas RB5, RB6, RB7*/
        }

        if(Gpis_bGetInput(0) == _TRUE)          /*preguntamos si se presiono el boton 0*/
        {
            Gpios_TogglePin(GPIOS_PORTB, 0);    /*invierto el estado del led conectado al puerto B pin 0*/
        }

        if(Gpis_bGetInput(1) == _TRUE)          /*preguntamos si se presiono el boton 1*/
        {
            Gpios_TogglePin(GPIOS_PORTB, 1);    /*invierto el estado del led conectado al puerto B pin 1*/
        }

        if(Gpis_bGetInput(2) == _TRUE)          /*preguntamos si se presiono el boton 2*/
        {
            Gpios_TogglePin(GPIOS_PORTB, 2);    /*invierto el estado del led conectado al puerto B pin 2*/
        }
    }
}


void interrupt low_priority low_isr(void)
{
    Timers_Isr();
}
