/*
 * Simple ejemplo en el cual escribimos un byte en la direccion de memoria 0x0000
 * para despues leerlo y comprobar que se escribio. La memoria es una eeprom 25LC230
 * la cual posee una interfaz SPI. Se utliza el puerto serial a 115200 para msotrar
 * el dato leido de la memoria. El ejemplo muestra como utilizar las funciones
 * del periferico SPI2 y como configurar su funcionamiento, ademas de como trasnferir
 * datos.
 */

#include <p18cxxx.h>
#include "vectors.h"
#include "system/system.h"
#include "delays/delays.h"
#include "uart/uart.h"
#include "spi/spi.h"
#include "gpios/gpios.h"
#include "printf/printf.h"

void putChar(_U08 u8Char);

#pragma code
void main(void)
{
    _U08 u8Byte;

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
    Gpios_PinDirection(GPIOS_PORTE, 2, GPIOS_OUTPUT); /*pin RD3 como salida para actuar como CS*/
    Gpios_WritePin(GPIOS_PORTE, 2, 1);                /*inhabilitamos esclavo*/
    Gpios_PinDirection(GPIOS_PORTC, 6, GPIOS_OUTPUT); /*puerto de tx uart como salida*/

    (void)Uart_Init(UART_PORT1, 115200);            /*velocidad a 115200 bauds*/
    xdev_out(putChar);             /*funcion Uart1_PutChar como salida estandar*/
    Spi_Init(SPI_PORT2, SPI_4DIV);       /*inicializamos spi a 12MHz/4 = 3MHz*/

    /*Escribe aqui tu aplicacion*/
    Gpios_WritePin(GPIOS_PORTE, 2, 0);            /*habilitamos dispositivo esclavo*/
    (void)Spi_u8Transfer(SPI_PORT2, 0x06);        /*mandamos comando de write enable*/
    Gpios_WritePin(GPIOS_PORTE, 2, 1);            /*des habilitamos dispositivo esclavo*/
        
    Gpios_WritePin(GPIOS_PORTE, 2, 0);            /*habilitamos dispositivo esclavo*/
    (void)Spi_u8Transfer(SPI_PORT2, 0x02);        /*mandamos comando write*/
    (void)Spi_u8Transfer(SPI_PORT2, 0x00);        /*parte alta de la direccion de la memoria*/
    (void)Spi_u8Transfer(SPI_PORT2, 0x00);        /*parte baja de la direccion de la memoria*/
    (void)Spi_u8Transfer(SPI_PORT2, 0x23);        /*escribimos un byte 0x23*/
    Gpios_WritePin(GPIOS_PORTE, 2, 1);            /*des habilitamos dispositivo esclavo*/
    
    /*esperamos a que el dato se grabe en la memoria, no es la mejor manera de
     hacerlo, asi que solo es para propositos demostrativos*/
    Delays_ms(10);

    Gpios_WritePin(GPIOS_PORTE, 2, 0);            /*habilitamos dispositivo esclavo*/
    (void)Spi_u8Transfer(SPI_PORT2, 0x03);        /*mandamos comando read*/
    (void)Spi_u8Transfer(SPI_PORT2, 0x00);        /*parte alta de la direccion de la memoria*/
    (void)Spi_u8Transfer(SPI_PORT2, 0x00);        /*parte baja de la direccion de la memoria*/
    u8Byte = Spi_u8Transfer(SPI_PORT2, 0x55);     /*leemos un byte en la direccion 0x0000*/
    Gpios_WritePin(GPIOS_PORTE, 2, 1);            /*des habilitamos dispositivo esclavo*/

    /*mostramos por serial el byte leido el cual serae l mismo que escribimos 0x23*/
    xprintf("Registro de status: 0x%X\r\n", (_U16)u8Byte);

    while (1)
    {
        
    }
}

void putChar(_U08 u8Char)
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
