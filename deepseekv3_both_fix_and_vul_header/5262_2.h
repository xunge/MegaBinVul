#include <stdint.h>
#include <stddef.h>

typedef uint8_t guint8;
typedef int gboolean;
typedef struct tvbuff tvbuff_t;

#define ENC_ASCII 0
#define wmem_packet_scope() NULL
const guint8* tvb_get_string_enc(void* scope, tvbuff_t* tvb, int offset, int length, int enc);
void* wmem_alloc(void* scope, size_t size);