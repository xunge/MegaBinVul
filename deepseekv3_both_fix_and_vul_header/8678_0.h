#include <stdint.h>
#include <assert.h>

#define VMW_IS_MULTIREG_ADDR(addr, reg, num, stride) \
    ((addr) >= (reg) && (addr) < (reg) + (num) * (stride) && \
     ((addr) - (reg)) % (stride) == 0)

#define VMW_MULTIREG_IDX_BY_ADDR(addr, reg, stride) \
    (((addr) - (reg)) / (stride))

#define VMXNET3_REG_TXPROD 0
#define VMXNET3_REG_IMR 0
#define VMXNET3_REG_RXPROD 0
#define VMXNET3_REG_RXPROD2 0
#define VMXNET3_REG_ALIGN 4
#define VMXNET3_DEVICE_MAX_TX_QUEUES 8
#define VMXNET3_DEVICE_MAX_RX_QUEUES 8
#define VMXNET3_MAX_INTRS 8

#define VMW_CBPRN(fmt, ...) 
#define VMW_WRPRN(fmt, ...) 

typedef uint64_t hwaddr;

typedef struct VMXNET3State {
    int device_active;
    int txq_num;
} VMXNET3State;

static void vmxnet3_process_tx_queue(VMXNET3State *s, int tx_queue_idx);
static void vmxnet3_on_interrupt_mask_changed(VMXNET3State *s, int l, uint64_t val);