/*
 * Se envia una cadena de caracteres por cada fila en un lcd de 4x20.
 * El lcd esta conectado mediante un bus de 8 bits
 * por default la velocidad de ejecucion seria de 12MHz
 */

#include <p18cxxx.h>
#include "vectors.h"
#include "types.h"
#include "hd44780/hd44780.h"

#pragma code
void main(void)
{
    ANCON0 = 0XFF;  /*Desativamos las salidas analogicas*/
    ANCON1 = 0XFF;  /*Desativamos las salidas analogicas*/

    HD44780_Init();

    HD44780_WriteString("Hola mundo4");
    HD44780_SetCursor(1,1);
    HD44780_WriteString("Hola mundo3");
    HD44780_SetCursor(2,2);
    HD44780_WriteString("Hola mundo2");
    HD44780_SetCursor(3,3);
    HD44780_WriteString("Hola mundo1");
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
