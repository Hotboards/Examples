/*
 * simple ejemplo de emulacion del puerto serial atravez del usb,
 * solo conecta tu pepper-8m al puerto usb, carga el programa y habre
 * tu terminal serial (tera term) a una velocidad 9600, 8bits, no flow control
 * observaras la cadena enviada de manera continua.
 */
#include "fuses.h"
#include "usb_cdc/usb_cdc.h"
#include "system/system.h"

int main(void)
{
    System_EnablePLL(); /*micro a 48MHz, esto es obligatorio para el USB*/
    UsbCDC_Init(9600);  /*inicia emulacion serial a 9600 baudios*/
    
    while(1)
    {
        if(UsbCDC_bEnumerated() == _TRUE) /*usb enumarado*/
        {
            if(UsbCDC_bReady() == _TRUE)  /*usb libre para transmitir*/
            {
                /*mandamos cadena terminada en cero*/
                UsbCDC_SendString( "hola emulacion UART en USB\r\n");
            }
        }
    }
}

void interrupt low_isr( void )
{
    /*es necesario llamar esta funcion en este vector de interrupcion*/
    UsbCDC_Task();
}
