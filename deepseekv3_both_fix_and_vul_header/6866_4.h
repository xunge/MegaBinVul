#include <stdint.h>
#include <stddef.h>

typedef int64_t i64;
typedef uint8_t u8;
typedef uint32_t u32;

typedef struct deark deark;
typedef struct prismctx prismctx;
typedef struct atari_img_decode_data atari_img_decode_data;

struct prismctx {
    i64 pal_size;
    u32 pal[256];
};

struct atari_img_decode_data {
    int bpp;
};

#define DE_MAKE_RGB(r, g, b) (((r)<<16)|((g)<<8)|(b))
#define DE_CHAR_RIGHTARROW "→"

static void de_zeromem(void *ptr, size_t n);
static uint16_t de_getu16be(size_t offset);
static u8 de_scale_1000_to_255(i64 val);
static int de_snprintf(char *str, size_t size, const char *format, ...);
static void de_dbg_pal_entry2(deark *c, i64 idx, u32 clr, const char *s1, const char *s2, const char *s3);
static unsigned int map_vdi_pal(int bpp, unsigned int idx);