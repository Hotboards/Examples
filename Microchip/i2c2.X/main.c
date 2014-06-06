/*
 * Simple ejemplo en el cual se lee el registro donde se almacena la temperatura en el sensor digital
 * TC74, atravez de su interfaz I2C. Se configura el modulo MSSP2 en modo I2C maestro, los pines de este sensor estanconectados
 * a los pines D0=SCL y D1=SDA de la tarjeta pepper-8m. Se utliza el puerto serial a 115200 para mostrar
 * el dato leido del sensor. El ejemplo muestra pregunta al sensor por la temperatura cada segundo
 * del driver I2C2 y como ensamblar una simple comunicacion.
 */

#include <xc.h>
#include "fuses.h"
#include "i2c/i2c.h"
#include "gpios/gpios.h"
#include "uart/uart.h"
#include "delays/delays.h"
#include "printf/printf.h"

void putChar(const _U08 u8Char);

int main(void)
{
    _S08 i8Config;

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
        I2c_Start(I2C_PORT2);                                   /*generamos condicion start*/
        (void)I2c_bTxByte(I2C_PORT2, ADDR_WRITE(0b1001101));    /*mandamos direccion del sensor en modo escritura*/
        (void)I2c_bTxByte(I2C_PORT2, 0x00);                     /*mandamos direccion de la lectura d ela temperatura*/
        I2c_RepeatedStart(I2C_PORT2);                           /*repetimos señal start*/
        (void)I2c_bTxByte(I2C_PORT2, ADDR_READ(0b1001101));     /*madamos direccion del sensor en modo lectura*/
        i8Config = (_S08)I2c_u8RxByte(I2C_PORT2, I2C_NACK);     /*leemos dato (temperatura) y contestamos NACK*/
        I2c_Stop(I2C_PORT2);                                    /*indicamos fin de comunicacion*/

        /*mostramos por serial el byte leido el cual tendra el valor de la temp ambiental*/
        xprintf("Temperatura ambiente: %d\r", (_S16)i8Config);
        Delays_ms(1000);
    }
}

void putChar(const _U08 u8Char)
{
    Uart_PutChar(UART_PORT1, u8Char);
}
