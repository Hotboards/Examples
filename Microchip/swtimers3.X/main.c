/*
 * Programa que parpadea un led cada 100ms y al mismo timepo rota un led en el puerto B cada 500ms
 * Este es un sencillo ejemplo de como el uC puede ejecutar una aplicacion consistente en 2 procesos
 * sin que una afecte a al otra.
 * la aplicacion puede correr sin problemas usando la pepper-pot
 * por default la velocidad de ejecucion seria de 12MHz
 */

#include <p18cxxx.h>
#include "vectors.h"
#include "types.h"
#include "gpios/gpios.h"
#include "system/system.h"
#include "swtimers/swtimers.h"


#pragma code
void main(void)
{
    _U08 port = 1;

    ANCON0 = 0XFF;  /*Desativamos las salidas analogicas*/
    ANCON1 = 0XFF;  /*Desativamos las salidas analogicas*/

    Timers_Init();                      /*inicializamos el driver para genere una interrupcion cada 5ms*/
    Timers_SetTime(0, 100/timers_ms);          /*recargamos el canal 0 con un valor de 100ms*/
    Timers_SetTime(1, 500/timers_ms);          /*recargamos el canal 1 con un valor de 200ms*/
    
    Gpios_PinDirection(GPIOS_PORTA, 1, GPIOS_OUTPUT);          /*puerto RA1 como salida*/
    Gpios_WriteTris(GPIOS_PORTB, 0x00);                     /*puerto B como salida*/


    __ENABLE_INTERRUPTS();   /*se habilitan las interrupciones globales con prioridad*/

    while (1)
    {
        /*parpadeamos el primer led (Puerto A, Pin 1)*/
        if(Timers_u16GetTime(0) == 0)/*preguntamos si la interrupcion decrmento hasta llegar a 0 el canal 0*/
        {
            Timers_SetTime(0, 100/timers_ms);/*se cumplen los 100ms asi que volvemos a recargar el mismo canal */
            Gpios_TogglePin(GPIOS_PORTA, 1);        /*invierto el estado del led conectado al puerto A pin 1*/
        }

        /*rotamos un led encendido en el puerto B cada 500ms*/
        if(Timers_u16GetTime(1) == 0)/*preguntamos si la interrupcion decrmento hasta llegar a 0 el canal 1*/
        {
            Timers_SetTime(1, 500/timers_ms);/*se cumplen los 500ms asi que volvemos a recargar el mismo canal */
            Gpios_WritePort(GPIOS_PORTB, port);     /*escribo en el puerto B el valor rotado*/
            port = Gpios_u8ReadPort(GPIOS_PORTB);   /*leo el estado del puerto B*/
            LEFT_8SHIFT(port, 1);                   /*roto a la izquierda una posicion el valor de port*/
            if(port == 0)                           /*si el valor de port llego a cero*/
            {                                       /*se termino de rotar el puerto entero*/
                port = 1;                           /*vuelvo a comenzar la rotacion*/
            }
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
    Timers_Isr();/*Es neceario mandar llamar esta funcion en este vector de interrupcion*/
}
