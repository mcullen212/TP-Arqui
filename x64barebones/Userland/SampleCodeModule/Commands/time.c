#include <commands.h>

void time(){
    uint8_t * currentTime;
    uint32_t length;
    call_get_time(&currentTime);

    call_write(currentTime, getCursorX(), getCursorY(), getCursorScale(), &length);
    cursorAction(ENTER);
}

