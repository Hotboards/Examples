/*
 * Simple programa que reliza la incializacion en un controlador hd44870, el cual tipicamente es usado
 * en un lcd alfanumerico. Se depliega un solo caracter 'A' ademas se apaga el cursor y el parapdeo,
 * en modo 8 bits
 * Es necesario revisar el archivo hardware_profile.h para revisar las conexiones al controlador
 */

#include <xc.h>
#include "fuses.h"
#include "types.h"
#include "delays/delays.h"
#include "6800/_6800.h"
#include "system/system.h"

_BOOL bBusyFlag(void)
{
    _U08 bFlag;
    bFlag = _6800_u8ReadAddr();
    return QUERY_8BIT(bFlag, 7);
}

int main(void)
{
    ANCON0 = 0XFF;  /*Desativamos las entradas analogicas*/
    ANCON1 = 0XFF;  /*Desativamos las entradas analogicas*/

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
    
    _6800_WriteCommand(0x30);           /*modo 8 bits y una linea activa*/
    while(bBusyFlag());
    _6800_WriteCommand(0x04);           /*Se apaga el controlador*/
    while(bBusyFlag());
    _6800_WriteCommand((_U08)0x01);     /*se enciende y limpia el display*/
    Delays_ms((_U08)2);                 /*para el comando clear screen se debe esperar 1.52ms*/
    _6800_WriteCommand(0x06);           /*incremento de cursor a la derecha*/
    while(bBusyFlag());
    _6800_WriteCommand(0x0C);           /*se apaga el cursor y el parpadeo*/
    while(bBusyFlag());
    
    _6800_WriteData('A');               /*Se imprime la letra A en el lcd*/
    /*a partir de este punto se pueden mandar caracteres al lcd, solo se requiere
     esperar 40us entre cada caracter o comando*/

    while (1)
    {

    }
}
