/*
 * Se muestrean tres canales del adc (2,3 y 4) se promedian las mediciones y el resultado se despliega
 * en el puerto B utilizando leds, la resolucion empleada en el ejemplo es de 8 bits
 * por default la velocidad de ejecucion seria de 12MHz
 */

#include <p18cxxx.h>
#include "vectors.h"
#include "types.h"
#include "gpios/gpios.h"
#include "adc/adc.h"
#include "system/system.h"
#include "swtimers/swtimers.h"

#pragma code
void main(void)
{
    _U16 adc; /*variable que almacenara el resultado del adc (canal 3)*/

    ANCON0 = 0XFF;  /*Desativamos las salidas analogicas*/
    ANCON1 = 0XFF;  /*Desativamos las salidas analogicas*/

    Timers_Init();                      /*se incilizan los timers por softwar*/
    Timers_SetTime(0, 100/timers_ms);   /*se prepara el canal cero con 100ms*/
    Adc_Init(ADC_8BITS);                /*se inciliza el adc con resolucion de 10bits*/
    Gpios_WriteTris(GPIOS_PORTB, 0x00); /*todo el puerto B como salida*/

    __ENABLE_INTERRUPTS();
    while (1)
    {
        if(Timers_u16GetTime(0) == 0)                /*cuando se agote el tiempo en el canal cero*/
        {
            Timers_SetTime(0, 100/timers_ms);        /*se recarga el mismo canal con el mismo tiempo*/
            adc  = Adc_u16Read(2);                   /*Se lee la lectura del canal 2 en el adc*/
            adc += Adc_u16Read(3);                   /*Se lee la lectura del canal 3 en el adc*/
            adc += Adc_u16Read(4);                   /*Se lee la lectura del canal 4 en el adc*/
            adc /= 3;                                /*se promedian las tres mediciones*/
            Gpios_WritePort(GPIOS_PORTB, (_U08)adc); /*se escribe a la salida la lectura en binario*/
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
    /*coloca aquí el código que llevará tu interrupción de baja prioridad en caso de usarla*/
}


