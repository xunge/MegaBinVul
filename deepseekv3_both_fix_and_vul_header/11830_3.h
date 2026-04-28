#include <stdio.h>
#include <stdlib.h>

typedef unsigned short ushort;

#define CLASS

extern int raw_image;
extern int shot_select;
extern FILE *ifp;
extern unsigned data_offset;
extern unsigned raw_width;
extern unsigned raw_height;
extern unsigned top_margin;
extern unsigned left_margin;
extern unsigned height;
extern unsigned width;
extern ushort (*image)[4];
extern int mix_green;

void unpacked_load_raw();
void read_shorts(ushort *pixel, unsigned count);
void merror(void *ptr, const char *where);
int get4();
int LIM(int val, int min, int max);