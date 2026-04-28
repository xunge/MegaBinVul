#include <stdlib.h>
#include <stdint.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define LIM(x, a, b) ((x) < (a) ? (a) : ((x) > (b) ? (b) : (x)))
#define FORC3 for (c = 0; c < 3; c++)

typedef unsigned short ushort;

extern short *image;
extern int height;
extern int width;
extern int load_flags;
extern ushort (*curve)[0x1000];
extern void kodak_65000_decode(short *buf, int len);
extern void derror(void);
#ifdef LIBRAW_LIBRARY_BUILD
extern void checkCancel(void);
#endif

#define CLASS