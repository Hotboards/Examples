/*
 * Ejemplo en donde se genera un pulso de 2KHz con un 30% de duty cycle los cnales A, B y C del PWM 1
 * el canal A se asigna al pin RP2 el cual esta en el puerto A pin 5.
 * el canal B se asigna al pin RP19 el cual esta en el puerto D pin 2.
 * el canal C se asigna al pin RP20 el cual esta en el puerto D pin 3.
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
    System_PeripheralPinSelect(EnhancedPWMOutputChannel1B, 19);  /*PWM1_B en el pin RP19 (D2)*/
    System_PeripheralPinSelect(EnhancedPWMOutputChannel1C, 20); /*PWM1_C en el pin RP20 (D3)*/

    Gpios_PinDirection(GPIOS_PORTA, 5, GPIOS_OUTPUT);  /*pin RA5 como salida para PWM_1A*/
    Gpios_PinDirection(GPIOS_PORTD, 2, GPIOS_OUTPUT);  /*pin RD2 como salida para PWM_1B*/
    Gpios_PinDirection(GPIOS_PORTD, 3, GPIOS_OUTPUT);  /*pin RD3 como salida para PWM_1C*/

    Pwm_Init(PWM_PORT1, 2000);
    Pwm_DutyCycle(PWM_PORT1, PWM_CHANNEL_A|PWM_CHANNEL_B|PWM_CHANNEL_C, 30);

    while (1)
    {
        /*Escribe aqui tu aplicacion*/
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
