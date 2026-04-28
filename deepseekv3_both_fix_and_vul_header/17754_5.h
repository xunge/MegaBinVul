#include <stdatomic.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <poll.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

#define LOOP_UP 10
#define AGOO_ERR_INIT {0}

struct _agooErr {
    char *msg;
};

struct agooBind {
    int fd;
    char *id;
    struct agooBind *next;
};

struct agooCon {
    int sock;
    char *remote;
};

struct {
    atomic_int running;
    atomic_int con_cnt;
    int loop_max;
    int loop_cnt;
    bool active;
    struct agooBind *binds;
    void *con_queue;
} agoo_server;

struct {
    const char *name;
} agoo_error_cat, agoo_con_cat;

static struct agooCon *agoo_con_create(struct _agooErr *err, int sock, uint64_t cnt, struct agooBind *b);
static void agoo_err_clear(struct _agooErr *err);
static void agoo_log_cat(void *cat, const char *fmt, ...);
static void agoo_bind_close(struct agooBind *b);
static void agoo_queue_push(void *queue, void *item);
static void add_con_loop(void);

typedef struct agooCon *agooCon;
typedef struct agooBind *agooBind;