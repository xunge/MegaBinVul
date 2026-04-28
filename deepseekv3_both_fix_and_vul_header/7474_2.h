#include <stdint.h>
#include <stdbool.h>

typedef uint32_t __u32;

struct nci_dev {
    unsigned long flags;
    int req_lock;
};

#define NCI_UP 0
#define ENETDOWN 1

#define test_bit(nr, addr) ((*addr) & (1UL << (nr)))

static inline void mutex_lock(int *lock) { *lock = 1; }
static inline void mutex_unlock(int *lock) { *lock = 0; }
int __nci_request(struct nci_dev *ndev, void (*req)(struct nci_dev *, const void *), const void *opt, __u32 timeout);