#include <stdint.h>

typedef uint8_t guint8;
typedef unsigned int guint;

typedef struct tvbuff_t tvbuff_t;

guint8 tvb_get_guint8(tvbuff_t *tvb, guint offset);
guint tvb_reported_length(tvbuff_t *tvb);