#include <pthread.h>
#include <unistd.h>

struct gp_pool {
    int shutdown;
    pthread_mutex_t lock;
    struct gp_query *reply_list;
    struct gp_thread *free_list;
    struct gp_thread *busy_list;
    int sig_pipe[2];
};

struct gp_thread {
    struct gp_pool *pool;
    struct gp_query *query;
    pthread_mutex_t cond_mutex;
    pthread_cond_t cond_wakeup;
};

struct gp_query {
    void *conn;
    void *buffer;
    size_t buflen;
    struct gp_query *next;
};

#define LIST_DEL(list, item) 
#define LIST_ADD(list, item) 

#define GPDEBUGN(level, fmt, ...) 
#define GPERROR(msg) 

void gp_debug_set_conn_id(int id);
int gp_conn_get_cid(void *conn);
void gp_handle_query(struct gp_pool *pool, struct gp_query *q);