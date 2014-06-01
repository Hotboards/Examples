/*
 * Simple programa que espera por recivir una cadena de caracteres, cuando recive
 * la cadena led1 invierte el eatdo del led conectado a B1 y cuando recive led3
 * invierte le estado del led B3
 * para correr este demo debes habrir en tu PC una terminal por serial y setear 
 * su velocidad a 9600 no flow control y transferencia de 8 bits sin paridad
 * en hardware_profile se indica que se usara la Rx del puerto serial
 * #define UART_ENABLE_RX1      1
 * recuerda que dentro de tu aplicacion debes definir lo que hara la funcion
 * void Uart1_CallbackRx(_U08 u8Data)
 */

#include <xc.h>
#include "fuses.h"
#include "types.h"
#include "uart/uart.h"
#include "system/system.h"
#include "gpios/gpios.h"
#include <string.h>

static _U08 gu8Buffer[100];
static _BOOL gbFlag = _FALSE;

int main(void)
{
    ANCON0 = 0XFF;  /*Desactivamos las entradas analogicas*/
    ANCON1 = 0XFF;  /*Desactivamos las entradas analogicas*/

    Gpios_PinDirection(GPIOS_PORTC, 6, GPIOS_OUTPUT); /*pin de tx como salida*/
    Gpios_PinDirection(GPIOS_PORTC, 7, GPIOS_INPUT); /*pin de rx como entrada*/
    Gpios_PinDirection(GPIOS_PORTB, 1, GPIOS_OUTPUT); /*pin de rx como entrada*/
    Gpios_PinDirection(GPIOS_PORTB, 3, GPIOS_OUTPUT); /*pin de rx como entrada*/
    (void)Uart_Init(UART_PORT1, 9600);   /*se iniclaiza el puerto serial a 9600 baudios*/
    __ENABLE_INTERRUPTS();          /*habilitamos interrupciones globales*/

    while (1)
    {
        if(gbFlag == _TRUE) /*llego un caracter por teclado*/
        {
            gbFlag = _FALSE; /*limpiamos la bandera*/
            if(strcmp(&gu8Buffer[0], "led1\r") == 0)
            {
                Gpios_TogglePin(GPIOS_PORTB, 1);
            }
            else if(strcmp(&gu8Buffer[0], "led3\r") == 0)
            {
                Gpios_TogglePin(GPIOS_PORTB, 3);
            }
        }
    }
}


void interrupt low_priority low_isr(void)
{
    Uart1_RxIsr();/*en esta funcion se capturan los datos de llegada*/
    /*coloca aquí el código que llevará tu interrupción de baja prioridad en caso de usarla*/
}

/*esta funcion es llamda dentro de la funcion Uart_RxIsr() y se encarga de pasar a la aplicacion
 los datos llegados por puerto serial*/
void Uart1_CallbackRx(_U08 u8Data)
{
    static unsigned short i = 0;

    gu8Buffer[i] = u8Data; /*se respalda dato*/
    i++;
    if(gu8Buffer[i-1] == '\r') /*fin de cadena?*/
    {
        gbFlag = 1;
        gu8Buffer[i] = '\0';   /*caracter nulo*/
        i = 0;           /*reinicia indice*/
    }
}

