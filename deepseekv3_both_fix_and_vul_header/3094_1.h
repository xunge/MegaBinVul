#include <stdlib.h>
#include <string.h>

#define CHECK_ORDER_LOW(x)
#define LIBRAW_PROGRESS_RAW2_IMAGE 0
#define ZERO(array) memset(array, 0, sizeof(array))
#define EXCEPTION_HANDLER(err)

typedef unsigned short ushort;

struct imgdata_t {
    ushort (*image)[4];
};

struct IO_t {
    int shrink;
};

struct S_t {
    int iheight;
    int iwidth;
};

struct C_t {
    int cblack[4];
    int data_maximum;
    int maximum;
    int black;
};

class LibRaw {
public:
    imgdata_t imgdata;
    IO_t IO;
    S_t S;
    C_t C;
    int is_phaseone_compressed();
    int subtract_black();
};

class LibRaw_exceptions {
};