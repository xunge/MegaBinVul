#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

#define SNDRV_SEQ_MAX_PORTS 256
#define GFP_KERNEL 0
#define THIS_MODULE ((struct module *)0)

struct snd_seq_addr {
    int client;
    int port;
};

struct port_subs_info {
    int dummy;
};

struct snd_use_lock {
    int dummy;
};

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

struct snd_seq_client_port {
    struct snd_seq_addr addr;
    struct module *owner;
    char name[32];
    struct list_head list;
    struct port_subs_info c_src;
    struct port_subs_info c_dest;
    struct snd_use_lock use_lock;
};

struct snd_seq_client {
    int number;
    int num_ports;
    pthread_mutex_t ports_mutex;
    pthread_spinlock_t ports_lock;
    struct list_head ports_list_head;
};

#define list_for_each_entry(pos, head, member) \
    for (pos = (typeof(*pos)*)((char*)(head)->next - offsetof(typeof(*pos), member)); \
         &pos->member != (head); \
         pos = (typeof(*pos)*)((char*)pos->member.next - offsetof(typeof(*pos), member)))

#define offsetof(TYPE, MEMBER) ((size_t)&((TYPE *)0)->MEMBER)

static inline void *kzalloc(size_t size, int flags) {
    return calloc(1, size);
}

static inline void snd_use_lock_init(struct snd_use_lock *lock) {}
static inline void port_subs_info_init(struct port_subs_info *info) {}

static inline void mutex_lock(pthread_mutex_t *mutex) {}
static inline void mutex_unlock(pthread_mutex_t *mutex) {}

static inline void write_lock_irqsave(pthread_spinlock_t *lock, unsigned long flags) {}
static inline void write_unlock_irqrestore(pthread_spinlock_t *lock, unsigned long flags) {}

static inline void list_add_tail(struct list_head *new, struct list_head *head) {
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}

#define snd_BUG_ON(cond) (cond)
#define pr_warn(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)