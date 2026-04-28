#include <pthread.h>
#include <stdint.h>
#include <errno.h>

typedef enum { FALSE, TRUE } my_bool;

typedef struct comp_thread_ctxt_t {
    uint32_t num;
    my_bool started;
    my_bool cancelled;
    my_bool data_avail;
    char *to;
    pthread_mutex_t ctrl_mutex;
    pthread_cond_t ctrl_cond;
    pthread_mutex_t data_mutex;
    pthread_cond_t data_cond;
    pthread_t id;
} comp_thread_ctxt_t;

#define COMPRESS_CHUNK_SIZE 8192
#define MY_QLZ_COMPRESS_OVERHEAD 400

#define MY_FAE 0
#define MYF(flags) (flags)

typedef unsigned int uint;

extern void *my_malloc(size_t size, int flags);
extern void my_free(void *ptr);
extern void msg(const char *format, ...);
extern void *compress_worker_thread_func(void *arg);