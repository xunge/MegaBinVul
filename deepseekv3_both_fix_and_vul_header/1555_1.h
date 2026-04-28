#include <stdint.h>
#include <stddef.h>

typedef unsigned char u_char;

typedef struct {
    u_char *start;
    size_t size;
    uint32_t length;
} njs_string_prop_t;

typedef struct {
    uint32_t code;
    uint32_t count;
    uint32_t upper;
} njs_unicode_decode_t;

typedef struct {
    int type;
} njs_value_t;

#define NJS_TRIM_START 0x01
#define NJS_TRIM_END   0x02

static int njs_is_byte_or_ascii_string(njs_string_prop_t *string);
static int njs_is_whitespace(uint8_t c);
static void njs_string_prop(njs_string_prop_t *string, const njs_value_t *value);
static void njs_utf8_decode_init(njs_unicode_decode_t *ctx);
static uint32_t njs_utf8_decode(njs_unicode_decode_t *ctx, const u_char **pos, const u_char *end);
static int njs_utf8_is_whitespace(uint32_t cp);
static const u_char *njs_utf8_prev(const u_char *p);