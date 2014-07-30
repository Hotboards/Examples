/* 
Define en este archivo las diferentes opciones de configuracion existentes en tus drivers de bajo
nivel dentro de la carpeta "bsp"
 */
#ifndef __HARDWARE_PROFILE_H__
#define	__HARDWARE_PROFILE_H__

    #define BSP_CLOCK                   48000000

    #define ONEWIRE_N_PORTS             1

    #define ONEWIRE_PORT_P0             GPIOS_PORTD
    #define ONEWIRE_PORT_B0             0

#endif	
