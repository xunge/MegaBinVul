#include <stdint.h>
#include <pthread.h>
#include <poll.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

typedef struct xlator_t {
    char *name;
    void *private;
} xlator_t;

typedef struct fuse_private_t {
    pthread_mutex_t sync_mutex;
    pthread_cond_t sync_cond;
    int event_recvd;
    int fuse_thread_started;
    pthread_t *fuse_thread;
    int reader_thread_count;
    int mount_finished;
    int status_pipe[2];
} fuse_private_t;

typedef struct glusterfs_graph_t {
    int id;
} glusterfs_graph_t;

typedef enum {
    GF_EVENT_GRAPH_NEW,
    GF_EVENT_CHILD_UP,
    GF_EVENT_CHILD_DOWN,
    GF_EVENT_CHILD_CONNECTING,
    GF_EVENT_AUTH_FAILED
} gf_event_t;

typedef enum {
    _gf_false,
    _gf_true
} gf_boolean_t;

#define GF_CALLOC(n, s, t) calloc(n, s)
#define GF_LOG_WARNING 1
#define GF_LOG_ERROR 2
#define GF_LOG_DEBUG 3

void gf_log(const char *name, int level, const char *fmt, ...);
int fuse_graph_setup(xlator_t *this, glusterfs_graph_t *graph);
void *fuse_thread_proc(void *arg);
int gf_thread_create(pthread_t *thread, const void *attr, void *(*start_routine)(void *), void *arg, const char *name);
int fuse_get_mount_status(xlator_t *this);
void fini(xlator_t *this);