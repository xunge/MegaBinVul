#include <stddef.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <linux/errno.h>
#include <pthread.h>

struct rdma_route {
    struct {
        struct sockaddr_storage src_addr;
    } addr;
};

struct rdma_cm_id {
    struct rdma_route route;
    void *device;
};

struct rdma_id_private {
    struct rdma_cm_id id;
    int backlog;
    int reuseaddr;
    void *bind_list;
    void *cma_dev;
    int state;
};

enum {
    RDMA_CM_ADDR_BOUND,
    RDMA_CM_LISTEN,
    RDMA_CM_IDLE
};

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define WARN_ON(condition) (condition)

static inline int cma_comp_exch(struct rdma_id_private *id_priv, int old, int new) {
    int prev = id_priv->state;
    if (prev == old)
        id_priv->state = new;
    return prev == old;
}

static inline int rdma_bind_addr(struct rdma_cm_id *id, struct sockaddr *addr) {
    return 0;
}

static inline int cma_check_port(void *bind_list, struct rdma_id_private *id_priv, int port) {
    return 0;
}

static inline int cma_ib_listen(struct rdma_id_private *id_priv) {
    return 0;
}

static inline int cma_iw_listen(struct rdma_id_private *id_priv, int backlog) {
    return 0;
}

static inline int cma_listen_on_all(struct rdma_id_private *id_priv) {
    return 0;
}

static inline struct sockaddr *cma_src_addr(struct rdma_id_private *id_priv) {
    return (struct sockaddr *)&id_priv->id.route.addr.src_addr;
}

static inline int rdma_cap_ib_cm(void *device, int version) {
    return 0;
}

static inline int rdma_cap_iw_cm(void *device, int version) {
    return 0;
}