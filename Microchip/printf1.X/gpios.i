#line 1 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
#line 1 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"

#line 19 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
 
 
#line 1 "H:/CodeBank8/bsp/Microchip/gpios/gpios.h"

#line 19 "H:/CodeBank8/bsp/Microchip/gpios/gpios.h"
 

#line 22 "H:/CodeBank8/bsp/Microchip/gpios/gpios.h"


     
#line 1 "../../../CodeBank8/types.h"

#line 17 "../../../CodeBank8/types.h"
 

#line 20 "../../../CodeBank8/types.h"

    
    
#line 24 "../../../CodeBank8/types.h"
     
    typedef unsigned char           _U08;
    typedef unsigned short          _U16;
    typedef unsigned long           _U32;
    typedef signed char             _S08;
    typedef signed short            _S16;
    typedef signed long             _S32;
    typedef unsigned char           _BOOL;
    typedef signed char *           _STRING;
    
    
#line 37 "../../../CodeBank8/types.h"
 
    typedef union
    {
        _U08 u8Flags;
        struct
        {
            unsigned b0  :1;
            unsigned b1  :1;
            unsigned b2  :1;
            unsigned b3  :1;
            unsigned b4  :1;
            unsigned b5  :1;
            unsigned b6  :1;
            unsigned b7  :1;
        }_sBITS;
    }_uFLAGS;

    
#line 57 "../../../CodeBank8/types.h"
 
    typedef union
    {
        _U32 u32Long;
        _U16 u16Short[2];
        _U08 u8Byte[4];
    }_u4BYTES;

    
#line 68 "../../../CodeBank8/types.h"
 
    typedef union
    {
        _U16 u16Short;
        _U08 u8Byte[2];
    }_u2BYTES;

    
#line 78 "../../../CodeBank8/types.h"
 
    typedef struct
    {
        _U08 u8PrevState;
        _U08 u8NextState;
        _U08 u8ActualState;
        _U08 u8ErrorState;
    }_sSM;
    
    
#line 90 "../../../CodeBank8/types.h"
  
    typedef struct
    {
        _U08 u8Hour;
        _U08 u8Minutes;
        _U08 u8Seconds;
    }_sTIME;
    
    
#line 101 "../../../CodeBank8/types.h"
  
    typedef struct
    {
        _U08 u8Day;
        _U08 u8Dayofweek;
        _U08 u8Month;
        _U08 u8Year;
    }_sDATE;

    
#line 112 "../../../CodeBank8/types.h"
 
#line 114 "../../../CodeBank8/types.h"
#line 115 "../../../CodeBank8/types.h"
#line 116 "../../../CodeBank8/types.h"
#line 117 "../../../CodeBank8/types.h"

    
#line 120 "../../../CodeBank8/types.h"
 
#line 122 "../../../CodeBank8/types.h"
#line 123 "../../../CodeBank8/types.h"
#line 124 "../../../CodeBank8/types.h"
#line 125 "../../../CodeBank8/types.h"

    
#line 128 "../../../CodeBank8/types.h"
 
#line 130 "../../../CodeBank8/types.h"
#line 131 "../../../CodeBank8/types.h"
#line 132 "../../../CodeBank8/types.h"
#line 133 "../../../CodeBank8/types.h"

    
#line 136 "../../../CodeBank8/types.h"
 
#line 138 "../../../CodeBank8/types.h"
#line 139 "../../../CodeBank8/types.h"

    
#line 142 "../../../CodeBank8/types.h"
 
#line 144 "../../../CodeBank8/types.h"
#line 145 "../../../CodeBank8/types.h"

    
#line 148 "../../../CodeBank8/types.h"
 
#line 150 "../../../CodeBank8/types.h"
#line 151 "../../../CodeBank8/types.h"

    
    
#line 155 "../../../CodeBank8/types.h"
 
#line 157 "../../../CodeBank8/types.h"
#line 158 "../../../CodeBank8/types.h"
    
    
#line 161 "../../../CodeBank8/types.h"
 
