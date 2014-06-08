/*
 * Se envia una cadena de caracteres por cada fila en un lcd de 2x16.
 * El lcd esta conectado mediante el bus serie spi2
 * por default la velocidad de ejecucion seria de 12MHz
 */

#include <xc.h>
#include "fuses.h"
#include "types.h"
#include "system/system.h"
#include "gpios/gpios.h"
#include "spi/spi.h"
#include "st7032/st7032.h"

int main(void)
{
    ANCON0 = 0XFF;  /*Desativamos las salidas analogicas*/
    ANCON1 = 0XFF;  /*Desativamos las salidas analogicas*/

    /*el modulo spi2 no tiene los pines conectados asi que hay que
     asignarlos a los pines RPx que deseemos*/
    System_PeripheralPinSelect(SPI2DataInput, 11);   /*SDI en el pin RP11 (C0)*/
    System_PeripheralPinSelect(SPI2DataOutput, 12);  /*SDO en el pin RP12 (C1)*/
    System_PeripheralPinSelect(SPI2ClockOutput, 13); /*SCK en el pin RP13 (C2)*/

    Gpios_PinDirection(GPIOS_PORTC, 0, GPIOS_INPUT);  /*pin RB4 como salida para SDI*/
    Gpios_PinDirection(GPIOS_PORTC, 1, GPIOS_OUTPUT); /*pin RD7 como salida para SDO*/
    Gpios_PinDirection(GPIOS_PORTC, 2, GPIOS_OUTPUT); /*pin RB4 como salida para SCK*/
    
    Spi_Init(SPI_PORT2, SPI_4DIV);
    ST7032_Init(ST7032_LCD0);

    ST7032_SetCursor(ST7032_LCD0, 0, 1); /*ubico cursor en el primer renglon del lcd*/
    ST7032_WriteString(ST7032_LCD0, "Hola mundo1");
    ST7032_SetCursor(ST7032_LCD0, 1, 2); /*ubico cursor en el segundo renglon del lcd*/
    ST7032_WriteString(ST7032_LCD0, "Hola mundo2");
    
    while (1)
    {

    }
}
