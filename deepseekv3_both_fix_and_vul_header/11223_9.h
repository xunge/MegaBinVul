#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tvbuff_t tvbuff_t;
typedef signed int gint;
typedef unsigned int guint;
typedef unsigned char guint8;
typedef unsigned short guint16;
typedef unsigned char Bytef;

typedef struct {
    Bytef *next_in;
    guint avail_in;
    Bytef *next_out;
    guint avail_out;
    void *zalloc;
    void *zfree;
    void *opaque;
    int data_type;
    guint adler;
    guint reserved;
} z_stream;
typedef z_stream *z_streamp;

#define MAX_WBITS 15
#define TVB_Z_MIN_BUFSIZ 1024
#define TVB_Z_MAX_BUFSIZ 1048576
#define Z_OK 0
#define Z_STREAM_END 1
#define Z_BUF_ERROR (-5)
#define Z_DATA_ERROR (-3)
#define Z_SYNC_FLUSH 2
#define Z_DEFLATED 8

#define CLAMP(x, low, high) ((x) > (high) ? (high) : ((x) < (low) ? (low) : (x)))

void *g_malloc(size_t size);
void *g_malloc0(size_t size);
void *g_memdup(const void *mem, size_t byte_size);
char *g_strdup(const char *str);
void g_free(void *ptr);
void tvb_memcpy(tvbuff_t *tvb, void *target, int offset, int length);
int tvb_captured_length_remaining(tvbuff_t *tvb, int offset);
tvbuff_t *tvb_new_real_data(guint8 *data, guint length, guint reported_length);
void tvb_set_free_cb(tvbuff_t *tvb, void (*free_cb)(void *));

int inflateInit2(z_streamp strm, int windowBits);
int inflate(z_streamp strm, int flush);
int inflateEnd(z_streamp strm);
int inflateReset(z_streamp strm);

#define g_new0(type, count) ((type*)g_malloc0(sizeof(type)*(count)))