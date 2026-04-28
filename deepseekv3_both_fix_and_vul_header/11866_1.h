#include <stdlib.h>
#include <stdio.h>

typedef unsigned char uchar;

#define CLASS

extern int raw_width;
extern int height;
extern int width;
extern FILE *ifp;
extern unsigned short curve[256];
extern unsigned short (*image)[4];
extern int maximum;

void merror(void *ptr, const char *where);
void derror();
void checkCancel();

#define FORC3 for (c = 0; c < 3; c++)
#define LIM(x, min, max) ((x) < (min) ? (min) : ((x) > (max) ? (max) : (x)))