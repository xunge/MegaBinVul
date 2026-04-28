#include <pthread.h>
#include <stddef.h>

typedef struct xb_wstream_t xb_wstream_t;
typedef struct xb_wstream_file_t xb_wstream_file_t;
typedef struct MY_STAT MY_STAT;

typedef struct ds_file_t ds_file_t;
typedef struct ds_stream_file_t ds_stream_file_t;
typedef struct ds_stream_ctxt_t ds_stream_ctxt_t;
typedef struct ds_ctxt_t ds_ctxt_t;

struct ds_file_t {
    void *ptr;
    const char *path;
};

struct ds_stream_file_t {
    xb_wstream_file_t *xbstream_file;
    ds_stream_ctxt_t *stream_ctxt;
};

struct ds_stream_ctxt_t {
    pthread_mutex_t mutex;
    ds_file_t *dest_file;
    xb_wstream_t *xbstream;
};

struct ds_ctxt_t {
    void *pipe_ctxt;
    void *ptr;
};

#define MY_FAE 0
#define MYF(x) (x)

extern void xb_ad(void *);
extern void *my_malloc(size_t, int);
extern void my_free(void *);
extern void msg(const char *);
extern ds_file_t *ds_open(ds_ctxt_t *, const char *, MY_STAT *);
extern int ds_close(ds_file_t *);
extern xb_wstream_file_t *xb_stream_write_open(xb_wstream_t *, const char *, MY_STAT *, void *, int (*)(void *, const void *, size_t));
extern int my_xbstream_write_callback(void *, const void *, size_t);