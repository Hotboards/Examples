/*
 * Ivertimos el estado del led en RA1 cada que presionemos el boton que esta puesto en la tarjeta (RA0)
 * polearemos las entradas cada 10ms y evaluaremos si se presiono un boton con un tiempo de debounce
 * de 50ms. En esta ocasion modificaremos ese tiempo de 50ms a 2 seg cada que se preione el boton y viceversa
 * en el archivo middleware_profile.h declaramos las siguientes definiciones
 * #define GPIS_N_INPUTS        1 //usaremos un boton
 * el boton estara situado en el puerto A en el pin 0
 * #define GPIS_B0_P            GPIOS_PORTA
 * #define GPIS_B0_B            0
 */

#include <p18cxxx.h>
#include "vectors.h"
#include "types.h"
#include "gpios/gpios.h"
#include "system/system.h"
#include "swtimers/swtimers.h"
#include "gpis/gpis.h"

#pragma code
void main(void)
{
    _BOOL flag = 0;
    _U08 tiempo[2] = {5, 200}; /*teimpo de debounce 50ms y 2 seg*/

    System_EnablePLL();/*Elevamos la frecuencia de operacion a 48MHz*/
    ANCON0 = 0XFF;  /*Desativamos las salidas analogicas*/
    ANCON1 = 0XFF;  /*Desativamos las salidas analogicas*/

    Timers_Init();                      /*inicializamos el driver para genere una interrupcion cada 5ms*/
    Timers_SetTime(0, 10/timers_ms);          /*recargamos el canal 0 con un valor de 100ms*/
    Gpis_Init();/*Inicilizamos las entradas donde estan los botones*/
    Gpios_PinDirection(GPIOS_PORTA, 1, GPIOS_OUTPUT);          /*puerto RA1 como salida*/

    __ENABLE_INTERRUPTS();   /*se habilitan las interrupciones globales con prioridad*/

    while (1)
    {
        if(Timers_u16GetTime(0) == 0)/*preguntamos si la interrupcion decrmento hasta llegar a 0 el canal 0*/
        {
            Timers_SetTime(0, 10/timers_ms);/*se cumplen los 100ms asi que volvemos a recargar el mismo canal */
            Gpis_Task();            /*poleamos las entradas, en este caso solo el boton de RA0*/
        }

        if(Gpis_bGetInput(0) == _TRUE) /*preguntamos si se presiono el boton*/
        {
            flag ^= 1;                              /*invertimos la bandera*/
            Gpis_Debounce(0, tiempo[flag]);         /*invertimos el teimpo de debounce*/
            Gpios_TogglePin(GPIOS_PORTA, 1);        /*invierto el estado del led conectado al puerto A pin 1*/
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
    Timers_Isr();/*esta es la funcion de interrupcion de los timers (cada 5ms)*/
}
