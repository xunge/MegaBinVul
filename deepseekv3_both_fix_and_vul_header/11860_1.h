#include <stdio.h>
#include <stdlib.h>

#define LIM(x, a, b) ((x) < (a) ? (a) : ((x) > (b) ? (b) : (x)))
#define CLASS

typedef unsigned short ushort;

extern FILE *ifp;
extern unsigned shot_select;
extern unsigned data_offset;
extern unsigned raw_width;
extern unsigned raw_height;
extern unsigned top_margin;
extern unsigned left_margin;
extern unsigned height;
extern unsigned width;
extern ushort (*image)[4];
extern int raw_image;
extern int mix_green;

void unpacked_load_raw();
void read_shorts(ushort *pixel, unsigned count);
void merror(void *ptr, const char *where);
#ifdef LIBRAW_LIBRARY_BUILD
void checkCancel();
#endif
unsigned get4();