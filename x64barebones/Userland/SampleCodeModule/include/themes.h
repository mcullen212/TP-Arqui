#ifndef THEMES_H
#define THEMES_H

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

enum Hex32Colors themesShell[][2] = { // {backgroundColor, fontColor}
    {COLOR_BLACK, COLOR_WHITE},
    {COLOR_BLACK,COLOR_YELLOW},
    {COLOR_BLACK,COLOR_CYAN},
    {COLOR_WHITE,COLOR_BLACK},
    {COLOR_WHITE,COLOR_BLUE},
    {COLOR_BLUE,COLOR_YELLOW}
};


#endif
