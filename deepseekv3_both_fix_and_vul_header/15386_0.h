#include <stdint.h>

typedef struct {
    int cabac_decoder;
    int* ctx_model;
} thread_context;

#define LogSlice 0
#define LogSymbols 0
#define CONTEXT_MODEL_REF_IDX_LX 0

void logtrace(int, const char*, ...);
int decode_CABAC_bit(thread_context*, int*);
int decode_CABAC_bypass(thread_context*);