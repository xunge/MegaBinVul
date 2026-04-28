#include <stdio.h>
#include <string.h>

#ifndef LIBRAW_LIBRARY_BUILD
extern int filters;
extern int width;
extern int height;
extern int timestamp;
extern int verbose;
extern short (*BAYER)[4];
extern int fcol(int row, int col);
#else
extern int filters;
extern int width;
extern int height;
extern int timestamp;
extern short (*BAYER)[4];
extern int fcol(int row, int col);
#ifdef DCRAW_VERBOSE
extern int verbose;
#endif
#endif

#ifndef _
#define _(str) str
#endif

#define CLASS

#define BAYER2(row,col) BAYER[row*width+col][fcol(row,col)]