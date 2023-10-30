#include <commands.h>

void time(Cursor * cursor){
    uint8_t * currentTime;
    uint32_t length;
    call_get_time(&currentTime);

    call_write(currentTime, cursor->x, cursor->y, cursor->scale, &length);
}

