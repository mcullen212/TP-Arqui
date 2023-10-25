#include <libc.h>

int strcmp(const char * s1, const char * s2) {
    while(*s1 != '\0' && *s2 != '\0' && *s1 == *s1) {
        s1++;
        s2++;
    }
    return (unsigned char) *s1 - (unsigned char) *s1;
}

//(unsigned int fd, const char *buf, size_t count)
// int putChar(char *c) {
//     call_write(1, c, 1);
// }
/*
static char *intToString(int num){
    char *str = malloc(11);
    int i = 0;
    if(num == 0){
        str[i] = '0';
        i++;
    }
    else{
        if(num < 0){
            str[i] = '-';
            i++;
            num = -num;
        }
        while(num != 0){
            str[i] = (num % 10) + '0';
            num = num / 10;
            i++;
        }
    }
    str[i] = '\0';
    return str;
}

static char *hexToString(int num){
    char *str = malloc(10);
    int i = 0;
    if(num == 0){
        str[i] = '0';
        i++;
    }
    else{
        while(num != 0){
            str[i] = (num % 10) + '0';
            num = num / 10;
            i++;
        }
    }
    str[i] = '\0';
    return str;
}

int printf(const char * format, ...){ //nose como accesder a los parametros ... pero se que se puede
    while(*format != '\0'){
        if(*format == '%'){
            format++;
            switch(*format){
                case 'd': //int
                    char * str = intToString(arg);
                    for(int i = 0; str!='\0'; i++)
                        putchar(str[i]);
                    free(str);
                    break;
                case 's': //string
                    for(int i = 0; arg!='\0'; i++)
                        putchar(arg[i]);
                    free(str);
                    break;
                case 'c'://char
                    putchar(arg);
                    break;
                case 'x'://hex
                    break;
                case 'o'://octal
                    break;
                case 'b'://binary
                    break;
                case 'f'://float
                    break;
                case 'p': //pointer
                    break;
                case '%'://percentage
                    break;
                default:
                    break;
            }
        }
        putchar(*format);
        format++;
    }
}

//guarda valor en el paramentro pasado por referencia
int scanf(const char *format, ...){
    while(*format != '\0'){
        if(*format == '%'){
            format++;
            switch(*format){
                case 'd': //int
                    break;
                case 's': //string
                    break;
                case 'c'://char
                    break;
                case 'x'://hex
                    break;
                case 'o'://octal
                    break;
                case 'b'://binary
                    break;
                case 'f'://float
                    break;
                case 'p': //pointer
                    break;
                case '%'://percentage
                    break;
                default:
                    break;
            }
        }
        putchar(*format);
        format++;
    }
} */

char getChar(){
    char c;
    call_read(0, &c, 1);
    return c;
}
