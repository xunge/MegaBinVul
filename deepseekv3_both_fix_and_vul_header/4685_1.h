#include <stdint.h>
#include <stddef.h>

#define SCALE_SHIFT 16
#define CLAMP(x, low, high) (((x) > (high)) ? (high) : (((x) < (low)) ? (low) : (x)))

typedef uint8_t guchar;
typedef uint32_t guint32;
typedef int64_t gint64;
typedef size_t gsize;
typedef int gboolean;
#define TRUE 1
#define FALSE 0

static inline int get_check_shift(int check_size) {
    return 0;
}

#define INNER_LOOP(src_channels, dest_channels, body) \
    do { \
        body \
    } while (0)