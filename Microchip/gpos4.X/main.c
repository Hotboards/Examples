/*
 * Ivertimos el estado de 3 leds conectados al puerto B (RB0, RB2 y RB4)
 * en el archivo hardware_profile.h declaramos las siguientes definiciones
 * #define GPOS_N_PINS          3 //usaremos 3 salidas
 * el led estara situado en el puerto B en el pin 0, 2 y 4
 * #define GPOS_P0_P            GPIOS_PORTB
 * #define GPOS_P0_B            0
 
 * #define GPOS_P1_P            GPIOS_PORTB
 * #define GPOS_P1_B            2

 * #define GPOS_P2_P            GPIOS_PORTB
 * #define GPOS_P2_B            4
 * Recuerda revisar el archivo bsp_profile.h donde se define escribe
 * la velocidad de reloj a 48MHz
 */

#include <xc.h>
#include "fuses.h"
#include "types.h"
#include "system/system.h"
#include "swtimers/swtimers.h"
#include "gpos/gpos.h"

int main(void)
{
    System_EnablePLL();                 /*Elevamos la frecuencia de operacion a 48MHz*/
    ANCON0 = 0XFF;                      /*Desativamos las salidas analogicas*/
    ANCON1 = 0XFF;                      /*Desativamos las salidas analogicas*/

    Timers_Init();                      /*inicializamos el driver para genere una interrupcion cada 5ms*/
    Timers_SetTime(0, 10/timers_ms);    /*recargamos el canal 0 con un valor de 10ms*/
    Gpos_Init();                        /*Inicilizamos las salidas donde estan los leds*/
    Gpos_SetMode(0, GPOS_OSC_MODE, 20); /*oscilar salida 0 cada 200ms*/
    Gpos_SetMode(1, GPOS_OSC_MODE, 30); /*oscilar salida 1 cada 300ms*/
    Gpos_SetMode(2, GPOS_OSC_MODE, 50); /*oscilar salida 2 cada 500ms*/

    __ENABLE_INTERRUPTS();   /*se habilitan las interrupciones globales con prioridad*/

    while (1)
    {
        if(Timers_u16GetTime(0) == 0)/*preguntamos si la interrupcion decrmento hasta llegar a 0 el canal 0*/
        {
            Timers_SetTime(0, 10/timers_ms);/*se cumplen los 10ms asi que volvemos a recargar el mismo canal */
            Gpos_Task();                    /*actualizamos las salidas, en este caso RA1*/
        }
    }
}


void interrupt low_priority low_isr(void)
{
    Timers_Isr();   
}
