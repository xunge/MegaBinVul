#include <stdlib.h>
#include <stdio.h>

#define CLASS 
#define FORC(count) for (c=0; c < count; c++)

typedef unsigned short ushort;

extern int filters;
extern int raw_width;
extern int raw_height;
extern int tiff_samples;
extern int tile_length;
extern FILE *ifp;
extern unsigned data_offset;
extern int shot_select;
extern ushort *raw_image;
extern int top_margin;
extern int height;
extern int width;
extern int left_margin;
extern unsigned short (*image)[4];
extern unsigned maximum;
extern int raw_color;

void merror(void *ptr, const char *where);
void read_shorts(ushort *pixel, int count);
unsigned get4();
void checkCancel();