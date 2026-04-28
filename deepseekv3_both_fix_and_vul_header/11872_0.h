#include <string.h>
#include <stdlib.h>

#define uchar unsigned char
#define CLASS 
#define width 640
#define height 480
#define RAW(row,col) raw_image[(row)*width+(col)]
#define ABS(x) ((x) > 0 ? (x) : -(x))
#define LIM(x,min,max) ((x) < (min) ? (min) : (x) > (max) ? (max) : (x))

extern int getbits(int bits);
extern void checkCancel();
extern unsigned short *raw_image;
extern int maximum;