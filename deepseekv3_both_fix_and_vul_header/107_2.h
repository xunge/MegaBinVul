#include <stdint.h>
#include <stddef.h>
#include <arpa/inet.h>

#define FALSE 0
#define TRUE 1
#define CHAFA_PIXEL_MAX 256

typedef int gboolean;
typedef uint32_t guint32;
typedef int32_t gint32;
typedef uint16_t guint16;
typedef uint8_t guint8;
typedef void* gpointer;
typedef const void* gconstpointer;
typedef size_t gsize;

typedef struct {
    guint32 header_size;
    guint32 file_version;
    guint32 pixmap_format;
    guint32 pixmap_depth;
    guint32 pixmap_width;
    guint32 pixmap_height;
    guint32 x_offset;
    guint32 byte_order;
    guint32 bitmap_unit;
    guint32 bitmap_bit_order;
    guint32 bitmap_pad;
    guint32 bits_per_pixel;
    guint32 bytes_per_line;
    guint32 visual_class;
    guint32 red_mask;
    guint32 green_mask;
    guint32 blue_mask;
    guint32 bits_per_rgb;
    guint32 color_map_entries;
    guint32 n_colors;
    guint32 window_width;
    guint32 window_height;
    gint32 window_x;
    gint32 window_y;
    guint32 window_border_width;
} XwdHeader;

typedef struct {
    guint32 pixel;
    guint16 red;
    guint16 green;
    guint16 blue;
    guint8 flags;
    guint8 pad;
} XwdColor;

typedef struct {
    XwdHeader header;
    gpointer mapping;
    gconstpointer file_data;
    gsize file_data_len;
    const guint8 *image_data;
} XwdLoader;

#define UNPACK_FIELD_U32(dst, src, field) ((dst)->field = ntohl((src)->field))
#define UNPACK_FIELD_S32(dst, src, field) ((dst)->field = ntohl((src)->field))
#define ASSERT_HEADER(cond) if (!(cond)) return FALSE

static inline gboolean file_mapping_taste(gpointer mapping, void *data, size_t offset, size_t size) {
    return FALSE;
}

static inline gconstpointer file_mapping_get_data(gpointer mapping, gsize *len) {
    return NULL;
}

static inline int compute_pixel_type(XwdLoader *loader) {
    return 0;
}