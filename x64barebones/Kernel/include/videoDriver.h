#ifndef VIDEO_DRIVER_H
#define VIDEO_DRIVER_H

#include <stdint.h>

enum Hex32Colors {
    COLOR_BLACK     = 0x000000,
    COLOR_WHITE     = 0xFFFFFF,
    COLOR_RED       = 0xFF0000,
    COLOR_GREEN     = 0x00FF00,
    COLOR_BLUE      = 0x0000FF,
    COLOR_YELLOW    = 0xFFFF00,
    COLOR_MAGENTA   = 0xFF00FF,
    COLOR_CYAN      = 0x00FFFF,
    COLOR_GRAY      = 0x808080,
    COLOR_LIGHT_GRAY = 0xC0C0C0,
    COLOR_DARK_GRAY  = 0x404040,
};


void drawChar(uint8_t letter, uint32_t hexColor, uint64_t x, uint64_t y, uint32_t scale);

void deleteChar(uint32_t hexColor, uint64_t x, uint64_t y, uint32_t scale);

#endif
