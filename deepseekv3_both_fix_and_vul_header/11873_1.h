#include <stdio.h>
#include <stdlib.h>

typedef unsigned short ushort;

#define CLASS
#define FORC(count) for (c=0; c < count; c++)

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
extern unsigned maximum;
extern int raw_color;
extern void (*merror)(void *, const char *);
extern void (*read_shorts)(ushort *, int);
extern unsigned get4();
extern void checkCancel();
extern ushort (*image)[4];