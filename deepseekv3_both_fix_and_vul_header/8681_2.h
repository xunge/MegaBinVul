#include <stdint.h>
#include <stddef.h>

typedef struct PCIDevice PCIDevice;

struct Vmxnet3_TxCompDesc {
    uint32_t txdIdx;
    uint8_t gen;
};

struct Vmxnet3_Ring {
    uint8_t gen;
};

struct Vmxnet3_TxQueueDesc {
    struct Vmxnet3_Ring comp_ring;
    uint32_t intr_idx;
};

typedef struct VMXNET3State {
    struct Vmxnet3_TxQueueDesc *txq_descr;
} VMXNET3State;

#define PCI_DEVICE(obj) ((PCIDevice *)(obj))
#define VMW_RIPRN 0
#define smp_wmb() __asm__ volatile("" ::: "memory")

static void VMXNET3_RING_DUMP(int level, const char *ring_name, int qidx, void *ring);
static uint8_t vmxnet3_ring_curr_gen(void *ring);
static void vmxnet3_ring_write_curr_cell(PCIDevice *d, void *ring, void *descr);
static void vmxnet3_inc_tx_completion_counter(VMXNET3State *s, int qidx);
static void vmxnet3_trigger_interrupt(VMXNET3State *s, int intr_idx);