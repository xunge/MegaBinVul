#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uchar;

#define CLASS 

extern int raw_width;
extern int height;
extern int width;
extern FILE *ifp;
extern int load_flags;
extern unsigned short (*image)[3];
extern unsigned short *curve;
extern int maximum;

void merror(void *ptr, const char *where);
void derror(void);
#ifdef LIBRAW_LIBRARY_BUILD
void checkCancel(void);
#endif

#define FORC3 for (c=0; c < 3; c++)
#define LIM(x,min,max) ((x) < (min) ? (min) : ((x) > (max) ? (max) : (x)))