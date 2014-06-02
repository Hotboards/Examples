/*
 * Se despliega el voltaje leido en el canal 3 del adc en tres displays, cada 100ms
 * se toma el puerto B como bus de datos y los pines display1 = D7, display2 = D6,
 * display4 = D4 para los comunes. los displays son positivo comun. Revisa el archivo hardware_profile.h
 * El micro tiene una velocidad de 12MHz, cristal externo
 */

#include <xc.h>
#include "fuses.h"
#include "gpios/gpios.h"
#include "swtimers/swtimers.h"
#include "system/system.h"
#include "adc/adc.h"
#include "7segments/_7segments.h"


int main(void)
{
    _U08 u8Adc = 0;
    _U08 u8Val;
    _U16 u16Volts;

    ANCON0 = 0xff;
    ANCON1 = 0xff;

    Adc_Init(ADC_8BITS);
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
            Timers_SetTime(1, 100/timers_ms);       /*se cumplen los 200ms asi que volvemos a recargar el mismo canal */
            u8Adc = Adc_u16Read( 3 );               /*se lee el canal del adc*/
            u16Volts = (_U16)u8Adc * (_U16)13;      /*se trasnforma la lectura en milivolts*/
            _7segments_SetNumber(u16Volts/10);      /*actualizamos el display con el valor en volts*/
            u8Val = _7segments_u8GetDisplay(2);     /*se lee el tercer display*/
            _7segments_SetDisplay(2, u8Val|0x80);   /*se agrega el punto decimal*/
        }
    }
}


void interrupt low_priority low_isr(void)
{
    Timers_Isr();
}
