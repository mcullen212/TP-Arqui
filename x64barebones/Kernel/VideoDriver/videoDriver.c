#include <videoDriver.h>
const uint8_t pixel_A[5][5] = {
    {0, 0, 1, 0, 0},
    {0, 1, 0, 1, 0},
    {1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1}
};

const uint8_t pixel_B[5][5] = {
    {1, 1, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {1, 1, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {1, 1, 1, 0, 0}
};

const uint8_t pixel_C[5][5] = {
    {0, 1, 1, 1, 0},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0},
    {1, 0, 0, 0, 1},
    {0, 1, 1, 1, 0}
};

const uint8_t pixel_D[5][5] = {
    {1, 1, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {1, 0, 0, 1, 0},
    {1, 0, 0, 1, 0},
    {1, 1, 1, 0, 0}
};

const uint8_t pixel_E[5][5] = {
    {1, 1, 1, 1, 0},
    {1, 0, 0, 0, 0},
    {1, 1, 1, 0, 0},
    {1, 0, 0, 0, 0},
    {1, 1, 1, 1, 0}
};

const uint8_t pixel_F[5][5] = {
    {1, 1, 1, 1, 0},
    {1, 0, 0, 0, 0},
    {1, 1, 1, 0, 0},
    {1, 0, 0, 0, 0},
    {1, 0, 0, 0, 0}
};

const uint8_t pixel_G[5][5] = {
    {0, 1, 1, 1, 1},
    {1, 0, 0, 0, 0},
    {1, 0, 0, 1, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 1, 1, 0}
};

const uint8_t pixel_H[5][5] = {
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1}
};

const uint8_t pixel_I[5][5] = {
    {1, 1, 1, 1, 1},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {1, 1, 1, 1, 1}
};

const uint8_t pixel_J[5][5] = {
    {0, 0, 0, 0, 1},
    {0, 0, 0, 0, 1},
    {0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 1, 1, 0}
};

const uint8_t pixel_K[5][5] = {
    {1, 0, 0, 0, 1},
    {1, 0, 0, 1, 0},
    {1, 1, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {1, 0, 0, 0, 1}
};

const uint8_t pixel_L[5][5] = {
    {1, 0, 0, 0, 0},
    {1, 0, 0, 0, 0},
    {1, 0, 0, 0, 0},
    {1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1}
};

const uint8_t pixel_M[5][5] = {
    {1, 0, 0, 0, 1},
    {1, 1, 0, 1, 1},
    {1, 0, 1, 0, 1},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1}
};

const uint8_t pixel_N[5][5] = {
    {1, 0, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {1, 0, 1, 0, 1},
    {1, 0, 0, 1, 1},
    {1, 0, 0, 0, 1}
};

const uint8_t pixel_O[5][5] = {
    {0, 1, 1, 1, 0},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 1, 1, 0}
};

const uint8_t pixel_P[5][5] = {
    {1, 1, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {1, 1, 1, 0, 0},
    {1, 0, 0, 0, 0},
    {1, 0, 0, 0, 0}
};

const uint8_t pixel_Q[5][5] = {
    {0, 1, 1, 1, 0},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 1, 0},
    {1, 0, 0, 0, 1},
    {0, 1, 1, 1, 1}
};

const uint8_t pixel_R[5][5] = {
    {1, 1, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {1, 1, 1, 0, 1},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1}
};

const uint8_t pixel_S[5][5] = {
    {0, 1, 1, 1, 0},
    {1, 0, 0, 0, 1},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 1},
    {1, 1, 1, 1, 0}
};

const uint8_t pixel_T[5][5] = {
    {1, 1, 1, 1, 1},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0}
};

const uint8_t pixel_U[5][5] = {
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 1, 1, 0}
};

const uint8_t pixel_V[5][5] = {
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 0, 1, 0},
    {0, 0, 1, 0, 0}
};

const uint8_t pixel_W[5][5] = {
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {1, 0, 1, 0, 1},
    {1, 1, 0, 1, 1},
    {1, 0, 0, 0, 1}
};

const uint8_t pixel_X[5][5] = {
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 0, 1, 0},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1}
};

const uint8_t pixel_Y[5][5] = {
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {0, 1, 0, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0}
};

const uint8_t pixel_Z[5][5] = {
    {1, 1, 1, 1, 1},
    {0, 0, 0, 0, 1},
    {0, 0, 0, 1, 0},
    {0, 0, 1, 0, 0},
    {1, 1, 1, 1, 1}
};

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

void putPixel(uint32_t hexColor, uint64_t x, uint64_t y) {
	//the location in memory where the graphics framebuffer is stored
    uint8_t * framebuffer = (uint8_t *) VBE_mode_info->framebuffer;

	// indicates where the pixel's color information should be stored
    uint64_t offset = (x * ((VBE_mode_info->bpp)/8)) + (y * VBE_mode_info->pitch);

	//setting color 
    framebuffer[offset]     =  (hexColor) & 0xFF;  // blue components 
    framebuffer[offset+1]   =  (hexColor >> 8) & 0xFF;  // green component
    framebuffer[offset+2]   =  (hexColor >> 16) & 0xFF; // rojo component
} 

void printLetter(char num_letter, uint32_t hexColor, uint64_t x, uint64_t y, uint64_t scale) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (pixel_A[i][j] == 1) {
                for (uint64_t k = 0; k < scale; k++) {
                    for (uint64_t l = 0; l < scale; l++) {
                        putPixel(hexColor, x + j * scale + l, y + i * scale + k);
                    }
                }
            }
        }
    }
}




