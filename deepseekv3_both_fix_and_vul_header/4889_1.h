#include <unistd.h>

#define MK_FALSE 0
#define mk_unlikely(x) (x)

struct config {
    int fdt;
};

struct session_request {
    int fd_file;
    int vhost_fdt_id;
    unsigned int vhost_fdt_hash;
    void *host_conf;
};

struct vhost_fdt_hash_table {
    int av_slots;
};

struct vhost_fdt_hash_chain {
    int fd;
    unsigned int hash;
    int readers;
};

extern struct config *config;

static inline struct vhost_fdt_hash_table *mk_vhost_fdt_table_lookup(int id, void *host_conf) {
    return NULL;
}

static inline struct vhost_fdt_hash_chain *mk_vhost_fdt_chain_lookup(unsigned int hash, struct vhost_fdt_hash_table *ht) {
    return NULL;
}