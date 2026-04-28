#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <stddef.h>

#define KERN_ERR
#define printk(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define mutex_lock(lock) pthread_mutex_lock(lock)
#define mutex_unlock(lock) pthread_mutex_unlock(lock)
#define kfree(ptr) free(ptr)

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct hlist_head {
    struct hlist_node *first;
};

struct ecryptfs_msg_ctx {
    pthread_mutex_t mux;
    void *msg;
};

struct ecryptfs_daemon {
    struct hlist_node euid_chain;
};

#define hlist_for_each_entry(pos, elem, head, member) \
    for (elem = (head)->first; elem && (pos = ((struct ecryptfs_daemon *)((char *)elem - offsetof(struct ecryptfs_daemon, member)))); elem = elem->next)

extern struct ecryptfs_msg_ctx *ecryptfs_msg_ctx_arr;
extern struct hlist_head *ecryptfs_daemon_hash;
extern int ecryptfs_message_buf_len;
extern int ecryptfs_hash_bits;
extern int ecryptfs_hash_buckets;
extern pthread_mutex_t ecryptfs_msg_ctx_lists_mux;
extern pthread_mutex_t ecryptfs_daemon_hash_mux;

int ecryptfs_exorcise_daemon(struct ecryptfs_daemon *daemon);
void ecryptfs_destroy_ecryptfs_miscdev(void);