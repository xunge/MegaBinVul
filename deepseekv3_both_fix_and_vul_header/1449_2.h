#include <stddef.h>
#include <stdint.h>

struct inode;
struct file {
    void *private_data;
};

struct printer_dev {
    uintptr_t lock;
    int printer_cdev_open;
    unsigned int printer_status;
    uintptr_t kref;
};

#define PRINTER_SELECTED 0x01

void printer_dev_free(uintptr_t *kref);
void spin_lock_irqsave(uintptr_t *lock, unsigned long flags);
void spin_unlock_irqrestore(uintptr_t *lock, unsigned long flags);
void kref_put(uintptr_t *kref, void (*func)(uintptr_t *));
void DBG(struct printer_dev *dev, const char *msg);