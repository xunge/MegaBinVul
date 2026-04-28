#include <stdint.h>

typedef struct _tvbuff_t tvbuff_t;
typedef struct _packet_info packet_info;
typedef int gint;
typedef unsigned int guint;
typedef uint8_t guint8;
typedef int gboolean;

#define TRUE 1
#define _U_ __attribute__((unused))

extern int tvb_find_line_end(tvbuff_t *tvb, int offset, int max_length, int *next_offset, gboolean desegment);
extern gint get_bzr_prefixed_len(tvbuff_t *tvb, int offset);
extern gint tvb_reported_length_remaining(tvbuff_t *tvb, gint offset);
extern guint8 tvb_get_guint8(tvbuff_t *tvb, gint offset);