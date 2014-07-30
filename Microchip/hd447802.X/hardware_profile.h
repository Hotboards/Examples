/* 
Define en este archivo las diferentes opciones de configuracion existentes en tus drivers de bajo
nivel dentro de la carpeta "bsp"
 */
#ifndef __HARDWARE_PROFILE_H__
#define	__HARDWARE_PROFILE_H__

    #define BSP_CLOCK                   48000000

    #define _6800_BUSLENGHT             4
    #define _6800_DATAPORT              GPIOS_PORTD
    #define _6800_E_P               	GPIOS_PORTC
    #define _6800_E_B               	6
    #define _6800_RW_P                  GPIOS_PORTC
    #define _6800_RW_B                  7
    #define _6800_RS_P                  GPIOS_PORTB
    #define _6800_RS_B                  7

    #define HD44780_ROWS                4
    #define HD44780_COLUMNS             20

#endif	
