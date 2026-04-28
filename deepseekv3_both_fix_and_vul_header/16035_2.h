#include <stddef.h>

struct pci_dev;

struct saa7134_dev {
    struct pci_dev *pci;
    struct {
        void *timeout;
        void *pt;
    } ts_q;
};

void del_timer_sync(void *timer);
void saa7134_pgtable_free(struct pci_dev *pci, void *pt);