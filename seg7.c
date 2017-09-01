// Author : AmirrezaFiroozi
// License : GPLv3 
// For License information refer to the file that is in the same directory you've cloned. 
#include "seg7.h"

const char _Display[10] = { 0x3F , 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F} ; 
char _dp_state[4] = {0,0,0,0} ; // We need DotPoint state to tell seg_put function (not) to activate DotPoint 
// 1 means DotPoint is on. 0 means DotPoint is off.
    void seg_put(const char PORT,char CorA,char number)
    {
        // PORT is the port the segment is connected to 
        // CorA accepts two numbers : 1 for Common Cathode, 0 for Common Anode
        // Number is the number you wish segment to display, the number can be from 0 - 9 ;
       if (CorA)
       {
        switch (PORT)
        {
            case 'A':
                PORTA = _Display[number];
                if (_dp_state[0]) {PORTA.7 = 1;}
                else if(!_dp_state[0]) {PORTA.7 = 0;}
                break;
            case 'B':
                PORTB = _Display[number];
                if (_dp_state[1]) {PORTB.7 = 1;}
                else if(!_dp_state[1]) {PORTB.7 = 0;}
                break;
            case 'C':
                PORTC = _Display[number];
                if (_dp_state[2]) {PORTC.7 = 1;}
                else if(!_dp_state[2]) {PORTC.7 = 0;}
                break;
            case 'D':
                PORTD = _Display[number];
                if (_dp_state[3]) {PORTD.7 = 1;}
                else if(!_dp_state[3]) {PORTD.7 = 0;}
                break;
            
        }
       }
       else if (!CorA)
        {
                
            switch (PORT)
                {
                    case 'A':
                        PORTA = ~_Display[number];
                        if (_dp_state[0]) {PORTA.7 = 0;}
                        else if(!_dp_state[0]) {PORTA.7 = 1;}
                        break ;
                        // Since our _Display array is for Common Cathode 7 segment 
                        // If we want to use the array on Common Anode 7 segment
                        // We will need to NOT the numbers ( to make 1s 0s and to make 0s 1s )
                    case 'B':
                        PORTB = ~_Display[number];
                        if (_dp_state[1]) {PORTB.7 = 0;}
                        else if(!_dp_state[1]) {PORTB.7 = 1;}
                        break;
                    case 'C':
                        PORTC = ~_Display[number];
                        if (_dp_state[2]) {PORTC.7 = 0;}
                        else if(!_dp_state[2]) {PORTC.7 = 1;}
                        break;
                    case 'D':
                        PORTD = ~_Display[number];
                        if (_dp_state[3]) {PORTD.7 = 0;}
                        else if(!_dp_state[3]) {PORTD.7 = 1;}
                        break;
                       
                }
            
        }
    }

    void seg_dp_on(const char PORT,char CorA )
    //PORT is the port the segment is connected to 
    //CorA accepts either 0 for Common Anode  or 1 for Common Cathode
    {
        if (CorA)
        {
            switch (PORT)
            {
                case 'A':
                    PORTA.7 = 1 ; _dp_state[0] = 1 ; break ;
                    // We can adjust DotPoint state By setting PORTX.7, 1 or 0 
                    // The array _dp_state will be used in order to prevent state from resetting each time 
                    // that the function seg_put is used 
                case 'B':
                    PORTB.7 = 1 ; _dp_state[1] = 1 ; break ;
                case 'C':                      
                    PORTC.7 = 1 ; _dp_state[2] = 1 ; break ; 
                case 'D':
                    PORTD.7 = 1 ; _dp_state[3] = 1 ; break ; 
            }
        }
        if (!CorA)
        {
            switch (PORT)
            {
                case 'A':
                    PORTA.7 = 0 ; _dp_state[0] = 1 ; break ;
                case 'B':
                    PORTB.7 = 0 ; _dp_state[1] = 1 ; break ; 
                case 'C':
                    PORTC.7 = 0 ; _dp_state[2] = 1 ; break ; 
                case 'D' :
                    PORTD.7 = 0 ; _dp_state[3] = 1 ; break ;
            }
        }
    }      
    void seg_dp_off(const char PORT,char CorA )
    {
        if (CorA)
        {
            switch (PORT)
            {
                case 'A':
                    PORTA.7 = 0 ; _dp_state[0] = 0 ; break ;
                    // DotPoint is always connected to PORTX.7 so we can turn it on/off immediately by setting PORTX.7 , 1 or 0
                    // _dp_state is useful because we can tell the function seg_put to turn DP on/off 
                case 'B':
                    PORTB.7 = 0 ; _dp_state[1] = 0 ; break ;
                case 'C':
                    PORTC.7 = 0 ; _dp_state[2] = 0 ; break ; 
                case 'D':
                    PORTD.7 = 0 ; _dp_state[3] = 0 ; break ; 
            }
        }
        if (!CorA)
        {
            switch (PORT)
            {
                case 'A':
                    PORTA.7 = 1 ; _dp_state[0] = 0 ; break ;
                case 'B':
                    PORTB.7 = 1 ; _dp_state[1] = 0 ; break ; 
                case 'C':
                    PORTC.7 = 1 ; _dp_state[2] = 0 ; break ; 
                case 'D' :
                    PORTD.7 = 1 ; _dp_state[3] = 0 ; break ;
            }
        }
    }
    char get_dp_state(const char PORT)
    {  
        // In some cases it is necessary that we know weather DotPoint is turned on or off
        // So we simply return the state 
        switch (PORT)
        {
            case 'A':
                return _dp_state[0]; break ;
            case 'B':
                return _dp_state[1]; break ;
            case 'C':
                return _dp_state[2]; break ;
            case 'D':
                return _dp_state[3]; break ;
        }
         
    }
