#include <stdbool.h>

#define FALSE false
#define TRUE true
#define CSD_BUF_SIZE 256

typedef struct {
    int curbit;
    int lastbit;
    int last_byte;
    bool done;
    unsigned char buf[CSD_BUF_SIZE];
} CODE_STATIC_DATA;

typedef struct gdIOCtx gdIOCtx;

extern int GetDataBlock(gdIOCtx *fd, unsigned char *buf, int *ZeroDataBlockP);