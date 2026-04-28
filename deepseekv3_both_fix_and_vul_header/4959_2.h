#include <stddef.h>

typedef int gint;
typedef unsigned int guint;
typedef unsigned char guint8;

typedef struct tvbuff_t tvbuff_t;
typedef struct wmem_allocator_t wmem_allocator_t;

#define ENC_ASCII 0

wmem_allocator_t* wmem_packet_scope(void);
guint8 tvb_get_guint8(tvbuff_t *tvb, gint offset);
gint tvb_find_guint8(tvbuff_t *tvb, gint start, gint length, guint8 needle);
const guint8* tvb_get_string_enc(wmem_allocator_t *scope, tvbuff_t *tvb, gint offset, gint length, const char *encoding);