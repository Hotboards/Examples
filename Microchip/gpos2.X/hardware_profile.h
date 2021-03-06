/* 
Define en este archivo las diferentes opciones de configuracion existentes en tus drivers de bajo
nivel dentro de la carpeta "bsp"
 */
#ifndef __HARDWARE_PROFILE_H__
#define	__HARDWARE_PROFILE_H__

    #define BSP_CLOCK           48000000

    #define GPIS_N_INPUTS        1

   #define GPIS_B0_P            GPIOS_PORTA
   #define GPIS_B0_B            0

   #define GPOS_N_PINS          1

   #define GPOS_P0_P            GPIOS_PORTA
   #define GPOS_P0_B            1

#endif	
