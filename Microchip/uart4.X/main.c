/*
 * Simple programa que retrasmite un eco cada que presionas una tecla,
 * para correr este demo debes habrir en tu PC una terminal por serial y setear su velocidad a 9600
 * no flow control y transferencia de 8 bits sin paridad
 * en bsp_profile se indica que se usara la Rx del puerto serial
 * #define UART_ENABLE_RX1      1
 * recuerda que dentro de tu aplicacion debes definir lo que hara la funcion
 * void Uart1_CallbackRx(_U08 u8Data)
 */

#include <p18cxxx.h>
#include "vectors.h"
#include "types.h"
#include "uart/uart.h"
#include "system/system.h"
#include "gpios/gpios.h"

static _U08 gu8RxData;
static _BOOL gbFlag = 0;

#pragma code
void main(void)
{
    _U32 baudrate;

    ANCON0 = 0XFF;  /*Desativamos las salidas analogicas*/
    ANCON1 = 0XFF;  /*Desativamos las salidas analogicas*/

    Gpios_PinDirection(GPIOS_PORTC, 6, GPIOS_OUTPUT); /*pin de tx como salida*/
    Gpios_PinDirection(GPIOS_PORTC, 7, GPIOS_INPUT); /*pin de rx como entrada*/
    baudrate = Uart_Init(UART_PORT1, 9600);   /*se iniclaiza el puerto serial a 9600 baudios*/
    __ENABLE_INTERRUPTS();          /*habilitamos interrupciones globales*/

    while (1)
    {
        if(gbFlag == 1) /*llego un caracter por teclado*/
        {
            gbFlag = 0; /*limpiamos la bandera*/
            Uart_PutChar(UART_PORT1, gu8RxData);/*lo enviamos de regreso para tener feedback visual*/
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
    Uart1_RxIsr();/*en esta funcion se capturan los datos de llegada*/
    /*coloca aquí el código que llevará tu interrupción de baja prioridad en caso de usarla*/
}

/*esta funcion es llamda dentro de la funcion Uart_RxIsr() y se encarga de pasar a la aplicacion
 los datos llegados por puerto serial*/
void Uart1_CallbackRx(_U08 u8Data)
{
    gu8RxData = u8Data;/*se respalda el dato llegado en una variable global*/
    gbFlag = 1;     /*se activa una bandera para indicar a la aplicacion que se tien un dato*/
}

