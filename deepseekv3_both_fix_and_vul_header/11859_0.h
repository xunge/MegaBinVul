#include <stdio.h>
#include <stdlib.h>

#define CLASS 
#define FORC3 for (c = 0; c < 3; c++)
#define ushort unsigned short

extern FILE *ifp;
extern unsigned data_offset;
extern unsigned height;
extern unsigned width;
extern unsigned short (*image)[4];

void foveon_huff(ushort *huff);
unsigned get4();
void getbits(int val);
int ljpeg_diff(ushort *huff);
#ifdef LIBRAW_LIBRARY_BUILD
void checkCancel();
#endif