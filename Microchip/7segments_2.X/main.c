/*
 * Se despliega la cuenta de una variable de 8 bits de 0 a 255 en tres displays, cada 200ms
 * se toma el puerto B como bus de datos y los pines display1 = D7, display2 = D6,
 * display4 = D4 para los comunes. los displays son positivo comun. Revisa el archivo hardware_profile.h
 * El micro tiene una velocidad de 12MHz, cristal externo
 */

#include <p18cxxx.h>
#include "vectors.h"
#include "gpios/gpios.h"
#include "swtimers/swtimers.h"
#include "system/system.h"
#include "7segments/_7segments.h"

void task(void);

#pragma code
void main(void)
{
    _U08 u8Counter = 0;

    ANCON0 = 0xff;
    ANCON1 = 0xff;

    Timers_Init();                      /*inicializamos el driver para genere una interrupcion cada 5ms*/
    _7segments_Init();                  /*configuramos los pines como salidas*/
  
    __ENABLE_INTERRUPTS();   /*se habilitan las interrupciones globales con prioridad*/

    while (1)
    {
        if(Timers_u16GetTime(0) == 0)/*preguntamos si la interrupcion decrmento hasta llegar a 0 el canal 0*/
        {
            Timers_SetTime(0, 5/timers_ms);/*se cumplen los 5ms asi que volvemos a recargar el mismo canal */
            _7segments_Task();              /*actualiza el valor en el display y multiplexa al siguiente display*/
        }
        if(Timers_u16GetTime(1) == 0)/*preguntamos si la interrupcion decrmento hasta llegar a 0 el canal 1*/
        {
            Timers_SetTime(1, 200/timers_ms);/*se cumplen los 200ms asi que volvemos a recargar el mismo canal */
            _7segments_SetNumber(u8Counter); /*actualizamos el display*/
            u8Counter++;/*incrementamos al cuenta*/
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
