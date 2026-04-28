#include <stdint.h>

#define CV_8U 0
#define CV_16U 2

struct channel_layout {
    int graychan;
    int bchan;
    int gchan;
    int rchan;
};

typedef uint8_t uchar;
typedef uint16_t ushort;

enum Error {
    StsInternal
};

void CV_Error(int code, const char* msg);