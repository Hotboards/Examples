/*
 * Simple programa que reliza la incializacion en un controlador hd44870, el cual tipicamente es usado
 * en un lcd alfanumerico. Se depliega un solo caracter '4' ademas se apaga el cursor y el parapdeo,
 * la diferencia con los programas anteriores es que esta vez se usa la interfaz de 4bits y a demas
 * la frecuencia del CPU es de 48MHz, por lo que el tiempo de la señal de Enable se aumenta a 4, colocando
 * la siguiente linea en el archivo hardwareware_profile.h
 * #define _6800_ENABLE_TIME           4
 * Es necesario revisar el archivo hardware_profile.h para revisar las conexiones al controlador
 */

#include <xc.h>
#include "fuses.h"
#include "types.h"
#include "delays/delays.h"
#include "system/system.h"
#include "6800/_6800.h"

_BOOL bBusyFlag(void)
{
    _U08 bFlag;
    bFlag = _6800_u8ReadAddr();
    bFlag |= (_6800_u8ReadAddr()>>4);
    return QUERY_8BIT(bFlag, 7);
}

int main(void)
{

    ANCON0 = 0XFF;  /*Desactivamos las entradas analogicas*/
    ANCON1 = 0XFF;  /*Desactivamos las entradas analogicas*/

    System_EnablePLL();
    _6800_Init();
    /*secuencia para incilizar controlador*/
    Delays_ms((_U08)15);                /* 15 ms para que el controlador encienda */
    _6800_WriteCommand((_U08)0x30);	/* Secuecia de encendido en modo 8 bits */
    Delays_ms((_U08)5);
    _6800_WriteCommand((_U08)0x30);
    Delays_ms((_U08)2);
    _6800_WriteCommand((_U08)0x30);
    while(bBusyFlag());
    
    _6800_WriteCommand(0x20);           /*modo 4 bits y una linea activa*/
    while(bBusyFlag());
    
    _6800_WriteCommand(0x04);           /*Se apaga el controlador, nibble alto*/
    _6800_WriteCommand(0x04<<4);        /*nibble bajo*/
    while(bBusyFlag());
    
    _6800_WriteCommand((_U08)0x01);     /*se enciende y limpia el display, nibble alto*/
    _6800_WriteCommand((_U08)0x01<<4);  /*nibble bajo */
    Delays_ms((_U08)2);                 /*para el comando clear screen se debe esperar 1.52ms*/

    _6800_WriteCommand(0x06);           /*incremento de cursor a la derecha, nibble alto*/
    _6800_WriteCommand(0x06<<4);        /*nibble bajo */
    while(bBusyFlag());
    
    _6800_WriteCommand(0x0c);           /*se apaga el cursor y el parpadeo, nibble alto*/
    _6800_WriteCommand(0x0c<<4);        /*nibble bajo */
    while(bBusyFlag());
    
    _6800_WriteData('4');               /*Se imprime la letra 'e' en el lcd, nibble alto*/
    _6800_WriteData('4'<<4);            /*nibble bajo */
    /*a partir de este punto se pueden mandar caracteres al lcd, solo se requiere
     esperar 40us entre cada caracter o comando*/

    while (1)
    {

    }
}
