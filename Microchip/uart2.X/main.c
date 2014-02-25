/*
 * Se manda un msg por serial cada 1seg por el puerto serial 1. Pero ene sta ocasion se usan
 * interrupciones, tanto en las bases de timepo como en el puerto serial
 * para correr este demo debes habrir en tu PC una terminal por serial y setear su velocidad a 115200
 * no flow control y transferencia de 8 bits sin paridad
 * en bsp_profile se indica la frecuancia a 48MHz
 * #define BSP_CLOCK            48000000
 * y la base de tiempo en los timers se modifica
 * #define TIMERS_BASE_TIME     10
 */

#include <p18cxxx.h>
#include "vectors.h"
#include "types.h"
#include "uart/uart.h"
#include "system/system.h"
#include "swtimers/swtimers.h"
#include "gpios/gpios.h"


#pragma code
void main(void)
{
    _U32 baudrate;

    System_EnablePLL();/*colocamos el procesador a 48MHz*/
    ANCON0 = 0XFF;  /*Desativamos las salidas analogicas*/
    ANCON1 = 0XFF;  /*Desativamos las salidas analogicas*/

    Timers_Init();  /*incializamos los timer por software con 10ms de tiempo base*/
    Timers_InterruptPriority(_HIGH);    /*le damos asu interrupcion prioridad alta*/
    Timers_SetTime(0, 1000/timers_ms);  /*cargamos el canal 0 con un tiempo de 1 seg*/
    Gpios_PinDirection(GPIOS_PORTC, 6, GPIOS_OUTPUT); /*pin de tx como salida*/

    baudrate = Uart_Init(UART_PORT1, 115200);   /*se iniclaiza el puerto serial a 115200 baudios*/
    __ENABLE_INTERRUPTS();          /*habilitamos interrupciones globales*/

    while (1)
    {
        if(Timers_u16GetTime(0) == 0) /*trascurriero el segundo*/
        {
            Timers_SetTime(0, 1000/timers_ms);/*recargamos el mismo canal con 1 seg*/
            if(Uart_TxBusy(UART_PORT1) == 0)              /*preguntamos si esta libre para transmitir*/
            {
                /*transmitimos una cadena de datos almacenada en flash*/
                Uart_TxFlashBuffer(UART_PORT1, (rom _U08*)"Hola mundo\n\r", sizeof("Hola mundo\n\r")-1);
            }
        }
    }
}


#pragma interrupt YourHighPriorityISRCode
void YourHighPriorityISRCode(void)
{
    Timers_Isr();/*interrupciones por timers cada 10ms*/
    /*coloca aquí el código que llevará tu interrupción en caso de usarla*/
}

#pragma interruptlow YourLowPriorityISRCode
void YourLowPriorityISRCode(void)
{
    Uart1_TxIsr();/*se transmite los datos seriales en esta interrupcion*/
    /*coloca aquí el código que llevará tu interrupción de baja prioridad en caso de usarla*/
}
