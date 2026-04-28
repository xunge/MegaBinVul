#include <stdint.h>
#include <stdbool.h>

#define MSI_ADDR_DEST_ID_MASK    0xFF00
#define MSI_ADDR_DEST_ID_SHIFT   8
#define MSI_ADDR_DESTMODE_MASK   0x10000
#define MSI_DATA_DELIVERY_MODE_MASK  0x700
#define MSI_DATA_DELIVERY_MODE_SHIFT 8
#define MSI_DATA_TRIGGER_MASK    0x800
#define MSI_DATA_TRIGGER_SHIFT   11
#define MSI_DATA_VECTOR_MASK     0xFF

#define IRQ_UNBOUND 0
#define IRQ_MSI_EMU 1

struct domain {
    int event_lock;
};

struct pirq {
    struct {
        struct {
            int emuirq;
        } hvm;
    } arch;
};

void map_domain_emuirq_pirq(struct domain *d, int pirq, int type);
void send_guest_pirq(struct domain *d, struct pirq *info);
void vmsi_deliver(struct domain *d, uint8_t vector, uint8_t dest, uint8_t dest_mode, uint8_t delivery_mode, uint8_t trig_mode);
struct pirq *pirq_info(struct domain *d, int pirq);
void spin_lock(int *lock);
void spin_unlock(int *lock);
int printk(const char *fmt, ...);