/*
 * Se depliegan 4 numeros en los diplays, display1 = 0, display2 = 1, display3 = 2, display4 = 3
 * se toma el puerto B como bus de datos y los pines display1 = D7, display2 = D6, display3 = D5,
 * display4 = D4 para los comunes. los displays son positivo comun. Revisa el archivo hardware_profile.h
 * El micro tiene una velocidad de 12MHz, cristal externo
 */

#include <xc.h>
#include "fuses.h"
#include "gpios/gpios.h"
#include "swtimers/swtimers.h"
#include "system/system.h"
#include "7segments/_7segments.h"

int main(void)
{
    ANCON0 = 0xff;
    ANCON1 = 0xff;

    Timers_Init();                      /*inicializamos el driver para genere una interrupcion cada 5ms*/
    _7segments_Init();                  /*configuramos los pines como salidas*/
    _7segments_SetDisplay(0, _0);       /*depliega el cero en el display*/
    _7segments_SetDisplay(1, _1);       /*depliega el uno en el display*/
    _7segments_SetDisplay(2, _2);       /*depliega el dos en el display*/
    _7segments_SetDisplay(3, _3);       /*depliega el tres en el display*/
    __ENABLE_INTERRUPTS();   /*se habilitan las interrupciones globales con prioridad*/

    while (1)
    {
        if(Timers_u16GetTime(0) == 0)/*preguntamos si la interrupcion decrmento hasta llegar a 0 el canal 0*/
        {
            Timers_SetTime(0, 5/timers_ms);/*se cumplen los 5ms asi que volvemos a recargar el mismo canal */
            _7segments_Task();              /*actualiza el valor en el display y multiplexa al siguiente display*/
        }
    }
}


void interrupt low_priority low_isr(void)
{
    Timers_Isr();
}
