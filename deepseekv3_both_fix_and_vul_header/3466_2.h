#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <stdint.h>

typedef uint32_t __be32;
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define PTR_ERR(x) ((long)(x))
#define RDMA_PS_TCP 0
#define IB_QPT_RC 0
#define RDMA_NODE_IB_CA 0
#define EADDRNOTAVAIL 99

struct rdma_device {
    int node_type;
};

struct rdma_cm_id {
    struct rdma_device *device;
};

struct rdma_cm_id *rdma_create_id(void *a, void *b, int c, int d);
int rdma_bind_addr(struct rdma_cm_id *id, void *addr);
void rdma_destroy_id(struct rdma_cm_id *id);

#define rdsdebug(fmt, ...) printf(fmt, ##__VA_ARGS__)