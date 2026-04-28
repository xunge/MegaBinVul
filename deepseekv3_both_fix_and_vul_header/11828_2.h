#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <float.h>

#define CLASS
#define TS 512
#define width 0
#define height 0
#define verbose 0
#define image ((ushort (*)[4])0)
#define fcol(row,col) 0
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x) > 0 ? (x) : -(x))
#define SQR(x) ((x)*(x))
#define CLIP(x) ((x) < 0 ? 0 : ((x) > 65535 ? 65535 : (x)))
#define LIM(x,min,max) ((x) < (min) ? (min) : ((x) > (max) ? (max) : (x)))
#define FORC(cnt) for (c = 0; c < cnt; c++)
#define FORC3 FORC(3)
#define FORC4 FORC(4)

typedef unsigned short ushort;

void border_interpolate(int border);
void cielab(ushort rgb[3], short lix[3]);
void merror(void *ptr, const char *where);
const char *_(const char *text);