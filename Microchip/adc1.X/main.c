/*
 * Se muestre al canal 2 con una resolucion por default de 10 bits. despues de samplear se manda el
 * resultado por serial y se muestra en una terminal. Entre toma de mediciones se deja esperando un
 * tiempo de 100ms
 * por default la velocidad de ejecucion seria de 12MHz
 */

#include <xc.h>
#include "fuses.h"
#include "types.h"
#include "gpios/gpios.h"
#include "uart/uart.h"
#include "printf/printf.h"
#include "adc/adc.h"
#include "delays/delays.h"

void putc(const _U08 c)
{
    Uart_PutChar(UART_PORT1, c);
}

int main(void)
{
    _U16 adc;                       /*variable que almacenara el resultado del adc (canal 3)*/

    ANCON0 = 0XFF;                  /*Desativamos las entradas analogicas*/
    ANCON1 = 0XFF;                  /*Desativamos las entradas analogicas*/

    Adc_Init(ADC_10BITS);           /*se inciliza el adc con resolucion de 10bits*/
    Gpios_PinDirection(GPIOS_PORTC, 6, GPIOS_OUTPUT); /*puerto de tx como salida*/

    (void)Uart_Init(UART_PORT1, 115200);       /*velocidad a 115200 bauds*/
    xdev_out(putc);                            /*funcion Uart_PutChar como salida*/

    while (1)
    {
        adc = Adc_u16Read(2);                   /*Se lee la lectura del canal 2 en el adc*/
        xprintf("valor analogo: %5d\r", adc);   /*se imprime el valor por serial*/
        Delays_ms(100);                         /*Retardo de 100ms*/
    }
}
