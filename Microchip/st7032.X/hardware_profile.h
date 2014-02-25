/*
Define en este archivo las diferentes opciones de configuracion existentes en tus drivers de bajo
nivel dentro de la carpeta "bsp"
 */
#ifndef __HARDWARE_PROFILE_H__
#define	__HARDWARE_PROFILE_H__

    #define ST7032_N_LCDS              1 /*su valor por defaul es cero*/

    #define ST7032_SPI0                SPI_PORT2  /*puerto spi*/
    #define ST7032_SS_P0               GPIOS_PORTE /*puerto*/
    #define ST7032_SS_B0               1            /*pin*/
    #define ST7032_RST_P0              GPIOS_PORTE /*puerto*/
    #define ST7032_RST_B0              0            /*pin*/
    #define ST7032_RS_P0               GPIOS_PORTA /*puerto*/
    #define ST7032_RS_B0               3            /*pin*/

#endif
