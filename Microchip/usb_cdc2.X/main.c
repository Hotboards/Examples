/*
 * simple ejemplo de emulacion del puerto serial atravez del usb,
 * solo conecta tu pepper-8m al puerto usb, carga el programa y habre
 * tu terminal serial (tera term) a una velocidad 9600, 8bits, no flow control
 * escribe la letra 't' miniscula en la terminal y observa como el led de la
 * tarjeta parpadea.
 */

#include "fuses.h"
#include "usb_cdc/usb_cdc.h"
#include "system/system.h"
#include "gpios/gpios.h"

_U08 buffer[10];
_U08 i;

int main(void)
{
    System_EnablePLL(); /*micro a 48MHz, esto es obligatorio para el USB*/
    UsbCDC_Init(9600);  /*inicia emulacion serial a 9600 baudios*/
    Gpios_PinDirection(GPIOS_PORTA, 1, GPIOS_OUTPUT);/*pin RA1 como salida*/
    
    while(1)
    {
        if(UsbCDC_bEnumerated() == _TRUE) /*usb enumarado*/
        {
            i = UsbCDC_u8RxData( &buffer[0], 1 );/*recivimos datos por usb serial*/
            if((i > 0) && (buffer[0] == 't'))/*si se recivio un dato y este es la letra t*/
            {
                Gpios_TogglePin(GPIOS_PORTA, 1);/*invierto estado del led*/
            }
        }
    }
}

void interrupt low_isr( void )
{
    /*es necesario llamar esta funcion en este vector de interrupcion*/
    UsbCDC_Task();
}
