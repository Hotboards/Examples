/*
 * Se manda un msg por serial cada que se presiona el boton puesto en la tarjeta, por el puerto
 * serial 1. En esta ocasion se siguen usando interrupciones tanto en las bases de timepo como en el
 * puerto serial
 * para correr este demo debes habrir en tu PC una terminal por serial y setear su velocidad a 9600
 * no flow control y transferencia de 8 bits sin paridad
 * en bsp_profile se indica la frecuancia a 48MHz
 * #define BSP_CLOCK            48000000
 * y la base de tiempo en los timers se modifica
 * #define TIMERS_BASE_TIME     10
 * en middleware profile definimos la entrada donde esta el boton
 * #define GPIS_N_INPUTS       1
 * #define GPIS_B0_P           GPIOS_PORTA
 * #define GPIS_B0_B           0
 */

#include <avr/io.h>
#include "types.h"
#include "uart/uart.h"
#include "system/system.h"
#include "swtimers/swtimers.h"
#include "gpios/gpios.h"
#include "gpis/gpis.h"

int main(void)
{
    Timers_Init();  /*incializamos los timer por software con 10ms de tiempo base*/
    Timers_SetTime(0, 10/timers_ms);  /*cargamos el canal 0 con un tiempo de 10 milisegundos*/
    Gpis_Init();                     /*iniciamos la entrada conectada al boton*/
    Gpios_PinDirection(GPIOS_PORTC, 6, GPIOS_OUTPUT); /*pin de tx como salida*/
    (void)Uart_Init(UART_PORT0, 9600);   /*se iniclaiza el puerto serial a 9600 baudios*/
    __ENABLE_INTERRUPTS();          /*habilitamos interrupciones globales*/

    while (1)
    {
        if(Timers_u16GetTime(0) == 0) /*trascurriero los 10 mili segundos*/
        {
            Timers_SetTime(0, 10/timers_ms);/*recargamos el mismo canal con 10 mili segundos*/
            Gpis_Task();                    /*poleamos el boton*/
        }
        
        if(Gpis_bGetInput(0) == _TRUE)      /*preguntamos si se presiono el boton*/
        {
            if(Uart_TxBusy(UART_PORT0) == 0)              /*preguntamos si esta libre para transmitir*/
            {
                /*transmitimos una cadena de datos almacenada en flash*/
                Uart_TxBuffer(UART_PORT0, (const _U08*)"Boton uno\n\r", sizeof("Boton uno\n\r")-1);
            }
        }     
    }
}

