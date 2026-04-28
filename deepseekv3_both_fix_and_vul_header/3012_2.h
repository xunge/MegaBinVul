#include <stdint.h>
#include <stddef.h>
#include <errno.h>
#include <stdlib.h>

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

struct icmp_packet {
    uint8_t type;
    uint8_t code;
    uint16_t checksum;
    uint32_t rest;
};

struct socket_client {
    struct list_head queue_list;
    int lock;
    int queue_wait;
    size_t queue_len;
    void *private_data;
};

struct socket_packet {
    struct list_head list;
    struct icmp_packet icmp_packet;
    size_t icmp_len;
};

struct file {
    unsigned int f_flags;
    void *private_data;
};

#define O_NONBLOCK 04000
#define EAGAIN 11
#define EINVAL 22
#define EFAULT 14
#define VERIFY_WRITE 1

#define spin_lock_bh(lock) ((void)0)
#define spin_unlock_bh(lock) ((void)0)
#define wait_event_interruptible(wq, cond) (0)
#define access_ok(type, addr, size) (1)
#define copy_to_user(to, from, n) (0)
#define kfree(ptr) free(ptr)
#define list_first_entry(ptr, type, member) ((type *)((char *)(ptr)->next - offsetof(type, member)))
#define list_del(entry) do { \
    (entry)->next->prev = (entry)->prev; \
    (entry)->prev->next = (entry)->next; \
} while (0)

typedef long ssize_t;
typedef long loff_t;
typedef unsigned long size_t;
#define __user