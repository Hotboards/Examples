/*
 * Encendemos el led en la tarjeta cuando presionemos el boton, y apagamos el led cuando dejemos de
 * presionar el boton
 * en el archivo hardware_profile.h declaramos las siguientes definiciones
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
    System_EnablePLL();/*Elevamos la frecuencia de operacion a 48MHz*/
    ANCON0 = 0XFF;  /*Desativamos las salidas analogicas*/
    ANCON1 = 0XFF;  /*Desativamos las salidas analogicas*/

    Timers_Init();                      /*inicializamos el driver para genere una interrupcion cada 5ms*/
    Timers_SetTime(0, 10/timers_ms);          /*recargamos el canal 0 con un valor de 100ms*/
    Gpis_Init();/*Inicilizamos las entradas donde estan los botones*/
    Gpios_PinDirection(GPIOS_PORTA, 1, GPIOS_OUTPUT);          /*puerto RA1 como salida*/
    Gpios_WritePin(GPIOS_PORTA, 1, 1);          /*estado incial del led apagado*/
    
    __ENABLE_INTERRUPTS();   /*se habilitan las interrupciones globales con prioridad*/

    while (1)
    {
        if(Timers_u16GetTime(0) == 0)/*preguntamos si la interrupcion decrmento hasta llegar a 0 el canal 0*/
        {
            Timers_SetTime(0, 10/timers_ms);/*se cumplen los 10ms asi que volvemos a recargar el mismo canal */
            Gpis_Task();/*poleamos las entradas, en este caso solo el boton de RA0*/
        }

        if(Gpis_bGetStatus(0) == _TRUE) /*preguntamos si esta presionado el boton*/
        {
            Gpios_WritePin(GPIOS_PORTA, 1, 0);        /*enciendo el led en RA1*/
        }
        else                                /*si no esta presionado*/
        {
            Gpios_WritePin(GPIOS_PORTA, 1, 1);      /*apago el led en RA1*/
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
