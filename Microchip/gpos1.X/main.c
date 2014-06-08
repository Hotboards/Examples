/*
 * Ivertimos el estado del led en RA1 cada 200ms usando una salida oscilante
 * en el archivo hardware_profile.h declaramos las siguientes definiciones
 * #define GPOS_N_PINS          1 //usaremos un boton
 * el led estara situado en el puerto A en el pin 0
 * #define GPOS_P0_P            GPIOS_PORTA
 * #define GPOS_P0_B            1
 * Recuerda revisar el archivo hardware_profile.h donde se define escribe
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
