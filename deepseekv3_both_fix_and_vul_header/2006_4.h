#include <stdlib.h>
#include <stdint.h>
#include <stdatomic.h>
#include <stddef.h>

#define TPM_BUFSIZE 4096
#define GFP_KERNEL 0
#define ENODEV 19
#define EBUSY 16
#define ENOMEM 12

typedef uint8_t u8;

struct device {
    int dummy;
};

struct miscdevice {
    int minor;
};

struct inode {
    unsigned int i_rdev;
};

struct file {
    void *private_data;
};

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

struct tpm_chip {
    struct device *dev;
    struct miscdevice miscdev;
    struct list_head list;
    unsigned long is_open;
    u8 *data_buffer;
    atomic_int data_pending;
    struct {
        struct miscdevice miscdev;
    } vendor;
};

extern struct list_head tpm_chip_list;

#define iminor(inode) ((inode)->i_rdev & 0xff)
#define test_and_set_bit(nr, addr) (*(addr) |= (1UL << (nr)), 0)
#define clear_bit(nr, addr) (*(addr) &= ~(1UL << (nr)))
#define dev_dbg(dev, fmt, ...)
#define get_device(dev)
#define put_device(dev)
#define rcu_read_lock()
#define rcu_read_unlock()
#define kmalloc(size, flags) malloc(size)
#define atomic_set(v, i) atomic_store(v, i)

static inline struct tpm_chip* list_entry(struct list_head *ptr) {
    return (struct tpm_chip*)((char*)ptr - offsetof(struct tpm_chip, list));
}

#define list_for_each_entry_rcu(pos, head, member) \
    for (pos = list_entry(head); pos; pos = list_entry(pos->member.next))