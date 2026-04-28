#include <stdint.h>

typedef uint32_t guint32;
typedef unsigned int guint;
typedef struct tvbuff tvbuff_t;

uint32_t tvb_get_ntohl(tvbuff_t *tvb, guint offset);