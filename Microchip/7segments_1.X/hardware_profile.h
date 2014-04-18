/* 
Define en este archivo las diferentes opciones de configuracion existentes en tus drivers de bajo
nivel dentro de la carpeta "bsp"
 */
#ifndef __HARDWARE_PROFILE_H__
#define	__HARDWARE_PROFILE_H__

    #define _7SEGMENTS_DIGI_N                   4       /*4 digitos*/
    #define _7SEGMENTS_MODE                     1       /*anodo comun*/
    #define _7SEGMENTS_PORT                     GPIOS_PORTB /*puerto b como bus de datos*/
    /*pines que controlan los comunes*/
    #define _7SEGMENTS_DIGI0_P                  GPIOS_PORTD /*primer display*/
    #define _7SEGMENTS_DIGI0_B                  7

    #define _7SEGMENTS_DIGI1_P                  GPIOS_PORTD /*segundo display*/
    #define _7SEGMENTS_DIGI1_B                  6

    #define _7SEGMENTS_DIGI2_P                  GPIOS_PORTD /*tercero display*/
    #define _7SEGMENTS_DIGI2_B                  5

    #define _7SEGMENTS_DIGI3_P                  GPIOS_PORTD /*cuarto display*/
    #define _7SEGMENTS_DIGI3_B                  4

#endif	
