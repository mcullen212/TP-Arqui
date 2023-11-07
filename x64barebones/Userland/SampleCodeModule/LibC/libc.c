#include <libc.h>
#include <syscallFunctions.h>
#include <stdarg.h>

#define BUFFER_DIM 20

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
        if(s[i] == '\t') {
            i+=4;
        }
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

static int readFromKeyboard(char * buffer) {
    int i=0;
    char c;
    while (c != ' ' && c != '\t' && c != '\n' && i < BUFFER_DIM) {
        c = getChar();
        buffer[i++] = c;
    }
    return i;
}

static int intToString(int num, char *str) {
    int i = 0, j=0;
    char isNegative = 0;
    char aux[10]; 

    // if negative flag to add sign
    if (num < 0) {
        isNegative = 1;
        num = -num;
    }

    if (num == 0) {
        str[i] = '0';
        i++;
    } 

    while (num != 0) {
        aux[j] = (num % 10) + '0';
        num = num / 10;
        j++;
    }

    if (isNegative) {
        str[i] = '-';
        i++;
    }

    for (j = j - 1; j >= 0; j--) {
        str[i] = aux[j];
        i++;
    }
    str[i] = '\0';

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

static int stringToInt(char * num){
    char isNegative = 0;
    int i = 0;
    int res = 0;

    if(num[0] == '-'){
        isNegative = 1;
        i++;
    }

    while(num[i] != '\0'){
        res = res*10 + num[i] - '0';
        i++;
    }
    
    if(isNegative){
        res = -res;
    }
    
    return res;
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

char readChar(int * readBytes) {
    uint8_t buffer;
    call_read(&buffer, 1, (uint32_t *) readBytes);
    return buffer;
}

int randNbr(int fromIncluded, int toIncluded) {
    unsigned long long currentTicks;
    call_get_ticks(&currentTicks);
    return (fromIncluded + (currentTicks % (toIncluded)));
}

void scanf(const char * format, ...) {
    va_list variables;

    va_start(variables, format);

    char str[DIM];
    char buffer[BUFFER_DIM];
    int index = 0, fmtPos = 0;

     while(format[fmtPos] != '\0'){
        if(format[fmtPos] == '%'){
            printf(str);
            fmtPos++;
            switch(format[fmtPos]){
                case 'd': //int
                    readFromKeyboard(buffer);
                    int * number;
                    number = va_arg(variables, int*);
                    *number = stringToInt(buffer);
                    break;
                case 's': //string
                    readFromKeyboard(buffer);
                    char ** string;
                    string = va_arg(variables, char**);
                    *string = buffer;
                    break;
                default:
                    break;
            }
            fmtPos++;
        }else{
            str[index] = format[fmtPos++];
            index++;
        }
    }
}
