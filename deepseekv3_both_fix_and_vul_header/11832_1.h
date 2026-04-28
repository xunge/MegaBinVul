#include <stdlib.h>
#include <string.h>

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define FORC3 for (c=0; c < 3; c++)
#define CLASS

extern int height;
extern int width;
extern ushort **image;
extern int load_flags;
extern int kodak_65000_decode(short *buf, int len);
extern void derror();
#ifdef LIBRAW_LIBRARY_BUILD
extern void checkCancel();
#endif

typedef unsigned short ushort;