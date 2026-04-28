#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uchar;

extern int raw_width;
extern int height;
extern int width;
extern FILE *ifp;
extern unsigned short **image;
extern unsigned short *curve;
extern int maximum;

void merror(void *ptr, const char *where);
void derror(void);
void checkCancel(void);

#define CLASS
#define FORC3 for (c=0; c < 3; c++)
#define LIM(x,y,z) ((x) < (y) ? (y) : ((x) > (z) ? (z) : (x)))