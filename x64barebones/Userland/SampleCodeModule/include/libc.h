#ifndef LIB_C_H
#define LIB_C_H

int strlen(const char * s);
int strcmp(const char * s1, const char * s2);
int putString(char *c);
char getChar();
int printf(const char * format, ...);
char ** substrings(char * str, char delim, int * amountOfSubstrings);

#endif
