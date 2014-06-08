/*--------------------------------------------------------------------------------------------------
 * Las siguientes directivas pragmas son las que están programadas por default en la tarjeta pepper-8m.
 * NO SE DEBEN ALTERAR. Haserlo podria provocar el malfuncionamieto de la tarjeta y el posible daño
 * del Bootloader, ocasionando que no sea posible programar de nuevo la tarjeta por medio de la
 * aplicacion HIDBootloader. Esto tiene solucion programando de nuevo la tarjeta con un Pickit3.
 * Consultar la practica "Restaurando el bootloader de la Pepper" https://github.com/Hotboards/CodeBank8/wiki
 * AL MODIFICAR ESTE ARCHIVO SE PIERDE TODA GARANTIA INCLUIDA CON LA TARJETA PEPPER-8M. HOTBOARDS NO
 * SE RESPONSABILIZA POR LAS POSIBLES MODIFICACIONES REALIZADAS POR EL USUARIO A ESTE ARCHIVO.
 -------------------------------------------------------------------------------------------------*/
#ifndef __FUSES_H__
#define	__FUSES_H__

#ifdef	__cplusplus
extern "C" {
#endif

    #pragma config XINST = OFF          //Extended instruction set disabled
    #pragma config WDTEN = OFF          //WDT disabled (enabled by SWDTEN bit)
    #pragma config PLLDIV = 3           //NO ALTERAR: Divide by 3 (12 MHz oscillator input)
    #pragma config STVREN = ON          //stack overflow/underflow reset enabled
    #pragma config CPUDIV = OSC1        //NO ALTERAR: No CPU system clock divide
    #pragma config CP0 = OFF            //Program memory is not code-protected
    #pragma config OSC = HSPLL          //NO ALTERAR: HS oscillator, PLL enabled, HSPLL used by USB
    #pragma config T1DIG = OFF          //Sec Osc clock source may not be selected, unless T1OSCEN = 1
    #pragma config LPT1OSC = OFF        //high power Timer1 mode
    #pragma config FCMEN = OFF          //Fail-Safe Clock Monitor disabled
    #pragma config IESO = OFF           //Two-Speed Start-up disabled
    #pragma config WDTPS = 32768        //1:32768
    #pragma config DSWDTOSC = INTOSCREF //DSWDT uses INTOSC/INTRC as clock
    #pragma config RTCOSC = T1OSCREF    //RTCC uses T1OSC/T1CKI as clock
    #pragma config DSBOREN = OFF        //Zero-Power BOR disabled in Deep Sleep
    #pragma config DSWDTEN = OFF        //Disabled
    #pragma config DSWDTPS = 8192       //1:8,192 (8.5 seconds)
    #pragma config IOL1WAY = OFF        //IOLOCK bit can be set and cleared
    #pragma config MSSP7B_EN = MSK7     //7 Bit address masking
    #pragma config WPFP = PAGE_1        //Write Protect Program Flash Page 0
    #pragma config WPEND = PAGE_0       //Start protection at page 0
    #pragma config WPCFG = OFF          //Write/Erase last page protect Disabled
    #pragma config WPDIS = OFF          //WPFP[5:0], WPEND, and WPCFG bits ignored

#ifdef	__cplusplus
}
#endif

#endif	/* __FUSES_H__ */
