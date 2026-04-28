#include <stdint.h>

typedef enum { qfalse, qtrue } qboolean;
typedef enum { ERR_DROP } errorParm_t;

typedef struct {
    qboolean overflowed;
    int cursize;
    int maxsize;
    qboolean oob;
    uint8_t *data;
    int bit;
} msg_t;

typedef struct {
    struct {
        void *compressor;
    } compressor;
} huff_t;

extern huff_t msgHuff;
extern int oldsize;

void Com_Error(errorParm_t code, const char *fmt, ...);
void Huff_putBit(int bit, uint8_t *fout, int *bitptr);
void Huff_offsetTransmit(void *compressor, int ch, uint8_t *fout, int *bitptr, ...);
void CopyLittleShort(void *out, const void *in);
void CopyLittleLong(void *out, const void *in);