#include <stdint.h>

typedef enum { qfalse, qtrue } qboolean;

typedef struct {
    int readcount;
    int cursize;
    qboolean oob;
    uint8_t *data;
    int bit;
} msg_t;

typedef struct {
    struct {
        void *tree;
    } decompressor;
} Huff_t;

enum {
    ERR_DROP
};

extern Huff_t msgHuff;

int Huff_getBit(uint8_t *data, int *bit);
void Huff_offsetReceive(void *tree, int *get, uint8_t *data, int *bit, ...);
void CopyLittleShort(short *out, const void *in);
void CopyLittleLong(int *out, const void *in);
void Com_Error(int level, const char *fmt, ...);