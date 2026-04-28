#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define END_NOT_FOUND (-1)
#define FF_INPUT_BUFFER_PADDING_SIZE 16
#define AVERROR(e) (-(e))
#define ENOMEM 12

typedef struct ParseContext {
    uint8_t *buffer;
    int buffer_size;
    int index;
    int overread;
    int overread_index;
    int last_index;
    unsigned int state;
    uint64_t state64;
} ParseContext;

#define av_dlog(...)