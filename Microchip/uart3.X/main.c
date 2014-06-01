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

#include <xc.h>
#include "fuses.h"
#include "types.h"
#include "uart/uart.h"
#include "system/system.h"
#include "swtimers/swtimers.h"
#include "gpios/gpios.h"
#include "gpis/gpis.h"

int main(void)
{
    System_EnablePLL();/*colocamos el procesador a 48MHz*/
    ANCON0 = 0XFF;  /*Desactivamos las entradas analogicas*/
    ANCON1 = 0XFF;  /*Desactivamos las entradas analogicas*/

    Timers_Init();  /*incializamos los timer por software con 10ms de tiempo base*/
    Timers_InterruptPriority(_HIGH);    /*le damos asu interrupcion prioridad alta*/
    Timers_SetTime(0, 10/timers_ms);  /*cargamos el canal 0 con un tiempo de 1 seg*/
    Gpis_Init();                     /*iniciamos la entrada conectada al boton*/
    Gpios_PinDirection(GPIOS_PORTC, 6, GPIOS_OUTPUT); /*pin de tx como salida*/
    (void)Uart_Init(UART_PORT1, 9600);   /*se iniclaiza el puerto serial a 9600 baudios*/
    __ENABLE_INTERRUPTS();          /*habilitamos interrupciones globales*/

    while (1)
    {
        if(Timers_u16GetTime(0) == 0) /*trascurriero el segundo*/
        {
            Timers_SetTime(0, 10/timers_ms);/*recargamos el mismo canal con 1 seg*/
            Gpis_Task();                    /*poleamos el boton*/
        }
        
        if(Gpis_bGetInput(0) == _TRUE)      /*preguntamos si se presiono el boton*/
        {
            if(Uart_TxBusy(UART_PORT1) == 0)              /*preguntamos si esta libre para transmitir*/
            {
                /*transmitimos una cadena de datos almacenada en flash*/
                Uart_TxBuffer(UART_PORT1, "Boton uno\n\r", sizeof("Boton uno\n\r")-1);
            }
        }     
    }
}


void interrupt high_isr(void)
{
    Timers_Isr();/*interrupciones por timers cada 10ms*/
    /*coloca aquí el código que llevará tu interrupción en caso de usarla*/
}

void interrupt low_priority low_isr (void)
{
    Uart1_TxIsr();/*se transmite los datos seriales en esta interrupcion*/
    /*coloca aquí el código que llevará tu interrupción de baja prioridad en caso de usarla*/
}