#line 163 "../../../CodeBank8/types.h"
#line 164 "../../../CodeBank8/types.h"
    
    
#line 167 "../../../CodeBank8/types.h"
 
#line 169 "../../../CodeBank8/types.h"
#line 170 "../../../CodeBank8/types.h"
    

#line 25 "H:/CodeBank8/bsp/Microchip/gpios/gpios.h"
#line 26 "H:/CodeBank8/bsp/Microchip/gpios/gpios.h"
     

     
    
#line 32 "H:/CodeBank8/bsp/Microchip/gpios/gpios.h"
 
#line 34 "H:/CodeBank8/bsp/Microchip/gpios/gpios.h"
#line 35 "H:/CodeBank8/bsp/Microchip/gpios/gpios.h"

    
#line 39 "H:/CodeBank8/bsp/Microchip/gpios/gpios.h"
      
    typedef enum 
    {
        GPIOS_PORTA = 0, 
        GPIOS_PORTB, 
        GPIOS_PORTC,
        GPIOS_PORTD,
        GPIOS_PORTE,
        GPIOS_PORTF,
        GPIOS_PORTG
    }_eGPIOS_PORT;
    
     
    
#line 55 "H:/CodeBank8/bsp/Microchip/gpios/gpios.h"
  
    
    
     
    
#line 66 "H:/CodeBank8/bsp/Microchip/gpios/gpios.h"
 
    void Gpios_PinDirection(_eGPIOS_PORT ePort, _U08 u8Pin, _BOOL bDirection);

    
#line 76 "H:/CodeBank8/bsp/Microchip/gpios/gpios.h"
 
    void Gpios_WritePin(_eGPIOS_PORT ePort, _U08 u8Pin, _BOOL bValue);

    
#line 86 "H:/CodeBank8/bsp/Microchip/gpios/gpios.h"
 
    void Gpios_PullupPin(_eGPIOS_PORT ePort, _U08 u8Pin, _BOOL bValue);

    
#line 95 "H:/CodeBank8/bsp/Microchip/gpios/gpios.h"
   
    void Gpios_TogglePin(_eGPIOS_PORT ePort, _U08 u8Pin);

    
#line 104 "H:/CodeBank8/bsp/Microchip/gpios/gpios.h"
   
    _BOOL Gpios_bReadPin(_eGPIOS_PORT ePort, _U08 u8Pin);

    
#line 113 "H:/CodeBank8/bsp/Microchip/gpios/gpios.h"
 
    void Gpios_WritePort(_eGPIOS_PORT ePort, _U08 u8Value);

    
#line 121 "H:/CodeBank8/bsp/Microchip/gpios/gpios.h"
 
    _U08 Gpios_u8ReadPort(_eGPIOS_PORT ePort);

    
#line 130 "H:/CodeBank8/bsp/Microchip/gpios/gpios.h"
 
    void Gpios_WriteTris(_eGPIOS_PORT ePort, _U08 u8Value);

    
#line 138 "H:/CodeBank8/bsp/Microchip/gpios/gpios.h"
 
    _U08 Gpios_u8ReadTris(_eGPIOS_PORT ePort);

    
#line 146 "H:/CodeBank8/bsp/Microchip/gpios/gpios.h"
 
    void Gpios_SetPullups(_eGPIOS_PORT ePort, _U08 u8Value);

    
#line 154 "H:/CodeBank8/bsp/Microchip/gpios/gpios.h"
 
    _U08 Gpios_u8ReadPullups(_eGPIOS_PORT ePort);


#line 159 "H:/CodeBank8/bsp/Microchip/gpios/gpios.h"
 #line 21 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"




 


 
