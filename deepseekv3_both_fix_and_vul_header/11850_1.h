#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct decode {
    struct decode *branch[2];
    int leaf;
};

#define CLASS
#define ushort unsigned short
#define FORC3 for (c = 0; c < 3; c++)
#define height 0
#define width 0
#define model ""
#define load_flags 0
#define first_decode NULL
#define ifp NULL
unsigned short (*image)[3] = NULL;

void read_shorts(ushort *data, int count);
void foveon_decoder(int size, int flags);
int get4();
void derror();
void checkCancel();