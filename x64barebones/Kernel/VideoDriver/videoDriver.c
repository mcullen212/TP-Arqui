#include <videoDriver.h>
#include<fonts.h>

#define WIDTH_FONT 8
#define HEIGHT_FONT 16
#define TAB_SIZE 4

static uint32_t characterColor = 0xFFFFFF; // default color white
static uint32_t backgroundColor = 0x000000; // default color black

static void drawSquare(uint32_t hexColor, uint64_t x, uint64_t y, uint32_t scale);

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

void drawChar(uint8_t character, uint64_t x, uint64_t y, uint32_t scale) {
    unsigned char *pixel = font8x16[character];

    for(int i = 0; i < HEIGHT_FONT; i++) {
        for(int j = 0; j<WIDTH_FONT; j++) {
            int bit = (pixel[i] >> j) & 1;
            if(bit){
                drawSquare(characterColor, x, y, scale);
            }
            x+=scale;
        }
        x-=(8 * scale);
        y+=scale;
    }
}

static void drawSquare(uint32_t hexColor,uint64_t x, uint64_t y, uint32_t scale){
    for(int j = 0; j < scale;j++) {
        for(int i = 0; i < scale; i++) {
            putPixel(hexColor,x+i,y+j);
        }
    }
}

void deleteChar(uint64_t x, uint64_t y, uint32_t scale) {
    for(int i = 0; i < HEIGHT_FONT; i++) {
        for(int j = 0; j< WIDTH_FONT; j++) {
    		drawSquare(backgroundColor, x, y, scale);
            x+=scale;
        }
        x-=(8 * scale);
        y+=scale;
    }
}

void drawString(uint8_t * string, uint64_t x, uint64_t y, uint32_t scale, uint32_t * length) {
	int i = 0;
    int x0 = x;
	while(string[i] != 0){
        if (string[i] == '\n') {
            x = x0;
            y += (HEIGHT_FONT * scale);
        } else {
            if (string[i] == '\t') {
                for (int j = 0; j < TAB_SIZE ; j++) {
                    drawChar(' ', x, y, scale);
                    x+=8*scale;
                }
            } else {
                drawChar(string[i], x, y, scale);
		        x+=8*scale;
            }
        }
		i++;
	}
	*length = i;
}

void setColor(uint32_t textColor, uint32_t backColor) {
	characterColor = textColor;
	backgroundColor = backColor;
}
