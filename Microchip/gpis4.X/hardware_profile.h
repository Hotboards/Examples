/* 
Define en este archivo las diferentes opciones de configuracion existentes en tus drivers de bajo
nivel dentro de la carpeta "bsp"
 */
#ifndef __HARDWARE_PROFILE_H__
#define	__HARDWARE_PROFILE_H__

    #define BSP_CLOCK           48000000

    #define GPIS_N_INPUTS        3 //usaremos un boton

    #define GPIS_B0_P            GPIOS_PORTB
    #define GPIS_B0_B            5

    #define GPIS_B1_P            GPIOS_PORTB
    #define GPIS_B1_B            6

    #define GPIS_B2_P            GPIOS_PORTB
    #define GPIS_B2_B            7

#endif	