static volatile _U08 *const guap8Direction[] =
{
#line 32 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
#line 34 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
    (0),
#line 36 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
#line 37 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
#line 39 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
    (0),
#line 41 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
#line 42 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
#line 44 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
    (0),
#line 46 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
#line 47 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
#line 49 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
    (0),
#line 51 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
#line 52 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
#line 54 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
    (0),
#line 56 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
};  
static volatile _U08 *const guap8Input[]     =
{
#line 60 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
#line 62 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
    (0),
#line 64 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
#line 65 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
#line 67 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
    (0),
#line 69 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
#line 70 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
#line 72 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
    (0),
#line 74 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
#line 75 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
#line 77 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
    (0),
#line 79 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
#line 80 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
#line 82 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
    (0),
#line 84 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
};  
static volatile _U08 *const guap8Output[]    =
{
#line 88 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
#line 90 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
    (0),
#line 92 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
#line 93 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
#line 95 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
    (0),
#line 97 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
#line 98 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
#line 100 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
    (0),
#line 102 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
#line 103 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
#line 105 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
    (0),
#line 107 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
#line 108 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
#line 110 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
    (0),
#line 112 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
};   

 


 


 
 
void Gpios_PinDirection(_eGPIOS_PORT ePort, _U08 u8Pin, _BOOL bDirection)
{
    u8Pin &= (_U08)0x07;  
    bDirection &= (_BOOL)0x01;  
    
    if(0  == bDirection)
    { 
        ((*guap8Direction[(_U08)ePort]) &= ~(_U08)((_U08)1<<(_U08)(u8Pin))) ;
    }
    else
    { 
        ((*guap8Direction[(_U08)ePort]) |= (_U08)((_U08)1<<(_U08)(u8Pin))) ;
    }
}
 

 
void Gpios_WritePin(_eGPIOS_PORT ePort, _U08 u8Pin, _BOOL bValue)
{
    u8Pin &= (_U08)0x07;  
    bValue &= (_BOOL)0x01;  
    
    if((_BOOL)1 == bValue)
    { 
        ((*guap8Output[(_U08)ePort]) |= (_U08)((_U08)1<<(_U08)(u8Pin))) ;
    }
    else
    { 
        ((*guap8Output[(_U08)ePort]) &= ~(_U08)((_U08)1<<(_U08)(u8Pin))) ;
    }
}
 

 
void Gpios_PullupPin(_eGPIOS_PORT ePort, _U08 u8Pin, _BOOL bValue)
{
    
#line 159 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
 
}
 

 
void Gpios_TogglePin(_eGPIOS_PORT ePort, _U08 u8Pin)
{
    u8Pin &= (_U08)0x07;  
    ((*guap8Output[(_U08)ePort]) ^= (_U08)((_U08)1<<(_U08)(u8Pin))) ;
}
 

 
_BOOL Gpios_bReadPin(_eGPIOS_PORT ePort, _U08 u8Pin)
{
    u8Pin &= (_U08)0x07;  
    return ((_BOOL)((*guap8Input[(_U08)ePort])>>(_U08)(u8Pin)) & ((_U08)1)) ;
}
 

 
void Gpios_WritePort(_eGPIOS_PORT ePort, _U08 u8Value)
{
    *guap8Output[(_U08)ePort] = u8Value;
}
 

 
_U08 Gpios_u8ReadPort(_eGPIOS_PORT ePort)
{
    return *guap8Input[(_U08)ePort];
}
 

 
void Gpios_WriteTris(_eGPIOS_PORT ePort, _U08 u8Value)
{
    *guap8Direction[(_U08)ePort] = u8Value;
}
 

 
_U08 Gpios_u8ReadTris(_eGPIOS_PORT ePort)
{
    return *guap8Direction[(_U08)ePort];
}
 

 
void Gpios_SetPullups(_eGPIOS_PORT ePort, _U08 u8Value)
{
    
#line 211 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
 
}
 

 
_U08 Gpios_u8ReadPullups(_eGPIOS_PORT ePort)
{
    
#line 219 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
 
    return 0x00;
}
 


 

#line 231 "H:/CodeBank8/bsp/Microchip/gpios/gpios.c"
 
