/*
 * Se manda un msg por serial 2 cada 1seg por el puerto serial 1.
 * para correr este demo debes habrir en tu PC una terminal por serial y setear su velocidad a 115200
 * no flow control y transferencia de 8 bits sin paridad
 * por default la velocidad de ejecucion seria de 12MHz
 * En este caso se le deben asignar los pines de trasnmicion y en caso de usarse el de recepecion a
 * cualquiera de los pines etiquetados como RPn en la hoja de datos.
 * en el driver system.h se encuentran funciones que facilitan esta operacion.
 */

#include <p18cxxx.h>
#include "vectors.h"
#include "types.h"
#include "uart/uart.h"
#include "delays/delays.h"
#include "gpios/gpios.h"
#include "system/system.h"

#pragma code
void main(void)
{
    _U32 baudrate;
    
    ANCON0 = 0XFF;  /*Desativamos las salidas analogicas*/
    ANCON1 = 0XFF;  /*Desativamos las salidas analogicas*/

    /*el uart2 no tiene pines asignados por default, se dene asignar mediante estas funciones*/
    System_PeripheralPinSelect(AsynchronousTransmit2, 19); /*asignamos uart2 tx a RD2*/
    System_PeripheralPinSelect(AsynchronousReceive2, 20);  /*asignamos uart2 rx a RD3*/
    
    Gpios_PinDirection(GPIOS_PORTD, 2, GPIOS_OUTPUT); /*pin de tx2 como salida*/

    baudrate = Uart_Init(UART_PORT2, 115200); /*se iniclaiza el puerto serial a 115200 baudios*/
    
    while (1)
    {
        Uart_PutString(UART_PORT2, "Hola mundo\n\r");   /*se manda mensaje por puerto serial*/
        Delays_ms(1000);                    /*se cicla por 1 seg*/
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
