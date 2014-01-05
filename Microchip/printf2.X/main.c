/*
 * El programa usa la funcion xsprintf para almacenar una cadena formateada en un arreglo de maximo
 * 20 caracteres, para depues transmitirse por puerto serial usando interrupciones, el programa solo
 * lo hase una vez, con propositos demostrativos.
 * por default la velocidad de ejecucion seria de 12MHz
 */

#include <p18cxxx.h>
#include "vectors.h"
#include "types.h"
#include "gpios/gpios.h"
#include "uart/uart1.h"
#include "system/system.h"
#include "printf/printf.h"
#include <string.h>

#pragma code
void main(void)
{
    _U08 c, buffer[20] = {0};
    ANCON0 = 0XFF;  /*Desativamos las salidas analogicas*/
    ANCON1 = 0XFF;  /*Desativamos las salidas analogicas*/

    Gpios_PinDirection(GPIOS_PORTC, 6, GPIOS_OUTPUT); /*puerto de tx como salida*/

    (void)Uart1_Init(115200); /*velocidad a 115200 bauds*/

    __ENABLE_INTERRUPTS();
    /*Se recomienda manejar siempre parametros arriba de 16 bits para un correcto funcionamiento*/
    /*cuando se usan constantes se debe forzosamente realizar un castaje, como en este ejemplo*/
    xsprintf(buffer, (const _U08*)"Cadena %d, %d\n", (_U16)-200, (_U16)35);/*la cadena se almacena la cadena en un buffer*/
    /*se determina cuan larga es la cadena*/
    c = strlen((const char*)buffer);
    /*Se transmiten los datos por interrupciones*/
    Uart1_TxBuffer((const _U08*)buffer, c);
    while (1)
    {
        /*aqui se trasnmiten los datos por la interrupcion de tx del uart*/
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
    Uart1_TxIsr();/*en esta funcion se trasmiten los datos por serial*/
    /*coloca aquí el código que llevará tu interrupción de baja prioridad en caso de usarla*/
}


