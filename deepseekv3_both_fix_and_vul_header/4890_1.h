#include <fcntl.h>
#include <unistd.h>

struct session_request {
    struct {
        char *data;
    } real_path;
    struct {
        int flags_read_only;
    } file_info;
    void *host_conf;
    int vhost_fdt_id;
    unsigned int vhost_fdt_hash;
    int fd_is_fdt;
};

struct vhost_fdt_hash_chain {
    int fd;
    unsigned int hash;
    int readers;
};

struct vhost_fdt_hash_table {
    struct vhost_fdt_hash_chain chain[64];
    int av_slots;
};

struct config {
    int fdt;
};

extern struct config *config;

#define MK_FALSE 0
#define MK_TRUE 1
#define VHOST_FDT_HASHTABLE_CHAINS 64
#define mk_unlikely(x) (x)

struct vhost_fdt_hash_table *mk_vhost_fdt_table_lookup(int id, void *host_conf);
struct vhost_fdt_hash_chain *mk_vhost_fdt_chain_lookup(unsigned int hash, struct vhost_fdt_hash_table *ht);