#include <stdint.h>

typedef struct tvbuff tvbuff_t;
typedef unsigned int guint;
typedef uint32_t guint32;

static guint get_write_chunk_size(tvbuff_t *tvb, guint offset);