#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct {
    unsigned char data[8];
} XdmAuthKeyRec;
typedef XdmAuthKeyRec *XdmAuthKeyPtr;
typedef long Time_t;

static inline void getbits(long bits, unsigned char *dst) {
    dst[0] = (bits >> 24) & 0xff;
    dst[1] = (bits >> 16) & 0xff;
    dst[2] = (bits >> 8) & 0xff;
    dst[3] = bits & 0xff;
}