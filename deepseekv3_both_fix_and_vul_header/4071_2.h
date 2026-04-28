#include <stdint.h>
#include <string.h>

typedef unsigned char byte;
typedef unsigned long ulong;
typedef unsigned int uint;
typedef ulong gs_glyph;

#define GS_MIN_GLYPH_INDEX 0
#define ft_TrueType 0

typedef struct gs_memory_s gs_memory_t;

typedef struct gs_const_string_s {
    const byte *data;
    uint size;
} gs_const_string;

typedef struct gs_font_type42_s {
    struct {
        void (*string_proc)(struct gs_font_type42_s *, ulong, uint, const byte **);
    } data;
    /* other members omitted */
} gs_font_type42;

typedef struct gs_font_s {
    int FontType;
    gs_memory_t *memory;
    void *client_data;
    gs_font_type42 base;  // assuming gs_font contains gs_font_type42 as base
} gs_font;

typedef struct pl_font_s {
    char **names;
    uint max_name_index;
    uint next_name_index;
} pl_font_t;

extern const char *pl_mac_names[];
extern void *gs_alloc_bytes(gs_memory_t *, uint, const char *);
extern void gs_free_object(gs_memory_t *, void *, const char *);
extern void dmprintf(gs_memory_t *, const char *);
extern void dmprintf1(gs_memory_t *, const char *, ulong);
extern void if_debug1m(char, gs_memory_t *, const char *, ulong);
extern ulong tt_find_table(gs_font_type42 *, const char *, uint *);

static inline uint u16(const byte *p) { return p[0] << 8 | p[1]; }
static inline ulong u32(const byte *p) { return p[0] << 24 | p[1] << 16 | p[2] << 8 | p[3]; }