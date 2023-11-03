#include <commands.h>

void time(){
    uint8_t * currentTime;
    call_get_time(&currentTime);

    printf((char *) currentTime);
    printf("\n");
    return;
}

void div0(){

}

void invalidop(){}
