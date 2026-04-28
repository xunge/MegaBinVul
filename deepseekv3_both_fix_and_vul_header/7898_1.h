#include <stdint.h>

typedef struct tvbuff tvbuff_t;
typedef uint32_t guint32;
typedef unsigned int guint;

guint tvb_get_ntohl(tvbuff_t *tvb, guint offset);
guint get_write_chunk_size(tvbuff_t *tvb, guint offset);