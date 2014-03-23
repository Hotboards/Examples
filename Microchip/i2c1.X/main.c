/*
 * Simple ejemplo en el cual se lee el registro CONFIG del snesor digital TC74, atravez de su interfaz
 * I2C. Se configura el modulo MSSP2 en modo I2C maestro, los pines de este sensor estanconectados
 * a los pines D0=SCL y D1=SDA de la tarjeta pepper-8m. Se utliza el puerto serial a 115200 para mostrar
 * el dato leido del sensor. El ejemplo muestra como utilizar las funciones
 * del driver I2C2 y como ensamblar una simple comunicacion.
 */

#include <p18cxxx.h>
#include "vectors.h"
#include "i2c/i2c.h"
#include "gpios/gpios.h"
#include "uart/uart.h"
#include "printf/printf.h"

void putChar(const _U08 u8Char);

#pragma code
void main(void)
{
    _U08 u8Config;

    ANCON0 = 0XFF;  /*Desativamos las entradas analógicas*/
    ANCON1 = 0XFF;  /*Desativamos las entradas analógicas*/

    Gpios_PinDirection(GPIOS_PORTD, 0, GPIOS_INPUT);  /*SCL2*/
    Gpios_PinDirection(GPIOS_PORTD, 1, GPIOS_INPUT);  /*SDA2*/
    Gpios_PinDirection(GPIOS_PORTC, 6, GPIOS_OUTPUT); /*puerto de tx uart como salida*/

    (void)Uart_Init(UART_PORT1, 115200);   /*velocidad a 115200 bauds*/
    xdev_out(putChar);                     /*funcion Uart_PutChar como salida estandar*/

    I2c_Init(I2C_PORT2, 100000);           /*puerto I2C 2 a 100KHz de velocidad*/

    I2c_Start(I2C_PORT2);                                   /*generamos condicion start*/
    (void)I2c_bTxByte(I2C_PORT2, ADDR_WRITE(0b1001101));    /*madamos direccion del sensor en modo escritura*/
    (void)I2c_bTxByte(I2C_PORT2, 0x01);                     /*mandamos direccion a leer*/
    I2c_RepeatedStart(I2C_PORT2);                           /*repetimos señal start*/
    (void)I2c_bTxByte(I2C_PORT2, ADDR_READ(0b1001101));     /*madmaos direccion del sensor en modo lectura*/
    u8Config = I2c_u8RxByte(I2C_PORT2, I2C_NACK);           /*leemos dato leido y contestamos NACK*/
    I2c_Stop(I2C_PORT2);                                    /*indicamos fin de comunicacion*/

    /*mostramos por serial el byte leido el cual tendra el valor de 0x40, indica sensor listo*/
    xprintf("Registro config: 0x%X\r\n", (_U16)u8Config);

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
