#include <stdio.h>
#include <stdlib.h>

#define FORC3 for (c = 0; c < 3; c++)
#define CLASS

typedef unsigned short ushort;

extern FILE *ifp;
extern unsigned data_offset;
extern int width;
extern int height;
extern ushort (*image)[4];

void foveon_huff(ushort *huff);
unsigned get4();
void getbits(int);
unsigned ljpeg_diff(ushort *huff);
#ifdef LIBRAW_LIBRARY_BUILD
void checkCancel();
#endif