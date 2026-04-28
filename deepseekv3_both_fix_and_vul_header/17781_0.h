#include <stddef.h>

typedef struct sraSpan {
    struct sraSpan *_next;
    struct sraSpan *_prev;
} sraSpan;