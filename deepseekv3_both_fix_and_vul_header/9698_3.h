#include <stddef.h>

#define DBG2 2
#define CONFIG_CIFS_DFS_UPCALL
#define CONFIG_CIFS_UPCALL
#define __exit

struct file_system_type {
    const char *name;
    int fs_flags;
};

struct key_type {
    const char *name;
    size_t def_datalen;
};

static struct file_system_type cifs_fs_type;
static struct key_type key_type_dns_resolver;
static struct key_type cifs_spnego_key_type;

void cFYI(int level, const char *fmt, ...);
void cifs_proc_clean(void);
void cifs_dfs_release_automount_timer(void);
void unregister_key_type(struct key_type *);
void unregister_filesystem(struct file_system_type *);
void cifs_destroy_inodecache(void);
void cifs_destroy_mids(void);
void cifs_destroy_request_bufs(void);