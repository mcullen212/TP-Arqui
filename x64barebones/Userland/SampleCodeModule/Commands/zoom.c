#include <commands.h>

#define MAX_ZOOM 3
#define MIN_ZOOM 1

void zoomIn(){
    int currentScale;
    call_c_get_scale(&currentScale);
    if(currentScale < MAX_ZOOM){
        call_c_set_scale(currentScale+1);
        clear();
        return;
    }
    printf("Already at max zoom.\n");
}

void zoomOut(){
    int currentScale;
    call_c_get_scale(&currentScale);
    if(currentScale > MIN_ZOOM){
        call_c_set_scale(currentScale-1);
        clear();
        return;
    }
    printf("Already at min zoom.\n");
}