#line 1 "../../../CodeBank8/bsp/Microchip/delays/delays.c"
#line 1 "../../../CodeBank8/bsp/Microchip/delays/delays.c"

#line 19 "../../../CodeBank8/bsp/Microchip/delays/delays.c"
 
 
#line 1 "../../../CodeBank8/bsp/Microchip/delays/delays.h"

#line 19 "../../../CodeBank8/bsp/Microchip/delays/delays.h"
 

#line 22 "../../../CodeBank8/bsp/Microchip/delays/delays.h"


     
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
    

#line 25 "../../../CodeBank8/bsp/Microchip/delays/delays.h"
#line 26 "../../../CodeBank8/bsp/Microchip/delays/delays.h"
     

     
    
#line 33 "../../../CodeBank8/bsp/Microchip/delays/delays.h"
  
    


     
    
#line 41 "../../../CodeBank8/bsp/Microchip/delays/delays.h"
  
    
    
     
    
#line 50 "../../../CodeBank8/bsp/Microchip/delays/delays.h"
 
    void Delays_10us(_U32 us);

    
#line 58 "../../../CodeBank8/bsp/Microchip/delays/delays.h"
 
    void Delays_ms(_U16 ms);


#line 63 "../../../CodeBank8/bsp/Microchip/delays/delays.h"
 #line 21 "../../../CodeBank8/bsp/Microchip/delays/delays.c"


#line 1 "hardware_profile.h"

#line 4 "hardware_profile.h"
 

#line 7 "hardware_profile.h"



#line 11 "hardware_profile.h"
#line 23 "../../../CodeBank8/bsp/Microchip/delays/delays.c"



 

#line 29 "../../../CodeBank8/bsp/Microchip/delays/delays.c"
#line 30 "../../../CodeBank8/bsp/Microchip/delays/delays.c"
#line 32 "../../../CodeBank8/bsp/Microchip/delays/delays.c"
    


 


 
#line 40 "../../../CodeBank8/bsp/Microchip/delays/delays.c"

 


 
 
void Delays_10us( _U32 us )
{
    volatile _S32 s32Cycles;

    if((12000000 /4)  <= 2500000)  
    {
        
#line 56 "../../../CodeBank8/bsp/Microchip/delays/delays.c"
 
    }
    else
    {
        
#line 61 "../../../CodeBank8/bsp/Microchip/delays/delays.c"
 
        s32Cycles = (_S32)((12000000 /4) /100000) * us;
        
#line 64 "../../../CodeBank8/bsp/Microchip/delays/delays.c"
 
        s32Cycles -= (153 + 22);

        if (s32Cycles <= 45)
        {
             
        }
        else
        {
             
            while (s32Cycles>0)  
            {
                NOP();  
                s32Cycles -= 21;  
            }
        }
    }
}
 

 
void Delays_ms( _U16 ms )
{
    _S32 s32Cycles;

     
    s32Cycles = (_S32)((12000000 /4) /1000) * ms;
    
#line 92 "../../../CodeBank8/bsp/Microchip/delays/delays.c"
 
    s32Cycles -= (148 + 22);

    if (s32Cycles <= (170+25)) 
    {
        return;      
    }    
    else
    {
        while (s32Cycles > 0)  
        {
            NOP();               
            s32Cycles -= 22;     
        }
    }
}
 


 

#line 117 "../../../CodeBank8/bsp/Microchip/delays/delays.c"
 
