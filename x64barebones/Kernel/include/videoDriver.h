#ifndef VIDEO_DRIVER_H
#define VIDEO_DRIVER_H

#include <stdint.h>

// void drawChar(uint8_t letter, uint64_t x, uint64_t y, uint32_t scale);

// void deleteChar(uint64_t x, uint64_t y, uint32_t scale);

// void drawString(uint8_t * string, uint64_t x, uint64_t y, uint32_t scale, uint32_t * length);

void setColor(uint32_t text, uint32_t background);

void drawCharOnCursor(uint8_t character);

void deleteCharOnCursor();

void drawStringOnCursor(uint8_t * string, uint32_t * length);

#endif
