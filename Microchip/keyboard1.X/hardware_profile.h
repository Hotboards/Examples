/* 
Define en este archivo las diferentes opciones de configuracion existentes en tus drivers de bajo
nivel dentro de la carpeta "bsp"
 */
#ifndef __HARDWARE_PROFILE_H__
#define	__HARDWARE_PROFILE_H__

    #define BSP_CLOCK           48000000

    #define KEYBOARD_ROWS        4

    #define KEYBOARD_R0_P        GPIOS_PORTD
    #define KEYBOARD_R0_B        3

    #define KEYBOARD_R1_P        GPIOS_PORTD
    #define KEYBOARD_R1_B        2

    #define KEYBOARD_R2_P        GPIOS_PORTD
    #define KEYBOARD_R2_B        1

    #define KEYBOARD_R3_P        GPIOS_PORTD
    #define KEYBOARD_R3_B        0

    #define KEYBOARD_COLUMNS     4

    #define KEYBOARD_C0_P        GPIOS_PORTC
    #define KEYBOARD_C0_B        2

    #define KEYBOARD_C1_P        GPIOS_PORTC
    #define KEYBOARD_C1_B        1

    #define KEYBOARD_C2_P        GPIOS_PORTC
    #define KEYBOARD_C2_B        0

    #define KEYBOARD_C3_P        GPIOS_PORTE
    #define KEYBOARD_C3_B        2

#endif	
