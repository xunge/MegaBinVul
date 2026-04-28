#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef unsigned long gulong;

struct packet_info {
    void *pool;
};

struct nfs_name_snoop_key_t {
    uint32_t key;
    int fh_length;
    char *fh;
};

struct nfs_name_snoop_t {
    char *name;
    int name_len;
    char *parent;
    int parent_len;
    struct nfs_name_snoop_t *parent_ptr;
    bool fs_cycle;
};

#define DISSECTOR_ASSERT(cond) ((void)0)
#define NFS_MAX_FS_DEPTH 32
#define GPOINTER_TO_UINT(p) ((unsigned int)(uintptr_t)(p))
#define GUINT_TO_POINTER(u) ((void *)(uintptr_t)(u))
#define TRUE true
#define FALSE false

extern void *g_malloc(size_t size);
extern int g_snprintf(char *str, size_t size, const char *format, ...);
extern void *g_hash_table_lookup(void *hash_table, const void *key);
extern void *p_get_proto_data(void *pool, struct packet_info *pinfo, int proto, int id);
extern void p_add_proto_data(void *pool, struct packet_info *pinfo, int proto, int id, void *data);

extern void *nfs_name_snoop_matched;
extern int proto_nfs;

typedef struct nfs_name_snoop_t nfs_name_snoop_t;
typedef struct nfs_name_snoop_key_t nfs_name_snoop_key_t;
typedef struct packet_info packet_info;