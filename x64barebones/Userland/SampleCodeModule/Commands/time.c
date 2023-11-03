#include <commands.h>

void time(){
    uint8_t * currentTime;
    uint32_t length;
    call_get_time(&currentTime);

    printf(currentTime);
    printf("\n");
    return; 
}

void registers(){

}

void div0(){

}

void invalidop(){}
