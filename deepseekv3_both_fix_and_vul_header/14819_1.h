#include <stdint.h>
#include <stddef.h>

#define SCALE_SHIFT 16

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define CLAMP(x, low, high) (((x) > (high)) ? (high) : (((x) < (low)) ? (low) : (x)))

typedef uint32_t guint32;
typedef uint8_t guchar;
typedef int64_t gint64;
typedef size_t gsize;
typedef int gboolean;