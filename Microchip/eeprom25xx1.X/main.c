/*
 * En este ejemplo se escriben 32 bytes apartir de la direccion 0 de la memoria
 * para despues leerse de la misma y desplegarse en el puerto serial usando la
 * funcion xprintf.
 * Para correr el demo es necesario la tarjeta Pepper-Pot. De la contrario se debe
 * conectar una eeprom Microchip 25xx320a a acorde a como lo muestra el esquematico
 * de la pepper-pot
 */

#include <p18cxxx.h>
#include "vectors.h"
#include "system/system.h"
#include "uart/uart.h"
#include "spi/spi.h"
#include "gpios/gpios.h"
#include "printf/printf.h"
#include "eeprom25xx/eeprom25xx.h"

void putChar(const _U08 u8Char);

_U08 gau8BufferOut[32];
_U08 gau8BufferIn[32];

#pragma code
void main(void)
{
    _U08 i;

    /*Inicializa aqui tu aplicacion*/
    /*Inicializa aqui tu aplicacion*/
    ANCON0 = 0XFF;  /*Desativamos las entradas analógicas*/
    ANCON1 = 0XFF;  /*Desativamos las entradas analógicas*/

    /*el modulo spi2 no tiene los pines conectados asi que hay que
     asignarlos a los pines RPx que deseemos*/
    System_PeripheralPinSelect(SPI2DataInput, 11);   /*SDI en el pin RP11 (C0)*/
    System_PeripheralPinSelect(SPI2DataOutput, 12);  /*SDO en el pin RP12 (C1)*/
    System_PeripheralPinSelect(SPI2ClockOutput, 13); /*SCK en el pin RP13 (C2)*/

    Gpios_PinDirection(GPIOS_PORTC, 0, GPIOS_INPUT);  /*pin RB4 como salida para SDI*/
    Gpios_PinDirection(GPIOS_PORTC, 1, GPIOS_OUTPUT); /*pin RD7 como salida para SDO*/
    Gpios_PinDirection(GPIOS_PORTC, 2, GPIOS_OUTPUT); /*pin RB4 como salida para SCK*/
    Gpios_PinDirection(GPIOS_PORTC, 6, GPIOS_OUTPUT); /*puerto de tx uart como salida*/

    (void)Uart_Init(UART_PORT1, 115200);            /*velocidad a 115200 bauds*/
    xdev_out(putChar);             /*funcion Uart_PutChar como salida estandar*/
    Spi_Init(SPI_PORT2, SPI_4DIV);       /*inicializamos spi a 12MHz/4 = 3MHz*/
    Eeprom25xx_Init(EEPROM25XX_MEMORY0, EEPROM25XX_32K);/*incializamos el driver indicando una memoria de 32Kbits*/

    for(i=0;i<32;i++)
    {/*cargamos el buffer con los datos a escribir, numeros del 0 al 32*/
        gau8BufferOut[i] = i;
    }

    Eeprom25xx_Write(EEPROM25XX_MEMORY0, &gau8BufferOut[0], 0, 32); /*Grabamos los 32 bytes en la pagina 0 de la memoria*/
    while((Eeprom25xx_u8ReadStatus(EEPROM25XX_MEMORY0) & EEPROM25XX_BUSY) != 0){}/*esperamos a que termine de grabarlos*/
    Eeprom25xx_Read(EEPROM25XX_MEMORY0, &gau8BufferIn[0], 0, 32); /*leemos los 32 bytes de la direccion 0 de la memoria*/

    /*desplegamos en el puerto serial lo que se leyo de la memoria*/
    xprintf("Contenido de la pagina :\r\n");
    for(i=0;i<32;i++)
    {
        if((i%10) == 0)
        {
            xprintf("\r\n");
        }
        xprintf(" 0x%02X", (_U16)gau8BufferIn[i]);
    }

    while (1)
    {
        /*Escribe aqui tu aplicacion*/
    }
}

void putChar(const _U08 u8Char)
{
    Uart_PutChar(UART_PORT1, u8Char);
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
