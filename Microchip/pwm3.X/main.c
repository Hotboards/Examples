/*
 * Ejemplo en donde se genera dos pulsos de 1KHz con un 40% de duty cycle en el PWM 1, canal A
 * y 70% de duty cycle en el PWM 2 canal B
 * el canal A del PWM1 se asigna al pin RP2 el cual esta en el puerto A pin 5.
 * el canal A del PWM2 se asigna al pin RP19 el cual esta en el puerto D pin 2.
 * El micro corre a 3MHz y el divisor del timer del PWM es de 16
 */

#include <xc.h>
#include "fuses.h"
#include "system/system.h"
#include "gpios/gpios.h"
#include "pwm/pwm.h"

int main(void)
{
    ANCON0 = 0XFF;  /*Desativamos las entradas analógicas*/
    ANCON1 = 0XFF;  /*Desativamos las entradas analógicas*/

    /*el modulo pwm1 no tiene los pines conectados asi que hay que
     asignarlos a los pines RPx que deseemos*/
    System_PeripheralPinSelect(CompareOrPWMOutputChannel1A, 2);   /*PWM1_A en el pin RP2 (A5)*/
    System_PeripheralPinSelect(CompareOrPWMOutputChannel2A, 19);  /*PWM2_A en el pin RP19 (D2)*/

    Gpios_PinDirection(GPIOS_PORTA, 5, GPIOS_OUTPUT);  /*pin RA5 como salida para PWM_1A*/
    Gpios_PinDirection(GPIOS_PORTD, 2, GPIOS_OUTPUT);  /*pin RD2 como salida para PWM_2A*/

    Pwm_Init(PWM_PORT1, 1000);
    Pwm_Init(PWM_PORT2, 1000);

    Pwm_DutyCycle(PWM_PORT1, PWM_CHANNEL_A, 40);
    Pwm_DutyCycle(PWM_PORT2, PWM_CHANNEL_A, 70);

    while (1)
    {
        /*Escribe aqui tu aplicacion*/
    }
}

