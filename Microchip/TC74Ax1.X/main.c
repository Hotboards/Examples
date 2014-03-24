/*
 * Simple ejemplo en el cual se lee el valor de la temperatura proporcionado por el sensor digital
 * TC47 de microchip. Los pines de este sensor estanconectados
 * a los pines D0=SCL y D1=SDA de la tarjeta pepper-8m. Se utliza el puerto serial a 115200 para mostrar
 * el dato leido del sensor. 
 */

#include <p18cxxx.h>
#include "vectors.h"
#include "i2c/i2c.h"
#include "gpios/gpios.h"
#include "uart/uart.h"
#include "delays/delays.h"
#include "printf/printf.h"
#include "tc74ax/tc74ax.h"

void putChar(const _U08 u8Char);

#pragma code
void main(void)
{
    _S08 i8Temp;

    ANCON0 = 0XFF;  /*Desativamos las entradas analógicas*/
    ANCON1 = 0XFF;  /*Desativamos las entradas analógicas*/

    Gpios_PinDirection(GPIOS_PORTD, 0, GPIOS_INPUT);  /*SCL2*/
    Gpios_PinDirection(GPIOS_PORTD, 1, GPIOS_INPUT);  /*SDA2*/
    Gpios_PinDirection(GPIOS_PORTC, 6, GPIOS_OUTPUT); /*puerto de tx uart como salida*/

    (void)Uart_Init(UART_PORT1, 115200);   /*velocidad a 115200 bauds*/
    xdev_out(putChar);                     /*funcion Uart_PutChar como salida estandar*/

    I2c_Init(I2C_PORT2, 100000);           /*puerto I2C 2 a 100KHz de velocidad*/

    while (1)
    {
        i8Temp = Tc74ax_ReadTemp(TC74A5);
        /*mostramos por serial el byte leido el cual tendra el valor de la temp ambiental*/
        xprintf("Temperatura ambiente: %d\r", (_S16)i8Temp);
        Delays_ms(1000);
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
