#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uchar;

#define CLASS

extern int raw_width;
extern int height;
extern int width;
extern FILE *ifp;
extern unsigned short curve[256];
extern int maximum;
extern unsigned short (*image)[4];  // Changed from void** to proper array type

void merror(void *ptr, const char *where);
void derror();
void checkCancel();

#define FORC3 for (c=0; c < 3; c++)
#define LIM(x,min,max) ((x) < (min) ? (min) : ((x) > (max) ? (max) : (x)))