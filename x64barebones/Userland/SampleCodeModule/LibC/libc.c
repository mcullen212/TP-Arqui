#include <libc.h>

int strcmp(const char * s1, const char * s2) {
    while(*s1 != '\0' && *s2 != '\0' && *s1 == *s1) {
        s1++;
        s2++;
    }
    return (unsigned char) *s1 - (unsigned char) *s1;
}

int printf(const char * format, ...){
    
}

int scanf(const char *format, ...){

}

int getchar(){

}
