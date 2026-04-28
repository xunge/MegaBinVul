#include <stdlib.h>
#include <stddef.h>

#define ECRYPTFS_MAX_NUM_USERS 1024
#define ECRYPTFS_MSG_CTX_STATE_FREE 0
#define GFP_KERNEL 0
#define KERN_WARNING 0
#define KERN_ERR 0
#define ENOMEM 12

extern int ecryptfs_number_of_users;
extern int ecryptfs_hash_bits;
extern int ecryptfs_hash_buckets;
extern int ecryptfs_message_buf_len;
extern int ecryptfs_msg_counter;

struct mutex {
    int dummy;
};

struct hlist_head {
    int dummy;
};

struct list_head {
    int dummy;
};

struct ecryptfs_msg_ctx {
    struct list_head node;
    struct list_head daemon_out_list;
    struct mutex mux;
    int index;
    int state;
    int counter;
    void *task;
    void *msg;
};

extern struct mutex ecryptfs_daemon_hash_mux;
extern struct mutex ecryptfs_msg_ctx_lists_mux;
extern struct hlist_head *ecryptfs_daemon_hash;
extern struct list_head ecryptfs_msg_ctx_free_list;
extern struct ecryptfs_msg_ctx *ecryptfs_msg_ctx_arr;

#define printk(...)
#define mutex_init(...)
#define mutex_lock(...)
#define mutex_unlock(...)
#define kmalloc(size, flags) malloc(size)
#define INIT_HLIST_HEAD(...)
#define INIT_LIST_HEAD(...)
#define list_add_tail(...)

int ecryptfs_init_ecryptfs_miscdev(void);
int ecryptfs_release_messaging(void);