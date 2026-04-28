#include <stdint.h>
#include <stddef.h>

typedef int gboolean;
typedef unsigned char guchar;
typedef int64_t gint64;
typedef size_t gsize;

#define SCALE_SHIFT 16

#define CLAMP(x, low, high) (((x) > (high)) ? (high) : (((x) < (low)) ? (low) : (x)))

#define INNER_LOOP(src_channels, dest_channels, body) \
  do { \
    xmax = render_x1 * x_step + x_step / 2; \
    xstart = x; \
    xstop = xmax; \
    x_pos = (xstart >> SCALE_SHIFT); \
    p = src + x_pos * src_channels; \
    for (x_pos = xstart; x_pos < xstop; x_pos += x_step) \
    { \
      body \
      p += src_channels; \
      dest += dest_channels; \
    } \
  } while (0)