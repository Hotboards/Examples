/* 
Define en este archivo las diferentes opciones de configuracion existentes en tus drivers de bajo
nivel dentro de la carpeta "bsp"
 */
#ifndef __HARDWARE_PROFILE_H__
#define	__HARDWARE_PROFILE_H__

    #define EEPROM25XX_N_MEMORIES          1 /*su valor por defaul es cero*/

    #define EEPROM25XX_SPI0                SPI_PORT2  /*puerto spi*/
    #define EEPROM25XX_SS_P0               GPIOS_PORTE /*puerto*/
    #define EEPROM25XX_SS_B0               2            /*pin*/

#endif	
