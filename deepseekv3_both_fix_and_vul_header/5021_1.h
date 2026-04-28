#include <stdint.h>

#define UNREPL 0xFFFD

typedef uint8_t guint8;
typedef int32_t gint;
typedef uint32_t gunichar;

typedef struct wmem_allocator_t wmem_allocator_t;
typedef struct wmem_strbuf_t wmem_strbuf_t;

extern const gunichar t61_tab[];
extern const gunichar accents[];
extern const gunichar *(*cx_tab[])[32];