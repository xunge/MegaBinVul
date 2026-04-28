#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>

struct vmctx;
struct pci_vdev {
    void *arg;
};
struct gpio_chip {
    // Minimal definition needed for compilation
    // Actual implementation may contain more fields
    int dummy;  
};
struct virtio_gpio {
    pthread_mutex_t mtx;
    int nchip;
    struct gpio_chip *chips;
};

extern bool virtio_gpio_is_active;
void gpio_irq_deinit(struct virtio_gpio *gpio);
void native_gpio_close_chip(struct gpio_chip *chip);
void DPRINTF(const char *fmt, ...);