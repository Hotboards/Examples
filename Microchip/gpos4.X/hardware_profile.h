/* 
Define en este archivo las diferentes opciones de configuracion existentes en tus drivers de bajo
nivel dentro de la carpeta "bsp"
 */
#ifndef __HARDWARE_PROFILE_H__
#define	__HARDWARE_PROFILE_H__

    #define BSP_CLOCK           48000000

    #define GPOS_N_PINS          3

   #define GPOS_P0_P            GPIOS_PORTB
   #define GPOS_P0_B            0

   #define GPOS_P1_P            GPIOS_PORTB
   #define GPOS_P1_B            2

   #define GPOS_P2_P            GPIOS_PORTB
   #define GPOS_P2_B            4

#endif	
