#include <stdint.h>

typedef struct GetBitContext GetBitContext;

typedef struct AACContext {
    void *avctx;
} AACContext;

typedef struct SpectralBandReplication {
    int id_aac;
} SpectralBandReplication;

enum {
    TYPE_SCE,
    TYPE_CPE, 
    TYPE_CCE
};

#define AV_LOG_ERROR 16