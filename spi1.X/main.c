/*
 * simple lectura del descriptor de una memoria NOR flash de la marca Micron.
 * en este ejemplo se muestra la forma de transmitir del spi (enviando un comando a la memoria) y la
 * lectura de datos (enviando datos dummy), asi como la implemnetacion de un pin del micro como Chip
 * Select. Una vez leidos los datos se envian por serial de manera formateada con la funcion xprintf
 * por default la velocidad de ejecucion seria de 12MHz
 */

#include <p18cxxx.h>
#include "vectors.h"
#include "types.h"
#include "spi/spi1.h"
#include "gpios/gpios.h"
#include "printf/printf.h"
#include "uart1/uart2.h"
#include "delays/delays.h"
#include "system/system.h"

#define DUMMY   0xaa

#pragma code
void main(void)
{
    _U08 id, type, capacity;

    ANCON0 = 0XFF;  /*Desativamos las salidas analogicas*/
    ANCON1 = 0XFF;  /*Desativamos las salidas analogicas*/

    /*el uart2 no tiene pines asignados por default, se dene asignar mediante estas funciones*/
    System_PeripheralPinSelect(AsynchronousTransmit2, 19); /*asignamos uart2 tx a RD2*/
    
    Gpios_PinDirection(GPIOS_PORTD, 2, GPIOS_OUTPUT);   /*pin de tx2 como salida*/
    Uart2_Init(115200);                                 /*iniciamos puerto serial 1 a 115200*/
    xdev_out(Uart2_PutChar);                            /*funcion putchar como salida de printf*/

    Gpios_PinDirection(GPIOS_PORTD, 3, GPIOS_OUTPUT); /*pin RD3 como salida para actuar como CS*/
    Gpios_WritePin(GPIOS_PORTD, 3, 1);                /*inabilitamos esclavo (en este caso memmoria externa)*/
    Gpios_PinDirection(GPIOS_PORTC, 7, GPIOS_OUTPUT); /*pin RD7 como salida para SDO*/
    Gpios_PinDirection(GPIOS_PORTB, 4, GPIOS_OUTPUT); /*pin RB4 como salida para SCK*/
    Gpios_PinDirection(GPIOS_PORTB, 5, GPIOS_INPUT);  /*pin RB4 como salida para SDI*/
    
    Spi1_Init(SPI1_4DIV);                              /*inicializamos spi a 12MHz/4 = 3MHz*/


    while (1)
    {
        Gpios_WritePin(GPIOS_PORTD, 3, 0);   /*habilitamos dispositivo esclavo (memoria)*/

        (void)Spi1_u8Transfer(0x9F);         /*enviamos commado para leer identificador*/

        id = Spi1_u8Transfer(DUMMY);         /*leemos id*/
        type = Spi1_u8Transfer(DUMMY);       /*leemos tipo de memoria*/
        capacity = Spi1_u8Transfer(DUMMY);   /*leemos capacidad de la memoria*/

        Gpios_WritePin(GPIOS_PORTD, 3, 1);   /*deshabilitamos dispositivo esclavo (memoria)*/
        
        xprintf("\nmemoria: %x\n", (_U16)id);
        xprintf("tipo de memoria: %x\n", (_U16)type);
        xprintf("capacidad: %x\n", (_U16)capacity);
        Delays_ms(2000);
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
