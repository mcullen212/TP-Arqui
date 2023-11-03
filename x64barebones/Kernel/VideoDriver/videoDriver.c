#include <videoDriver.h>
#include <fonts.h>
#include <cursor.h>

//font
#define WIDTH_FONT 8
#define HEIGHT_FONT 16
#define TAB_SIZE 4

//screen
#define LAST_X 1024
#define LAST_Y 768

static uint32_t characterColor = 0xFFFFFF; // default color white
static uint32_t backgroundColor = 0x000000; // default color black

//static void drawSquare(uint32_t hexColor, uint64_t x, uint64_t y, uint32_t scale);
static void drawSquareOnCursor(uint32_t hexColor, int x, int y);
static void clearTerminal();

struct vbe_mode_info_structure {
	uint16_t attributes;		// deprecated, only bit 7 should be of interest to you, and it indicates the mode supports a linear frame buffer.
	uint8_t window_a;			// deprecated
	uint8_t window_b;			// deprecated
	uint16_t granularity;		// deprecated; used while calculating bank numbers
	uint16_t window_size;
	uint16_t segment_a;
	uint16_t segment_b;
	uint32_t win_func_ptr;		// deprecated; used to switch banks from protected mode without returning to real mode
	uint16_t pitch;			// number of bytes per horizontal line
	uint16_t width;			// width in pixels
	uint16_t height;			// height in pixels
	uint8_t w_char;			// unused...
	uint8_t y_char;			// ...
	uint8_t planes;
	uint8_t bpp;			// bits per pixel in this mode
	uint8_t banks;			// deprecated; total number of banks in this mode
	uint8_t memory_model;
	uint8_t bank_size;		// deprecated; size of a bank, almost always 64 KB but may be 16 KB...
	uint8_t image_pages;
	uint8_t reserved0;

	uint8_t red_mask;
	uint8_t red_position;
	uint8_t green_mask;
	uint8_t green_position;
	uint8_t blue_mask;
	uint8_t blue_position;
	uint8_t reserved_mask;
	uint8_t reserved_position;
	uint8_t direct_color_attributes;

	uint32_t framebuffer;		// physical address of the linear frame buffer; write here to draw to the screen
	uint32_t off_screen_mem_off;
	uint16_t off_screen_mem_size;	// size of memory in the framebuffer but not being displayed on the screen
	uint8_t reserved1[206];
} __attribute__ ((packed));

typedef struct vbe_mode_info_structure * VBEInfoPtr;

static Cursor cursor;

void initializeCursor(int x, int y, int scale) {
    cursor.x = x;
    cursor.y = y;
    cursor.scale = scale;
}

uint32_t getCursorX() {
    return cursor.x;
}

uint32_t getCursorY() {
    return cursor.y;
}

uint32_t getCursorScale() {
    return cursor.scale;
}

void setCursorScale(int scale) {
    cursor.scale = scale;
}


static void moveRight() {
    if(cursor.x < (MAX_X - (WIDTH_FONT * cursor.scale))) {
        cursor.x += (WIDTH_FONT * cursor.scale);
        return;
    }

    cursor.x = MIN_X;
    if(cursor.y < MAX_Y){
        cursor.y += (HEIGHT_FONT * cursor.scale);
        return;
    }

    cursor.y = MIN_Y;
    clearTerminal();
}

static void moveLeft() {
    if(cursor.x == MIN_X && cursor.y == MIN_Y) {
        return;
    }
    if(cursor.x == MIN_X) {
        cursor.x = MAX_X-(cursor.scale * WIDTH_FONT);
        cursor.y -= (HEIGHT_FONT * cursor.scale);
        return;
    }
    cursor.x -= (WIDTH_FONT * cursor.scale);
}

static void moveDown() {
    if(cursor.y < MAX_Y){
        cursor.y += (HEIGHT_FONT * cursor.scale);
        cursor.x = MIN_X;
        return;
    }
    cursor.x = MIN_X;
    cursor.y = MIN_Y;
    clearTerminal();
}

static void moveTab() {
    for (int i = 0; i < TAB_SIZE; i++) {
        moveRight();
    }
}

