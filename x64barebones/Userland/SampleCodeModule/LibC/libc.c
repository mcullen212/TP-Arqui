#include <libc.h>
#include <syscallFunctions.h>
#include<stdarg.h>

int strcmp(const char * s1, const char * s2) {
    int i = 0;
    while(s1[i] != 0  && s2[i] != 0){
        if(s1[i] != s2[i]){
            return s1[i] - s2[i];
        }
        i++;
    }
    return s1[i]-s2[i];
}

int strlen(const char * s) {
    int i = 0;
    while(s[i] != '\0') {
        i++;
    }
    return i;
}

int putString(char * c) {
    uint32_t length;
    call_write((uint8_t *)c, &length);
    return length;
}

char getChar(){
    uint8_t c;
    uint32_t size = 0;
    while(size!=1){
        call_read(&c, 1, &size);
    }
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

int printf(const char * format, ...){ 
    va_list variables;

    va_start(variables, format);

    char str[DIM];
    int index = 0, fmtPos = 0;

    while(format[fmtPos] != '\0'){
        if(format[fmtPos] == '%'){
            fmtPos++;
            switch(format[fmtPos]){
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
            fmtPos++;
        }else{
            str[index] = format[fmtPos++];
            index++;
        }
    }
    str[index] = '\0';
    va_end(variables);
    return putString(str);
}

char ** substrings(char * str, char delim, int * amountOfSubstrings){
    int i = 0; //index of str
    int j = 0; // index of result
    int k = 0; // index of result[j]
    char ** result;
    while(str[i] != '\0'){
        if(str[i] == delim){
            k = 0; // restart
            j++; //new term
        }else{
            result[j][k]=str[i];
            k++;
        }
        i++;
    }
    *amountOfSubstrings = j;
    return result;
}
