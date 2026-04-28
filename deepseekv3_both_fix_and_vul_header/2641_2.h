#include <stdlib.h>
#include <stdio.h>

#define CLASS

extern int height;
extern int width;
extern unsigned short *curve;
extern unsigned short **raw_image;
extern int kodak_65000_decode(short *buf, int len);
extern void derror();
extern void checkCancel();

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define RAW(row,col) (*raw_image)[(row)*width+(col)]