void moveCursor(actionOfCursor action) {
    switch(action) {
        case WRITE :
            moveRight();
            break;
        case DELETE :
            moveLeft();
            break;
        case ENTER :
            moveDown();
            break;
        case TAB :
            moveTab();
            break;
        default :
            break;
    }
}

VBEInfoPtr VBE_mode_info = (VBEInfoPtr) 0x0000000000005C00;

static void putPixel(uint32_t hexColor, uint64_t x, uint64_t y) {
	//the location in memory where the graphics framebuffer is stored
    uint8_t * framebuffer = (uint8_t *) ((uint64_t) VBE_mode_info->framebuffer);

	// indicates where the pixel's color information should be stored
    uint64_t offset = (x * ((VBE_mode_info->bpp)/8)) + (y * VBE_mode_info->pitch);

	//setting color
    framebuffer[offset]     =  (hexColor) & 0xFF;  // blue components
    framebuffer[offset+1]   =  (hexColor >> 8) & 0xFF;  // green component
    framebuffer[offset+2]   =  (hexColor >> 16) & 0xFF; // rojo component
}

void drawCharOnCursor(uint8_t character) {
    unsigned char * bitMapChar = font8x16[character];
    int x0 = cursor.x, y0 = cursor.y;

    for (int i = 0; i < HEIGHT_FONT; i++) {
        for (int j =0; j < WIDTH_FONT; j++) {
            int bit = (bitMapChar[i] >> j) & 1;
            if (bit) {
                drawSquareOnCursor(characterColor, x0, y0);
            }
            x0 += cursor.scale;
        }
        x0 -= (WIDTH_FONT * cursor.scale);
        y0 += cursor.scale;
    }

    moveCursor(WRITE); // Moves cursor to next key position.
}

void deleteCharOnCursor() {
    moveCursor(DELETE); // Moves cursor to the key to be deleted

    int x0 = cursor.x, y0 = cursor.y;

    for(int i = 0; i < HEIGHT_FONT; i++) {
        for(int j = 0; j < WIDTH_FONT; j++) {
            drawSquareOnCursor(backgroundColor, x0, y0);
            x0 += cursor.scale;
        }
        x0-=(8 * cursor.scale);
        y0+= cursor.scale;
    }
}

void drawStringOnCursor(uint8_t * string, uint32_t * length) {
    int i = 0;

    while (string[i] != '\0') {
        if (string[i] == '\n') {
            moveCursor(ENTER);
        } else {
            if (string[i] == '\t') {
                moveCursor(TAB);
            } else {
                drawCharOnCursor(string[i]);
            }
        }
        i++;
    }
    *length = i;
}

static void drawSquareOnCursor(uint32_t hexColor, int x, int y) {
    for (int i = 0; i < cursor.scale; i++) {
        for (int j = 0; j < cursor.scale; j++) {
            putPixel(hexColor, x + j, y + i);
        }
    }
}

void drawSquare(uint32_t hexColor,uint64_t x, uint64_t y, uint32_t scale){
    for(int j = 0; j < scale;j++) {
        for(int i = 0; i < scale; i++) {
            putPixel(hexColor,x+i,y+j);
        }
    }
}

void colorScreen(uint32_t hexColor) {
    for (int i = 0; i < LAST_X; i++) {
        for (int j = 0; j < LAST_Y; j++) {
            putPixel(hexColor, i, j);
        }
    }
}

void setColor(uint32_t textColor, uint32_t backColor) {
	characterColor = textColor;
	backgroundColor = backColor;
}

static void clearTerminal() {
    colorScreen(backgroundColor);
}

// x y coordinates are the border of the square where the circle is inscribed
void drawCircle(uint32_t hexColor, uint64_t x, uint64_t y, uint32_t length) {
    uint32_t radius = length/2 - 1;
    // center of square
    x = x + radius;
    y = y + radius;
   for(int i=0;i<radius;i++) {
        for(int j=0;j<radius;j++) {
            if((i*i)+(j*j)<=(radius*radius)) {
                putPixel(hexColor,x+i,y+j);
                putPixel(hexColor,x-i,y+j);
                putPixel(hexColor,x+i,y-j);
                putPixel(hexColor,x-i,y-j);
            }
        }
    }
}

uint32_t getBackgroundColor() {
    return backgroundColor;
}
