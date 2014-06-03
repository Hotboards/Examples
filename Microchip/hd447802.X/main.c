/*
 * Se utiliza la funcion tipo printf para mandar mensajes a que desplieguen en el lcd
 * se coloca el uC a 48MHz (revisarl el archivo hardware_profile.h)
 * se utiliza la interfaz 6800 en modo de 4 bits (revisar el archivo hardware_profile.h)
 * el lcd usado es uno de 4 filas y 20 columnas (revisar el archivo hardware_profile.h)
 */

#include <xc.h>
#include "fuses.h"
#include "types.h"
#include "system/system.h"
#include "hd44780/hd44780.h"
#include "printf/printf.h"

int main(void)
{
    ANCON0 = 0XFF;  /*Desactivamos las entradas analogicas*/
    ANCON1 = 0XFF;  /*Desactivamos las entradas analogicas*/

    System_EnablePLL();                                 /*uC a 48MHz*/
    HD44780_Init();                                     /*inicliza el LCD*/
    xdev_out(HD44780_WriteData);                        /*establece elcd como salida*/
    xprintf("Tengo %d edad", (_U16)29);                 /*imprime una cadena de caracteres*/
    HD44780_SetCursor(2, 0);                            /*se cambia el cursor a la linea 2 columna 5*/
    xprintf("Hoy es %d de %d", (_U16)30, (_U16)1984);   /*se imprime otra linea de caracteres*/
    while (1)
    {

    }
}
