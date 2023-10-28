#include <libc.h>

int strcmp(const char * s1, const char * s2) {
    while(*s1 != '\0' && *s2 != '\0' && *s1 == *s1) {
        s1++;
        s2++;
    }
    return (unsigned char) *s1 - (unsigned char) *s1;
}

int strlen(const char * s) {
    int i = 0;
    while(s[i] != '\0') {
        i++;
    }
    return i;
}

void putString(char *c, int length) {
    call_write(1,c, length); 
}

char getChar(){
    char c;
    call_read(1, (char *) &c, 1);
    return c;
}

static int intToString(int num, char *str){
    int i = 0;
    if(num < 0){
        str[i] = '-'; 
        i++;
        num = -num;
    }

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
    return i;
}

static int strConcat(char *str1, char *str2){
    int i = strlen(str1);
    int j = 0;
    while(str2[j] != '\0'){
        str1[i] = str2[j];
        i++;
        j++;
    }
    return i;
}

static int doubleToString(double num, char *str){
    int integerPart = (int) num;
    int decimalPart = (int) (num - integerPart)*1000;
    int length = intToString(integerPart,str);
    *(str+length) = '.';
    int i = intToString(decimalPart,str+integerPart+1);
    return length + i;
}

int printf(const char * format, ...){ //nose como accesder a los parametros ... pero se que se puede
    va_list variables;

    va_start(variables, format);

    char * str;
    int index = 0;

    while(*format != '\0'){
        if(*format == '%'){
            format++;
            switch(*format){
                case 'd': //int
                    index += intToString(va_arg(variables,int),str+index);
                    break;
                case 's': //string
                    index+=strConcat(str,va_arg(variables,char*));
                    break;
                // case 'f'://float tira un error SSE register return with SSE disabled no se como solucionarlo
                //     index += doubleToString(va_arg(variables,double), str);
                //     break;
                default:
                    break;
            }
            format++;
        }else{
            str[index] = *format;
            format++;
            index++;
        }
    }
    putString(str, index);
    va_end(variables);
    return index;
}

//guarda valor en el paramentro pasado por referencia
// int scanf(const char *format, ...){
//     while(*format != '\0'){
//         if(*format == '%'){
//             format++;
//             switch(*format){
//                //en proceso 
//             }
//         }
//     }
//     return 0;
// }
