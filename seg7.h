#ifndef _SEG7_H
#define _SEG7_H
#include <stdio.h>
void seg_put(const char PORT,char CorA,char number);
void seg_dp_on(const char PORT,char CorA);
void seg_dp_off(const char PORT,char CorA);
char get_dp_state(const char PORT); 
#endif
