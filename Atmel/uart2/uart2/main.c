/*
 * Se manda un msg por serial cada 1seg por el puerto serial 1. Pero ene sta ocasion se usan
 * interrupciones, tanto en las bases de timepo como en el puerto serial
 * para correr este demo debes habrir en tu PC una terminal por serial y setear su velocidad a 9600
 * no flow control y transferencia de 8 bits sin paridad
 * en bsp_profile se indica la frecuancia a 20MHz
 * #define BSP_CLOCK            20000000
 * y la base de tiempo en los timers se modifica
 * #define TIMERS_BASE_TIME     10
 */

#include <avr/io.h>
#include "types.h"
#include "uart/uart.h"
#include "system/system.h"
#include "swtimers/swtimers.h"
#include "gpios/gpios.h"

int main(void)
{
    Timers_Init();  /*incializamos los timer por software con 10ms de tiempo base*/
    Timers_SetTime(0, 1000/timers_ms);  /*cargamos el canal 0 con un tiempo de 1 seg*/
    Gpios_PinDirection(GPIOS_PORTD, 1, GPIOS_OUTPUT); /*pin de tx como salida*/

    Uart_Init(UART_PORT0, 9600);   /*se iniclaiza el puerto serial a 9600 baudios*/
    __ENABLE_INTERRUPTS();          /*habilitamos interrupciones globales*/

    while (1)
    {
        if(Timers_u16GetTime(0) == 0) /*trascurriero el segundo*/
        {
            Timers_SetTime(0, 1000/timers_ms);/*recargamos el mismo canal con 1 seg*/
            if(Uart_TxBusy(UART_PORT0) == _FALSE)              /*preguntamos si esta libre para transmitir*/
            {
                /*transmitimos una cadena de datos almacenada en flash*/
                Uart_TxBuffer(UART_PORT0, (const _U08*)"Hola mundo\n\r", sizeof("Hola mundo\n\r")-1);
            }
        }
    }
}

