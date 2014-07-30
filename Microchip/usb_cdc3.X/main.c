/*
 * simple ejemplo de emulacion del puerto serial atravez del usb,
 * solo conecta tu pepper-8m al puerto usb, carga el programa y habre
 * tu terminal serial (tera term) a una velocidad 9600, 8bits, no flow control
 * escribe la palabra toggle mas la tecla ENTER en la terminal y observa como el led de la
 * tarjeta parpadea.
 */

#include "fuses.h"
#include "usb_cdc/usb_cdc.h"
#include "system/system.h"
#include "gpios/gpios.h"
#include <string.h>

_U08 buffer[64];
_U08 temp;
_U08 numBytesRead=0;

int main(void)
{
    System_EnablePLL(); /*micro a 48MHz, esto es obligatorio para el USB*/
    UsbCDC_Init(9600);  /*inicia emulacion serial a 9600 baudios*/
    Gpios_PinDirection(GPIOS_PORTA, 1, GPIOS_OUTPUT);/*pin RA1 como salida*/
    
    while(1)
    {
        if(UsbCDC_bEnumerated() == _TRUE) /*usb enumarado*/
        {
            temp = UsbCDC_u8RxData( &buffer[numBytesRead], 64 );/*recivimos datos por usb serial*/
            if(temp != 0)
            {/*si llegaron caracteres*/
                numBytesRead += temp;
                if(buffer[numBytesRead-1] == '\r') //llego el ultimo caracter de la cadena?
                {
                    numBytesRead = 0; //reinicia el contador a 0
                    /*compara si es la cadena deseada*/
                    if(memcmp(buffer, "toggle\r", sizeof("toggle\r")-1) == 0)
                    {/*invierte el led en RA1*/
                        Gpios_TogglePin(GPIOS_PORTA, 1);
                    }
                }
            }
        }
    }
}

void interrupt low_isr( void )
{
    /*es necesario llamar esta funcion en este vector de interrupcion*/
    UsbCDC_Task();
}
