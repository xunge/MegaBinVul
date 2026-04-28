#include <stdio.h>
#include <stdlib.h>

#define LIM(x,y,z) ((x) < (y) ? (y) : ((x) > (z) ? (z) : (x)))
#define CLASS

typedef unsigned short ushort;

extern unsigned shot_select;
extern unsigned data_offset;
extern unsigned raw_width;
extern unsigned raw_height;
extern unsigned top_margin;
extern unsigned height;
extern unsigned left_margin;
extern unsigned width;
extern int mix_green;
extern FILE *ifp;
extern void *raw_image;
extern ushort (*image)[4];

void merror(void *ptr, const char *where);
void unpacked_load_raw();
void read_shorts(ushort *pixel, unsigned count);
unsigned get4();
#ifdef LIBRAW_LIBRARY_BUILD
void checkCancel();
#endif