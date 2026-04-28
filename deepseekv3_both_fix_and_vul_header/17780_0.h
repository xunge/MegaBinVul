#include <stdlib.h>

typedef struct sraSpan {
    struct sraSpan *_prev;
    struct sraSpan *_next;
} sraSpan;