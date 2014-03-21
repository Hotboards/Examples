/*
 * Ejemplo en donde se genera un pulso de 1KHz con un 80% de duty cycle en el canal PWM 1, canal A
 * el canal A se asigna al pin RP2 el cual esta en el puerto A pin 5.
 * El micro corre a 3MHz y el divisor del timer del PWM es de 16
 */

#include <p18cxxx.h>
#include "vectors.h"
#include "system/system.h"
#include "gpios/gpios.h"
#include "pwm/pwm.h"


#pragma code
void main(void)
{
    ANCON0 = 0XFF;  /*Desativamos las entradas analógicas*/
    ANCON1 = 0XFF;  /*Desativamos las entradas analógicas*/

    /*el modulo pwm1 no tiene los pines conectados asi que hay que
     asignarlos a los pines RPx que deseemos*/
    System_PeripheralPinSelect(CompareOrPWMOutputChannel1A, 2);   /*PWM1_A en el pin RP2 (A5)*/
    Gpios_PinDirection(GPIOS_PORTA, 5, GPIOS_OUTPUT);             /*pin RA5 como salida para PWM_1A*/
    
    Pwm_Init(PWM_PORT1, 1000);
    Pwm_DutyCycle(PWM_PORT1, PWM_CHANNEL_A, 80);

    while (1)
    {
       
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
