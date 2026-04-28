#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

typedef enum {
  GST_MATROSKA_TRACK_COMPRESSION_ALGORITHM_ZLIB,
  GST_MATROSKA_TRACK_COMPRESSION_ALGORITHM_BZLIB,
  GST_MATROSKA_TRACK_COMPRESSION_ALGORITHM_LZO1X,
  GST_MATROSKA_TRACK_COMPRESSION_ALGORITHM_HEADERSTRIP
} GstMatroskaTrackCompressionAlgorithm;

typedef struct {
  uint8_t *comp_settings;
  size_t comp_settings_length;
} GstMatroskaTrackEncoding;

#define G_MAXUINT32 UINT32_MAX
#define G_MAXUINT UINT32_MAX
#define G_MAXSIZE SIZE_MAX
#define G_MAXINT INT_MAX
#define MAX_DECOMPRESS_SIZE (1024 * 1024 * 1024)

#define GST_WARNING(...)
#define GST_ERROR(...)
#define g_malloc malloc
#define g_realloc realloc
#define g_free free
#define g_assert(expr)

typedef uint8_t guint8;
typedef size_t gsize;
typedef bool gboolean;
typedef void* gpointer;
typedef int gint;
typedef unsigned int guint;

#define TRUE true
#define FALSE false

enum {
  LZO_OUTPUT_FULL = 1,
  LZO_ERROR = -1
};

int lzo1x_decode(void* dst, int* dst_len, const void* src, int* src_len);