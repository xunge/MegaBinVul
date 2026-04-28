#include <stdint.h>
#include <string.h>

typedef unsigned char byte;
typedef unsigned long ulong;
typedef unsigned int uint;
typedef uint32_t gs_glyph;

typedef struct gs_const_string {
    const byte *data;
    int size;
} gs_const_string;

typedef struct gs_font {
    int FontType;
    void *client_data;
    void *memory;
} gs_font;

typedef struct gs_font_type42 {
    struct {
        void (*string_proc)(struct gs_font_type42 *, int, int, const byte **);
    } data;
} gs_font_type42;

typedef struct xps_font_t {
    // Define as needed for xps_find_sfnt_table
} xps_font_t;

#define GS_MIN_GLYPH_INDEX 0
#define ft_TrueType 0

static const char *pl_mac_names[258];

static int xps_find_sfnt_table(xps_font_t *font, const char *tag, int *length);
static int gs_throw(int code, const char *msg);
static int gs_throw1(int code, const char *msg, unsigned long arg);
static int gs_sprintf(char *str, const char *format, ...);

#define u32(p) (*(const uint32_t *)(p))
#define u16(p) (*(const uint16_t *)(p))

static void *gs_alloc_bytes(void *memory, size_t size, const char *name);