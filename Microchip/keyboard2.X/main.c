/*
 * Simple ejemplo en donde usamos el teclado matrizial de 4x4 para ingresar vaoler de 0 a 15 y
 * desplegarlos en leds conectados al puerto B (B0 - B3), polearemos las entradas cada 10ms y
 * evaluaremos si se presiono un boton con un tiempo de debounce por default de 50ms.
 * la unica diferencia con ele ejemplo anterior es que seteamos 4 teclas con un debounce de 500ms
 * Se debe revisar el archivo hardware_profile.h donde se encuentran los pines conectados al teclado
 * recuerda conectar resistencias de pullups a los pines en las columnas
 * keuboard layout 4x4
 *     c0  c1  c2  c3
 *    -----------------
 * r0 | 0 | 4 | 8 | C | <= teclas con 500ms de debounce
 *    -----------------
 * r1 | 1 | 5 | 9 | D |
 *    -----------------
 * r2 | 2 | 6 | A | E |
 *    -----------------
 * r3 | 3 | 7 | B | F |
 *    -----------------
 */



#include <xc.h>
#include "fuses.h"
#include "types.h"
#include "gpios/gpios.h"
#include "system/system.h"
#include "swtimers/swtimers.h"
#include "keyboard/keyboard.h"

int main(void)
{
    _U08 key;

    System_EnablePLL(); /*Elevamos la frecuencia de operacion a 48MHz*/
    ANCON0 = 0XFF;      /*Desativamos las salidas analogicas*/
    ANCON1 = 0XFF;      /*Desativamos las salidas analogicas*/

    Timers_Init();                      /*inicializamos el driver para genere una interrupcion cada 5ms*/
    Timers_SetTime(0, 10/timers_ms);    /*recargamos el canal 0 con un valor de 10ms*/
    Keyboard_Init();                    /*Inicilizamos las entradas y salidas del teclado*/
    Gpios_WriteTris(GPIOS_PORTB, 0x00); /*puerto B como salida*/
    Gpios_WritePort(GPIOS_PORTB, 0x00); /*limpiamos el puerto*/
    Keyboard_SetDebounce(0, 50);        /*500ms de debouncea a la tecla 0*/
    Keyboard_SetDebounce(4, 50);        /*500ms de debounce a la tecla 4*/
    Keyboard_SetDebounce(8, 50);        /*500ms de debounce a la tecla 8*/
    Keyboard_SetDebounce(12, 50);       /*500ms de debounce a la tecla 12*/
    __ENABLE_INTERRUPTS();              /*se habilitan las interrupciones globales con prioridad*/

    while (1)
    {
        if(Timers_u16GetTime(0) == 0)   /*preguntamos si la interrupcion decrmento hasta llegar a 0 el canal 0*/
        {
            Timers_SetTime(0, 10/timers_ms);/*se cumplen los 100ms asi que volvemos a recargar el mismo canal */
            Keyboard_Task();                /*poleamos poleamos el teclado matrizial*/
        }

        if(Keyboard_bIsPressed() == _TRUE)          /*preguntamos si se presiono alguna tecla*/
        {
            key = Keyboard_u8GetKey();              /*obtenemos cual tecla se presiono*/
            Gpios_WritePort(GPIOS_PORTB, key);     /*despliego el valor de la tecla en el puerto B*/
        }
    }
}


void interrupt low_priority low_isr(void)
{
    Timers_Isr();
}
