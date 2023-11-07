#ifndef LIB_C_H
#define LIB_C_H

#define DIM 610

int strlen(const char * s);
int strcmp(const char * s1, const char * s2);
int putString(char *c);
char getChar();
int printf(const char * format, ...);
char readChar(int * readBytes);
int rand(int fromIncluded, int toIncluded);

#endif
