/*
 * El programa muestra como utilizar la funcion printf en combinacion con los macros __FILE__ y 
 * __LINE__, pueden ser usados para depurar una aplicacion, se declara el macro assert el cual
 * manda un mensaje y traba el programa cuando su parametro sea falso, con esto se pueden revisar
 * situacion prohibidas o que no deben pasar en un programa.
 * Este sencillo programa genra numeros
 * del 0 al 6 al azar y se detecta la situacion prohibida, cuando la variable toma el valor de 0
 * por default la velocidad de ejecucion seria de 12MHz
 */

#include <p18cxxx.h>
#include "vectors.h"
#include "types.h"
#include "gpios/gpios.h"
#include "uart/uart1.h"
#include "printf/printf.h"
#include <stdlib.h>

/*macro assert el cual revisa que el parametro pasado no sea verdadero, en caso de serlo trabara el
 * programa y mandara un msj de error junto con el nombre del archivo y la linea donde esta el
 * supuesto error. */
#define xassert(statement)          if(!(statement)){xprintf("Error en archivo %s, linea %d", __FILE__, (_U16)__LINE__) ;while(1);}

#pragma code
void main(void)
{
    _U16 x, i;
    ANCON0 = 0XFF;  /*Desativamos las salidas analogicas*/
    ANCON1 = 0XFF;  /*Desativamos las salidas analogicas*/

    Gpios_PinDirection(GPIOS_PORTC, 6, GPIOS_OUTPUT); /*puerto de tx como salida*/
    
    (void)Uart1_Init(115200); /*velocidad a 115200 bauds*/
    xdev_out(Uart1_PutChar);  /*se redirecciona la salida printf via serial*/

    /*Se recomienda manejar siempre parametros arriba de 16 bits para un correcto funcionamiento*/
    /*cuando se usan constantes se debe forzosamente realizar un castaje*/
    srand(5); /*se inicializa la generacion de numeros al azar*/
    for(i=0;i<100;i++)
    {
        x = rand() % 6; /*se gnerean valores aleatorios en el rango de 0 a 6*/
        xassert(x);     /*se verifica que x no tome un valor prohibido, (en este caso 0)*/
        xprintf("En iteracion %3d, x vale: %d\n", i, x);/*si no es cero se imprime el valor de x*/
    }
    

    while (1)
    {
        /*aqui se trasnmiten los datos por la interrupcion de tx del uart*/
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


