/* 
Define en este archivo las diferentes opciones de configuracion existentes en tus drivers de bajo
nivel dentro de la carpeta "bsp"
 */
#ifndef __HARDWARE_PROFILE_H__
#define	__HARDWARE_PROFILE_H__

    #define BSP_CLOCK           20000000

    #define TIMERS_BASE_TIME    10

    #define GPIS_N_INPUTS       1

    #define GPIS_B0_P           GPIOS_PORTA
    #define GPIS_B0_B           0

#endif	
