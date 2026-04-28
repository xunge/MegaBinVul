#include <stdint.h>
#include <stdlib.h>
#include <pthread.h>

typedef int64_t i64;
typedef unsigned char uchar;

#define PRId64 "lld"
#define SALT_LEN 16
#define CTYPE_NONE 0
#define LRZ_DECRYPT 0
#define ENCRYPT 0

struct uncomp_thread {
    // Add necessary fields here
};

struct stream {
    int total_threads;
    int base_thread;
    int uthread_no;
    int unext_thread;
    i64 last_head;
};

struct stream_info {
    struct uncomp_thread *ucthreads;
    int num_streams;
    int fd;
    char chunk_bytes;
    struct stream *s;
    i64 size;
    i64 initial_pos;
    i64 total_read;
};

typedef struct rzip_control {
    pthread_t *pthreads;
    int threads;
    int major_version;
    int eof;
    i64 st_size;
    // Add other necessary fields here
} rzip_control;

#define unlikely(x) (x)
#define likely(x) (x)

void *calloc(size_t nmemb, size_t size);
void dealloc(void *ptr);
void fatal(const char *msg);
int read_u8(rzip_control *control, int f, uchar *c);
int read_val(rzip_control *control, int f, i64 *val, int bytes);
int read_buf(rzip_control *control, int f, uchar *buf, int len);
int decrypt_header(rzip_control *control, uchar *enc_head, uchar *c, i64 *v1, i64 *v2, i64 *last_head, int flag);
i64 get_readseek(rzip_control *control, int f);
void print_maxverbose(const char *fmt, ...);
void print_err(const char *fmt, ...);

uint64_t le64toh(uint64_t x);