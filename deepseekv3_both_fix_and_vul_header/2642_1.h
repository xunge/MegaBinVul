#include <stdlib.h>
#include <stdio.h>

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define CLASS

extern int height;
extern int width;
extern unsigned short *curve;
extern int kodak_65000_decode(short *buf, int len);
extern void derror();
extern void checkCancel();

#define RAW(row,col) raw_image[(row)*width+(col)]
extern unsigned short *raw_image;