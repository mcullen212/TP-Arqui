#include <commands.h>

void time(Cursor * cursor){
    char * currentTime;
    call_get_time(&currentTime);

    call_write(currentTime, cursor->x, cursor->y, cursor->scale, LENGTH_TIME);
}

