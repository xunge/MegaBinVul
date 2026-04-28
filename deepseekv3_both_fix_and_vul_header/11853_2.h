#include <stdlib.h>
#include <stdio.h>

typedef unsigned char uchar;

#define CLASS

extern int raw_width;
extern int height;
extern int width;
extern FILE *ifp;
extern int load_flags;
extern unsigned short curve[256];
extern int maximum;
extern unsigned short (*image)[3];  // Changed from void* to proper array type

#define FORC3 for (c = 0; c < 3; c++)
#define LIM(x, y, z) ((x) < (y) ? (y) : ((x) > (z) ? (z) : (x)))
#define merror(ptr, msg) if (!(ptr)) { fprintf(stderr, "%s\n", msg); exit(1); }
#define derror() { fprintf(stderr, "Error reading file\n"); exit(1); }
#ifdef LIBRAW_LIBRARY_BUILD
#define checkCancel()
#endif