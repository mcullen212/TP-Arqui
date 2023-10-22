#ifndef VIDEO_DRIVER_H
#define VIDEO_DRIVER_H

#include <stdint.h>

enum Hex64Colors {
    COLOR_BLACK     = 0x0000000000000000,
    COLOR_WHITE     = 0xFFFFFFFFFFFFFFFF,
    COLOR_RED       = 0xFF00000000000000,
    COLOR_GREEN     = 0x00FF000000000000,
    COLOR_BLUE      = 0x0000FF0000000000,
    COLOR_YELLOW    = 0xFFFF00FFFF000000,
    COLOR_MAGENTA   = 0xFF00FF0000FF0000,
    COLOR_CYAN      = 0x00FFFF000000FFFF,
    COLOR_GRAY      = 0x8080808080808080,
    COLOR_LIGHT_GRAY = 0xC0C0C0C0C0C0C0C0,
    COLOR_DARK_GRAY  = 0x4040404040404040,
};

void putPixel(uint32_t hexColor, uint64_t x, uint64_t y);

void printLetter(char num, uint32_t hexColor, uint64_t x, uint64_t y);

#endif