#ifndef LIB_C_H
#define LIB_C_H

#include <syscallFunctions.h>
#include<stdarg.h>

int strlen(const char * s);
int strcmp(const char * s1, const char * s2);
void putString(char *c, int length);
char getChar();
//int scanf(const char * format, ...);
int printf(const char * format, ...);

#endif
