#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct decode {
    struct decode *branch[2];
    short leaf;
};

extern int height;
extern int width;
extern int load_flags;
extern char *model;
extern FILE *ifp;
extern struct decode *first_decode;
extern unsigned short (*image)[3];

#define FORC3 for (c=0; c < 3; c++)
#define CLASS
#define ushort unsigned short
#undef LIBRAW_LIBRARY_BUILD
#define checkCancel()
#define get4() 0
#define read_shorts(a,b)
#define foveon_decoder(a,b)
#define derror()