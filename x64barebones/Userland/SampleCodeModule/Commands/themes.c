#include <themes.h>
#include <libc.h>
#include <syscallFunctions.h>

static enum Hex32Colors {
    COLOR_BLACK     = 0x000000,
    COLOR_WHITE     = 0xFFFFFF,
    COLOR_RED       = 0xFF0000,
    COLOR_GREEN     = 0x00FF00,
    COLOR_BLUE      = 0x0000FF,
    COLOR_YELLOW    = 0xB0CA07,
    COLOR_MAGENTA   = 0xFF00FF,
    COLOR_CYAN      = 0x00FFFF,
    COLOR_GRAY      = 0x808080,
    COLOR_LIGHT_GRAY = 0xC0C0C0,
    COLOR_DARK_GRAY  = 0x404040,
    COLOR_ORANGE    = 0xFFA500,
    COLOR_PURPLE    = 0x800080,
    COLOR_PINK      = 0xFFC0CB,
    COLOR_BROWN     = 0xA52A2A,
    COLOR_LIME_GREEN = 0x32CD32,
    COLOR_TEAL      = 0x008080,
    COLOR_GOLD      = 0xFFD700
};

static enum Hex32Colors themesShell[][2] = { // {backgroundColor, fontColor}
    {COLOR_BLACK, COLOR_WHITE},
    {COLOR_BLACK,COLOR_YELLOW},
    {COLOR_BLACK,COLOR_CYAN},
    {COLOR_WHITE,COLOR_BLACK},
    {COLOR_WHITE,COLOR_BLUE},
    {COLOR_BLUE,COLOR_YELLOW},
    {COLOR_BLUE,COLOR_WHITE},
    {COLOR_WHITE,COLOR_RED}
};


void theme(){
    printf("Please select a theme:\n");
    printf ("0. Default\n");
    printf("1. White on Black\n");
    printf("2. Yellow on Black\n");
    printf("3. Cyan on Black\n");
    printf("4. Black on White\n");
    printf("5. Blue on White\n");
    printf("6. BOCA\n");
    printf("7. White on Blue\n");
    printf("8. RIVER\n");
    char c;
    do {
        c = getChar();
        switch(c){
            case '0':
                defaultTheme();
                break;
            case '1':
                call_set_theme(themesShell[0]);
                break;
            case '2':
                call_set_theme(themesShell[1]);
                break;
            case '3':
                call_set_theme(themesShell[2]);
                break;
            case '4':
                call_set_theme(themesShell[3]);
                break;
            case '5':
                call_set_theme(themesShell[4]);
                break;
            case '6':
                call_set_theme(themesShell[5]);
                break;
            case '7':
                call_set_theme(themesShell[6]);
                break;
            case '8':
                call_set_theme(themesShell[7]);
                break;
            default:
                printf("Invalid theme\nPlease enter: 1, 2, 3, 4, 5 or 6\n");
                printf("Press ESC to exit\n");
                break;
        }
    } while ( c < '0' && c > '8' && c != 27);
    call_clear_screen();
}

void defaultTheme(){
    call_set_theme(themesShell[0]);
}

void setTheme(int theme){
    call_set_theme(themesShell[theme]);
}