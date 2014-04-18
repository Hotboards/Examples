/*------------------------------------------------------------------------------
 * Las siguientes directivas pragmas son las que están programadas por defaul
 * en la tarjeta pepper-8m, aunque se activaran en este código, por seguridad
 * el programa HIDBootloader.exe no te dejara grabarlas en el microcontrolador
 * ya que el programa bootloader podría llegar a dañarse.
 * En caso de que la aplicación requiera activarlas deberan descomentarse
 * modificarse con las opciones deseadas, entrar al programa HIDBootloader.exe
 * y en el menú Program->Settings, activar la opción de "Config Bits" y
 * descargar el programa en la memoria del micro.
 * La única directiva pragma sin comentar es la de XINST=OFF, solamente para
 * qué C18 te permita compilar tu programa
 -----------------------------------------------------------------------------*/
#pragma config XINST = OFF          //Extended instruction set disabled
/*#pragma config WDTEN = OFF        //WDT disabled (enabled by SWDTEN bit)
#pragma config PLLDIV = 5           //Divide by 3 (12 MHz oscillator input)
#pragma config STVREN = ON          //stack overflow/underflow reset enabled
#pragma config CPUDIV = OSC1        //No CPU system clock divide
#pragma config CP0 = OFF            //Program memory is not code-protected
#pragma config OSC = HSPLL          //HS oscillator, PLL enabled, HSPLL used by USB
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
*/

/*------------------------------------------------------------------------------
 * La siguiente sección declara los vectores reubicados de tus interrupciónes
 * NO es necesario que modifiques esta seccion de codigo
 -----------------------------------------------------------------------------*/
#define REMAPPED_RESET_VECTOR_ADDRESS			0x1000
#define REMAPPED_HIGH_INTERRUPT_VECTOR_ADDRESS          0x1008
#define REMAPPED_LOW_INTERRUPT_VECTOR_ADDRESS           0x1018

void YourHighPriorityISRCode(void);
void YourLowPriorityISRCode(void);

#if !defined(NO_BOOT)
extern void _startup (void);        // See c018i.c in your C18 compiler dir
#pragma code REMAPPED_RESET_VECTOR = REMAPPED_RESET_VECTOR_ADDRESS
void _reset (void)
{
    _asm goto _startup _endasm
}

#pragma code REMAPPED_HIGH_INTERRUPT_VECTOR = REMAPPED_HIGH_INTERRUPT_VECTOR_ADDRESS
void Remapped_High_ISR (void)
{
     _asm goto YourHighPriorityISRCode _endasm
}
#pragma code REMAPPED_LOW_INTERRUPT_VECTOR = REMAPPED_LOW_INTERRUPT_VECTOR_ADDRESS
void Remapped_Low_ISR (void)
{
     _asm goto YourLowPriorityISRCode _endasm
}
#endif

#pragma code HIGH_INTERRUPT_VECTOR = 0x08
void High_ISR (void)
{
#if !defined(NO_BOOT)
    _asm goto REMAPPED_HIGH_INTERRUPT_VECTOR_ADDRESS _endasm
#else
    _asm goto YourLowPriorityISRCode _endasm
#endif
}

#pragma code LOW_INTERRUPT_VECTOR = 0x18
void Low_ISR (void)
{
#if !defined(NO_BOOT)
    _asm goto REMAPPED_LOW_INTERRUPT_VECTOR_ADDRESS _endasm
#else
    _asm goto YourLowPriorityISRCode _endasm
#endif
}
#pragma code

