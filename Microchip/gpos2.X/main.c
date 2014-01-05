/*
 * encenderemos led en RA1 por 300ms cada que presionemos el boton que esta puesto 
 * en la tarjeta (RA0) polearemos las entradas cada 10ms y evaluaremos si se
 * presiono un boton con un tiempo de debounce de 50ms.
 * en el archivo hardware_profile.h declaramos las siguientes definiciones
 * #define GPIS_N_INPUTS        1 //usaremos un boton
 * el boton estara situado en el puerto A en el pin 0
 * #define GPIS_B0_P            GPIOS_PORTA
 * #define GPIS_B0_B            0
 * definimos salidas
 * #define GPOS_N_PINS          1 //usaremos un boton
 * le led estara situado en el puerto A en el pin 0
 * #define GPOS_P0_P            GPIOS_PORTA
 * #define GPOS_P0_B            1
 */

#include <p18cxxx.h>
#include "vectors.h"
#include "types.h"
#include "system/system.h"
#include "swtimers/swtimers.h"
#include "gpis/gpis.h"
#include "gpos/gpos.h"

#pragma code
void main(void)
{
    System_EnablePLL();                 /*Elevamos la frecuencia de operacion a 48MHz*/
    ANCON0 = 0XFF;                      /*Desativamos las salidas analogicas*/
    ANCON1 = 0XFF;                      /*Desativamos las salidas analogicas*/

    Timers_Init();                      /*inicializamos el driver para genere una interrupcion cada 5ms*/
    Timers_SetTime(0, 10/timers_ms);    /*recargamos el canal 0 con un valor de 10ms*/
    Gpis_Init();                        /*Inicilizamos las entradas donde estan los botones*/
    Gpos_Init();                        /*Inicilizamos las salidas donde estan los leds*/
    Gpos_SetMode(0, GPOS_HIGH_MODE, 0); /*apagamos el led colocando un uno a la salida*/

    __ENABLE_INTERRUPTS();              /*se habilitan las interrupciones globales con prioridad*/

    while (1)
    {
        if(Timers_u16GetTime(0) == 0)   /*preguntamos si la interrupcion decrmento hasta llegar a 0 el canal 0*/
        {
            Timers_SetTime(0, 10/timers_ms);/*se cumplen los 100ms asi que volvemos a recargar el mismo canal */
            Gpis_Task();                    /*poleamos las entradas, en este caso solo el boton de RA0*/
            Gpos_Task();                    /*actualizamos las salidas, en este caso RA1*/
        }

        if(Gpis_bGetInput(0) == _TRUE)          /*preguntamos si se presiono el boton*/
        {
            Gpos_SetMode(0, GPOS_DELAYHIGH_MODE, 30); /*enciendo el led por 300ms*/
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
    Timers_Isr();
}
