#ifndef FONTS_H
#define FONTS_H

const unsigned char font8x16[128][16]={
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
	,{0x00,0x00,0x3c,0x42,0x81,0xe7,0xa5,0x99,0x81,0x81,0x99,0x42,0x3c,0x00,0x00,0x00}
	,{0x00,0x00,0x3c,0x7e,0xff,0x99,0xdb,0xe7,0xff,0xff,0xe7,0x7e,0x3c,0x00,0x00,0x00}
	,{0x00,0x00,0x00,0x66,0xff,0xff,0xff,0xff,0xff,0x7e,0x3c,0x18,0x18,0x00,0x00,0x00}
	,{0x00,0x00,0x00,0x00,0x18,0x3c,0x7e,0xff,0xff,0x7e,0x3c,0x18,0x00,0x00,0x00,0x00}
	,{0x00,0x00,0x00,0x18,0x3c,0x3c,0x5a,0xff,0xff,0x5a,0x18,0x18,0x3c,0x00,0x00,0x00}
	,{0x00,0x00,0x00,0x18,0x3c,0x7e,0xff,0xff,0xff,0x5a,0x18,0x18,0x3c,0x00,0x00,0x00}
	,{0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x3c,0x3c,0x18,0x00,0x00,0x00,0x00,0x00,0x00}
	,{0xff,0xff,0xff,0xff,0xff,0xff,0xe7,0xc3,0xc3,0xe7,0xff,0xff,0xff,0xff,0xff,0xff}
	,{0x00,0x00,0x00,0x00,0x00,0x3c,0x66,0x42,0x42,0x66,0x3c,0x00,0x00,0x00,0x00,0x00}
	,{0xff,0xff,0xff,0xff,0xff,0xc3,0x99,0xbd,0xbd,0x99,0xc3,0xff,0xff,0xff,0xff,0xff}
	,{0x00,0x00,0xf0,0xe0,0xb0,0x18,0x7e,0xc3,0xc3,0xc3,0xc3,0xc3,0x7e,0x00,0x00,0x00}
	,{0x00,0x00,0x7e,0xc3,0xc3,0xc3,0x7e,0x18,0x18,0x7e,0x18,0x18,0x18,0x00,0x00,0x00}
	,{0x00,0x00,0x10,0x30,0x70,0xd0,0x10,0x10,0x10,0x1e,0x1f,0x0e,0x00,0x00,0x00,0x00}
	,{0x00,0x08,0x18,0x38,0x68,0x58,0x68,0x48,0x4e,0x4f,0x46,0x70,0x78,0x30,0x00,0x00}
	,{0x00,0x00,0x18,0x18,0xdb,0x7e,0x3c,0xff,0x3c,0x7e,0xdb,0x18,0x18,0x00,0x00,0x00}
	,{0x00,0x00,0x06,0x0e,0x1e,0x3e,0x7e,0x7e,0x3e,0x1e,0x0e,0x06,0x00,0x00,0x00,0x00}
	,{0x00,0x00,0x60,0x70,0x78,0x7c,0x7e,0x7e,0x7c,0x78,0x70,0x60,0x00,0x00,0x00,0x00}
	,{0x00,0x00,0x08,0x1c,0x3e,0x7f,0x1c,0x1c,0x1c,0x1c,0x7f,0x3e,0x1c,0x08,0x00,0x00}
	,{0x00,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x00,0x66,0x66,0x00,0x00,0x00}
	,{0x00,0xfe,0xdb,0xdb,0xdb,0xdb,0xde,0xdc,0xf8,0xd8,0xd8,0xd8,0xd8,0x00,0x00,0x00}
	,{0x00,0x78,0x0c,0x0c,0x1e,0x3b,0x73,0xe7,0xce,0xdc,0x78,0x30,0x30,0x1e,0x00,0x00}
	,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7e,0x7e,0x7e,0x7e,0x00,0x00,0x00,0x00}
	,{0x00,0x00,0x08,0x1c,0x3e,0x7f,0x1c,0x1c,0x1c,0x7f,0x3e,0x1c,0x08,0x00,0x7f,0x00}
	,{0x00,0x00,0x08,0x1c,0x3e,0x7f,0x1c,0x1c,0x1c,0x1c,0x1c,0x1c,0x1c,0x1c,0x00,0x00}
	,{0x00,0x00,0x1c,0x1c,0x1c,0x1c,0x1c,0x1c,0x1c,0x1c,0x7f,0x3e,0x1c,0x08,0x00,0x00}
	,{0x00,0x00,0x00,0x00,0x00,0x10,0x30,0x7f,0xff,0x7f,0x30,0x10,0x00,0x00,0x00,0x00}
	,{0x00,0x00,0x00,0x00,0x00,0x08,0x0c,0xfe,0xff,0xfe,0x0c,0x08,0x00,0x00,0x00,0x00}
	,{0x88,0xcc,0x66,0x66,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
	,{0x00,0x00,0x00,0x00,0x00,0x24,0x66,0xff,0xff,0x66,0x24,0x00,0x00,0x00,0x00,0x00}
	,{0x00,0x00,0x00,0x00,0x18,0x3c,0x3c,0x7e,0x7e,0xff,0xff,0x00,0x00,0x00,0x00,0x00}
	,{0x00,0x00,0x00,0x00,0xff,0xff,0x7e,0x7e,0x3c,0x3c,0x18,0x00,0x00,0x00,0x00,0x00}
	,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}// ' '
	,{0x00,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x00,0x18,0x18,0x00,0x00,0x00}// '!'
	,{0x00,0x66,0x66,0x33,0x11,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}// '"'
	,{0x00,0x66,0x66,0x66,0xff,0x66,0x66,0x66,0xff,0x66,0x66,0x66,0x66,0x00,0x00,0x00}// '#'
	,{0x00,0x18,0x18,0x3c,0x66,0x66,0x06,0x3c,0x60,0x66,0x66,0x3c,0x18,0x18,0x00,0x00}// '$'
	,{0x00,0x0e,0x1b,0x1b,0x0e,0xc0,0x70,0x1c,0x07,0x70,0xd8,0xd8,0x70,0x00,0x00,0x00}// '%'
	,{0x00,0x1c,0x36,0x36,0x36,0x1e,0x0c,0x7c,0x36,0x36,0x36,0x36,0x6c,0x00,0x00,0x00}// '&'
	,{0x00,0x18,0x18,0x0c,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}// '''
	,{0x00,0x60,0x30,0x18,0x18,0x0c,0x0c,0x0c,0x0c,0x0c,0x18,0x18,0x30,0x60,0x00,0x00}// '('
	,{0x00,0x06,0x0c,0x18,0x18,0x30,0x30,0x30,0x30,0x30,0x18,0x18,0x0c,0x06,0x00,0x00}// ')'
	,{0x00,0x00,0x00,0x00,0x18,0x18,0xff,0x3c,0x3c,0x66,0x00,0x00,0x00,0x00,0x00,0x00}// '*'
	,{0x00,0x00,0x00,0x00,0x18,0x18,0x18,0xff,0x18,0x18,0x18,0x00,0x00,0x00,0x00,0x00}// '+'
	,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x0c,0x04,0x00}// ','
	,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}// '-'
	,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00}// '.'
	,{0x00,0x30,0x30,0x30,0x18,0x18,0x18,0x0c,0x0c,0x0c,0x06,0x06,0x06,0x00,0x00,0x00}// '/'
	,{0x00,0x3c,0x66,0x66,0x66,0x66,0x66,0x76,0x7e,0x6e,0x66,0x66,0x3c,0x00,0x00,0x00}// '0'
	,{0x00,0x1c,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x3c,0x00,0x00,0x00}// '1'
	,{0x00,0x3c,0x66,0x66,0x60,0x60,0x60,0x3c,0x06,0x06,0x66,0x66,0x7e,0x00,0x00,0x00}// '2'
	,{0x00,0x7e,0x66,0x66,0x30,0x30,0x38,0x60,0x60,0x60,0x66,0x66,0x3c,0x00,0x00,0x00}// '3'
	,{0x00,0x60,0x70,0x70,0x78,0x68,0x6c,0x64,0x66,0xfe,0x60,0x60,0x60,0x00,0x00,0x00}// '4'
	,{0x00,0x7e,0x66,0x66,0x06,0x06,0x3e,0x60,0x60,0x60,0x66,0x66,0x3c,0x00,0x00,0x00}// '5'
	,{0x00,0x3c,0x66,0x66,0x06,0x06,0x3e,0x66,0x66,0x66,0x66,0x66,0x3c,0x00,0x00,0x00}// '6'
	,{0x00,0x7e,0x66,0x66,0x60,0x30,0x30,0x18,0x18,0x0c,0x0c,0x0c,0x0c,0x00,0x00,0x00}// '7'
	,{0x00,0x3c,0x66,0x66,0x66,0x66,0x3c,0x66,0x66,0x66,0x66,0x66,0x3c,0x00,0x00,0x00}// '8'
	,{0x00,0x3c,0x66,0x66,0x66,0x66,0x66,0x7c,0x60,0x60,0x66,0x66,0x3c,0x00,0x00,0x00}// '9'
	,{0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00}// ':'
	,{0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00,0x18,0x18,0x0c,0x00,0x00,0x00}// ';'
	,{0x00,0x00,0x60,0x30,0x18,0x0c,0x06,0x06,0x0c,0x18,0x30,0x60,0x00,0x00,0x00,0x00}// '<'
	,{0x00,0x00,0x00,0x00,0x00,0x7e,0x00,0x00,0x7e,0x00,0x00,0x00,0x00,0x00,0x00,0x00}// '='
	,{0x00,0x00,0x06,0x0c,0x18,0x30,0x60,0x60,0x30,0x18,0x0c,0x06,0x00,0x00,0x00,0x00}// '>'
	,{0x00,0x3c,0x66,0x66,0x60,0x60,0x30,0x18,0x18,0x18,0x00,0x00,0x18,0x00,0x00,0x00}// '?'
	,{0x00,0x3c,0x66,0x66,0x76,0x76,0x76,0x76,0x76,0x36,0x06,0x06,0x3c,0x00,0x00,0x00}// '@'
	,{0x00,0x3c,0x66,0x66,0x66,0x66,0x66,0x7e,0x66,0x66,0x66,0x66,0x66,0x00,0x00,0x00}// 'A'
	,{0x00,0x3e,0x66,0x66,0x66,0x66,0x3e,0x66,0x66,0x66,0x66,0x66,0x3e,0x00,0x00,0x00}// 'B'
	,{0x00,0x3c,0x66,0x66,0x06,0x06,0x06,0x06,0x06,0x06,0x66,0x66,0x3c,0x00,0x00,0x00}// 'C'
	,{0x00,0x3e,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x3e,0x00,0x00,0x00}// 'D'
	,{0x00,0x7c,0x06,0x06,0x06,0x06,0x1e,0x06,0x06,0x06,0x06,0x06,0x7c,0x00,0x00,0x00}// 'E'
	,{0x00,0x7c,0x06,0x06,0x06,0x06,0x3e,0x06,0x06,0x06,0x06,0x06,0x06,0x00,0x00,0x00}// 'F'
	,{0x00,0x3c,0x66,0x66,0x06,0x06,0x06,0x76,0x66,0x66,0x66,0x66,0x3c,0x00,0x00,0x00}// 'G'
	,{0x00,0x66,0x66,0x66,0x66,0x66,0x7e,0x66,0x66,0x66,0x66,0x66,0x66,0x00,0x00,0x00}// 'H'
	,{0x00,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x00,0x00,0x00}// 'I'
	,{0x00,0x78,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x60,0x66,0x66,0x3c,0x00,0x00,0x00}// 'J'
	,{0x00,0x66,0x66,0x66,0x66,0x36,0x1e,0x1e,0x36,0x66,0x66,0x66,0x66,0x00,0x00,0x00}// 'K'
	,{0x00,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x06,0x66,0x66,0x66,0x7e,0x00,0x00,0x00}// 'L'
	,{0x00,0x63,0x77,0x7f,0x6b,0x6b,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x00,0x00,0x00}// 'M'
	,{0x00,0x66,0x66,0x66,0x6e,0x7e,0x76,0x66,0x66,0x66,0x66,0x66,0x66,0x00,0x00,0x00}// 'N'
	,{0x00,0x3c,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x3c,0x00,0x00,0x00}// 'O'
	,{0x00,0x3e,0x66,0x66,0x66,0x66,0x66,0x3e,0x06,0x06,0x06,0x06,0x06,0x00,0x00,0x00}// 'P'
	,{0x00,0x3c,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x3c,0x60,0x60,0x40}// 'Q'
	,{0x00,0x3e,0x66,0x66,0x66,0x66,0x66,0x3e,0x36,0x66,0x66,0x66,0x66,0x00,0x00,0x00}// 'R'
	,{0x00,0x3c,0x66,0x66,0x06,0x06,0x3c,0x60,0x60,0x60,0x66,0x66,0x3c,0x00,0x00,0x00}// 'S'
	,{0x00,0x7e,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x00,0x00,0x00}// 'T'
	,{0x00,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x3c,0x00,0x00,0x00}// 'U'
	,{0x00,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x3c,0x3c,0x18,0x18,0x00,0x00,0x00}// 'V'
	,{0x00,0x63,0x63,0x63,0x63,0x63,0x63,0x6b,0x6b,0x7f,0x77,0x63,0x63,0x00,0x00,0x00}// 'W'
	,{0x00,0x66,0x66,0x66,0x3c,0x3c,0x18,0x18,0x3c,0x3c,0x66,0x66,0x66,0x00,0x00,0x00}// 'X'
	,{0x00,0x66,0x66,0x66,0x66,0x66,0x3c,0x18,0x18,0x18,0x18,0x18,0x18,0x00,0x00,0x00}// 'Y'
	,{0x00,0x7e,0x60,0x60,0x30,0x30,0x18,0x18,0x0c,0x0c,0x06,0x06,0x7e,0x00,0x00,0x00}// 'Z'
	,{0x00,0x7c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x7c,0x00,0x00,0x00}// '['
	,{0x00,0x06,0x06,0x06,0x0c,0x0c,0x0c,0x18,0x18,0x18,0x30,0x30,0x30,0x00,0x00,0x00}// '\'
	,{0x00,0x3e,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x3e,0x00,0x00,0x00}// ']'
	,{0x00,0x18,0x3c,0x66,0xc3,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}// '^'
	,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0x00,0x00}// '_'
	,{0x00,0x18,0x18,0x30,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}// '`'
	,{0x00,0x00,0x00,0x00,0x3c,0x60,0x60,0x7c,0x66,0x66,0x66,0x66,0x7c,0x00,0x00,0x00}// 'a'
	,{0x00,0x06,0x06,0x06,0x3e,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x3e,0x00,0x00,0x00}// 'b'
	,{0x00,0x00,0x00,0x00,0x3c,0x66,0x66,0x06,0x06,0x06,0x66,0x66,0x3c,0x00,0x00,0x00}// 'c'
	,{0x00,0x60,0x60,0x60,0x7c,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x7c,0x00,0x00,0x00}// 'd'
	,{0x00,0x00,0x00,0x00,0x3c,0x66,0x66,0x7e,0x06,0x06,0x66,0x66,0x3c,0x00,0x00,0x00}// 'e'
	,{0x00,0x70,0x18,0x18,0x18,0x3c,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x08,0x00}// 'f'
	,{0x00,0x00,0x00,0x00,0x3c,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x7c,0x60,0x60,0x3e}// 'g'
	,{0x00,0x06,0x06,0x06,0x3e,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x00,0x00,0x00}// 'h'
	,{0x00,0x18,0x00,0x00,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x10,0x00,0x00,0x00}// 'i'
	,{0x00,0x18,0x00,0x00,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x08}// 'j'
	,{0x00,0x06,0x06,0x06,0x46,0x66,0x66,0x66,0x3e,0x66,0x66,0x66,0x66,0x40,0x00,0x00}// 'k'
	,{0x00,0x08,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x00,0x00,0x00}// 'l'
	,{0x00,0x00,0x00,0x00,0x7f,0xdb,0xdb,0xdb,0xdb,0xdb,0xdb,0xdb,0xdb,0x00,0x00,0x00}// 'm'
	,{0x00,0x00,0x00,0x00,0x3e,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x00,0x00,0x00}// 'n'
	,{0x00,0x00,0x00,0x00,0x3c,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x3c,0x00,0x00,0x00}// 'o'
	,{0x00,0x00,0x00,0x00,0x3e,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x3e,0x06,0x06,0x06}// 'p'
	,{0x00,0x00,0x00,0x00,0x7c,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x7c,0x60,0x60,0x60}// 'q'
	,{0x00,0x00,0x00,0x00,0x38,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x0c,0x00,0x00,0x00}// 'r'
	,{0x00,0x00,0x00,0x00,0x3c,0x66,0x66,0x06,0x3c,0x60,0x66,0x66,0x3c,0x00,0x00,0x00}// 's'
	,{0x00,0x18,0x18,0x18,0x78,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x10,0x00,0x00,0x00}// 't'
	,{0x00,0x00,0x00,0x00,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x3e,0x00,0x00,0x00}// 'u'
	,{0x00,0x00,0x00,0x00,0x66,0x66,0x66,0x66,0x66,0x3c,0x3c,0x18,0x18,0x00,0x00,0x00}// 'v'
	,{0x00,0x00,0x00,0x00,0xdb,0xdb,0xdb,0xdb,0xdb,0xdb,0xdb,0xdb,0x7f,0x00,0x00,0x00}// 'w'
	,{0x00,0x00,0x00,0x00,0x66,0x66,0x3c,0x3c,0x18,0x3c,0x3c,0x66,0x66,0x00,0x00,0x00}// 'x'
	,{0x00,0x00,0x00,0x00,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x66,0x7c,0x60,0x60,0x60}// 'y'
	,{0x00,0x00,0x00,0x00,0x7e,0x60,0x30,0x30,0x18,0x0c,0x0c,0x06,0x7e,0x00,0x00,0x00}// 'z'
	,{0x00,0x70,0x18,0x18,0x18,0x18,0x0e,0x0e,0x18,0x18,0x18,0x18,0x70,0x00,0x00,0x00}// '{'
	,{0x00,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x00,0x00,0x00}// '|'
	,{0x00,0x0e,0x18,0x18,0x18,0x18,0x70,0x70,0x18,0x18,0x18,0x18,0x0e,0x00,0x00,0x00}// '}'
	,{0x00,0x00,0x00,0x00,0x00,0x00,0x6e,0x3b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}// '~'
	,{0x00,0x00,0x00,0x08,0x1c,0x36,0x63,0x63,0x63,0x63,0x7f,0x00,0x00,0x00,0x00,0x00}// ''
};
 
#endif
//Fuente:
//https://github.com/dhepper/font8x8/blob/master/font8x8_basic.h