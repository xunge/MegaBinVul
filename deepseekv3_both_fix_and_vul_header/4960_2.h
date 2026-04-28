#include <stddef.h>

typedef unsigned char guint8;
typedef int gint;
typedef unsigned int guint;

typedef struct tvbuff_t tvbuff_t;
typedef void* wmem_allocator_t;

#define wmem_packet_scope() NULL
#define ENC_ASCII 0

gint tvb_pbrk_guint8(tvbuff_t *tvb, gint offset, gint maxlength, const char *charset, gint *found_offset);
guint8* tvb_get_string_enc(wmem_allocator_t *scope, tvbuff_t *tvb, gint offset, gint length, guint encoding);