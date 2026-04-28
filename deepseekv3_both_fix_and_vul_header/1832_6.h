#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define __exit
#define DIPRINTK printf

struct timer_list {
    unsigned long expires;
    void (*function)(unsigned long);
    unsigned long data;
};

struct atm_phy_ops {
    void (*stop)(struct atm_dev *);
};

struct atm_dev {
    struct atm_phy_ops *phy;
};

struct pci_dev;
struct pci_driver;

struct idt77252_dev {
    struct atm_dev *atmdev;
    struct idt77252_dev *next;
    struct timer_list tst_timer;
    struct pci_dev *pcidev;
};

extern struct idt77252_dev *idt77252_chain;
extern struct pci_driver idt77252_driver;

void pci_unregister_driver(struct pci_driver *);
void del_timer_sync(struct timer_list *);
void deinit_card(struct idt77252_dev *);
void pci_disable_device(struct pci_dev *);
void kfree(void *);