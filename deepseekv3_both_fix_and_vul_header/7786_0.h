#include <stdint.h>
#include <pthread.h>
#include <errno.h>

typedef unsigned int uint;
typedef int my_bool;
#define FALSE 0
#define MY_FAE 0
#define COMPRESS_CHUNK_SIZE 0
#define MY_QLZ_COMPRESS_OVERHEAD 0

typedef struct comp_thread_ctxt_t {
    uint num;
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

void *my_malloc(size_t size, int flags);
void my_free(void *ptr);
void msg(const char *format, ...);
void *compress_worker_thread_func(void *arg);