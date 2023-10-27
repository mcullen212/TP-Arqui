#include <time.h>
#include <syscallFunctions.h>

char * time(){
    return call_get_time();
}