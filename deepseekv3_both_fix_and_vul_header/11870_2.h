#include <string.h>
#include <stdlib.h>

#define uchar unsigned char
#define ushort unsigned short

#define CLASS 
#define height 480
#define width 640
#define RAW(row,col) image[row][col]
int maximum = 0x3ff;

static int getbits(int bits) { return 0; }
#define LIM(val,min,max) ((val) < (min) ? (min) : ((val) > (max) ? (max) : (val)))
#define ABS(x) ((x) < 0 ? -(x) : (x))

#ifdef LIBRAW_LIBRARY_BUILD
static void checkCancel() {}
#endif

static ushort image[480][640];