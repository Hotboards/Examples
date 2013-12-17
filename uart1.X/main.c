/*
 * Se manda un msg por serial cada 1seg por el puerto serial 1.
 * para correr este demo debes habrir en tu PC una terminal por serial y setear su velocidad a 115200
 * no flow control y transferencia de 8 bits sin paridad
 * por default la velocidad de ejecucion seria de 12MHz
 */

#include <p18cxxx.h>
#include "vectors.h"
#include "types.h"
#include "uart1/uart1.h"
#include "delays/delays.h"
#include "gpios/gpios.h"

#pragma code
void main(void)
{
    _U32 baudrate;
    
    ANCON0 = 0XFF;  /*Desativamos las salidas analogicas*/
    ANCON1 = 0XFF;  /*Desativamos las salidas analogicas*/

    Gpios_PinDirection(GPIOS_PORTC, 6, GPIOS_OUTPUT); /*pin de tx como salida*/

    baudrate = Uart1_Init(115200); /*se iniclaiza el puerto serial a 115200 baudios*/
    
    while (1)
    {
        Uart1_PutString("Hola mundo\n\r");   /*se manda mensaje por puerto serial*/
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
