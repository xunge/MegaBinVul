#include <stdlib.h>
#include <string.h>

typedef struct tvbuff tvbuff_t;
typedef struct z_stream_s {
    void     *next_in;
    unsigned avail_in;
    void     *next_out;
    unsigned avail_out;
    char     *msg;
    void     *state;
    void     *zalloc;
    void     *zfree;
    void     *opaque;
    int      data_type;
    unsigned long adler;
    unsigned long reserved;
} z_stream;
typedef z_stream *z_streamp;
typedef unsigned char Bytef;
typedef unsigned char guint8;
typedef int gint;
typedef unsigned int guint;
typedef unsigned short guint16;

#define MAX_WBITS 15
#define TVB_Z_MIN_BUFSIZ 1024
#define TVB_Z_MAX_BUFSIZ (10*1024*1024)

#define Z_OK            0
#define Z_STREAM_END    1
#define Z_BUF_ERROR    (-5)
#define Z_DATA_ERROR    (-3)
#define Z_SYNC_FLUSH    2

#define Z_DEFLATED 8

extern void *g_new0(size_t size, size_t nmemb);
extern void *g_malloc0(size_t size);
extern void *g_memdup(const void *mem, size_t byte_size);
extern char *g_strdup(const char *str);
extern void g_free(void *ptr);

extern tvbuff_t *tvb_new_real_data(guint8 *data, guint length, guint reported_length);
extern void tvb_set_free_cb(tvbuff_t *tvb, void (*free_cb)(void *));
extern void *tvb_memdup(void *scope, const tvbuff_t *tvb, gint offset, size_t length);
extern guint tvb_captured_length_remaining(const tvbuff_t *tvb, gint offset);

#ifndef CLAMP
#define CLAMP(a, min, max) ((a) < (min) ? (min) : ((a) > (max) ? (max) : (a)))
#endif

/* Zlib function prototypes */
int inflateInit2(z_streamp strm, int windowBits);
int inflate(z_streamp strm, int flush);
int inflateEnd(z_streamp strm);
int inflateReset(z_streamp strm);

/* Helper macro for g_new0 */
#define g_new0(type, count) ((type*)g_new0(sizeof(type), (count)))