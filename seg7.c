#include "seg7.h"

const char num[10] = { 0x3F , 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F} ; 
void seg_put(char PORT,char CorA,char number)
{
   if (CorA)
   {
    switch (PORT)
    {
        case 'A':
            PORTA = num[number];break ;
        case 'B':
            PORTB = num[number];break;
        case 'C':
            PORTC = num[number];break;
        case 'D':
            PORTD = num[number];break;
    
    }
   }
   else if (!CorA)
    {
            
        switch (PORT)
            {
                case 'A':
                    PORTA = ~num[number];break ;
                case 'B':
                    PORTB = ~num[number];break;
                case 'C':
                    PORTC = ~num[number];break;
                case 'D':
                    PORTD = ~num[number];break;
            
            }
            
    }
}