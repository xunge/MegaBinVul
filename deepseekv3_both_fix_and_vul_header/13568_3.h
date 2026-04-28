#include <stdbool.h>
#include <stddef.h>
#include <time.h>

#define PAGE_SIZE 4096
#define ETIME 62

struct device;

struct pci_dev {
    struct device *dev;
};

struct r592_device {
    void *io_thread;
    void *detect_timer;
    void *host;
    struct memstick_request *req;
    void *dummy_dma_page;
    unsigned long dummy_dma_page_physical_address;
    unsigned int irq;
    void *mmio;
};

struct memstick_request {
    int error;
};

void *pci_get_drvdata(struct pci_dev *pdev);
void kthread_stop(void *kthread);
void del_timer_sync(void *timer);
void r592_enable_device(struct r592_device *dev, bool enable);
int memstick_next_req(void *host, struct memstick_request **req);
void memstick_remove_host(void *host);
void dma_free_coherent(struct device *dev, size_t size, void *vaddr, unsigned long dma_handle);
void free_irq(unsigned int irq, void *dev_id);
void iounmap(void *addr);
void pci_release_regions(struct pci_dev *pdev);
void pci_disable_device(struct pci_dev *pdev);
void memstick_free_host(void *host);