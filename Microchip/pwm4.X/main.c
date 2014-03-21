/*
 * Ejemplo en donde se genera un pulso de 750Hz con un duty cycle variable de 1% a 55% en el PWM 1,
 * canal B. ele ejemplo es un simple dimmer generado cada 3 segundos
 * el canal B se asigna al pin RP19 el cual esta en el puerto D pin 2.
 * El micro corre a 3MHz y el divisor del timer del PWM es de 16
 */

#include <p18cxxx.h>
#include "vectors.h"
#include "system/system.h"
#include "gpios/gpios.h"
#include "pwm/pwm.h"
#include "delays/delays.h"

#pragma code
void main(void)
{
    _U08 i;
    _U08 u8Array[] = {99,95,90,85,80,75,70,65,60,55,50,45};

    ANCON0 = 0XFF;  /*Desativamos las entradas analógicas*/
    ANCON1 = 0XFF;  /*Desativamos las entradas analógicas*/

    /*el modulo pwm1 no tiene los pines conectados asi que hay que
     asignarlos a los pines RPx que deseemos*/
    System_PeripheralPinSelect(EnhancedPWMOutputChannel1B, 19);   /*PWM1_B en el pin RP19 (D2)*/
    Gpios_PinDirection(GPIOS_PORTD, 2, GPIOS_OUTPUT);             /*pin RD2 como salida para PWM_1B*/

    Pwm_Init(PWM_PORT1, 750);

    while (1)
    {
        for(i=0;i<sizeof(u8Array);i++)
        {
            Pwm_DutyCycle(PWM_PORT1, PWM_CHANNEL_B, u8Array[i]);
            Delays_ms(300);
        }

        i--;

        for(;i<sizeof(u8Array);i--)
        {
            Pwm_DutyCycle(PWM_PORT1, PWM_CHANNEL_B, u8Array[i]);
            Delays_ms(300);
        }
        Delays_ms(3000);
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
    /*coloca aquí el código que llevará tu interrupción de baja prioridad en caso de usarla*/
}
