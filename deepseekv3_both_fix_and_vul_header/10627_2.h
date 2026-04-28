#include <stdint.h>
#include <stdbool.h>
#include <sys/uio.h>
#include <stddef.h>

typedef uint64_t hwaddr;
typedef uint64_t dma_addr_t;

struct NetRxPkt;
struct iovec;

typedef struct PCIDevice PCIDevice;

typedef struct E1000ECore {
    PCIDevice *owner;
    void *mac;
    size_t rx_desc_buf_size;
    size_t rx_desc_len;
    void *rx_pkt;
} E1000ECore;

typedef struct E1000E_RingInfo {
    int idx;
} E1000E_RingInfo;

typedef struct E1000E_RxRing {
    E1000E_RingInfo *i;
} E1000E_RxRing;

typedef struct E1000E_RSSInfo {
    // dummy definition
} E1000E_RSSInfo;

typedef struct {
    uint32_t written;
} e1000e_ba_state;

#define E1000_MAX_RX_DESC_LEN 16
#define E1000_MIN_RX_DESC_LEN 8
#define MAX_PS_BUFFERS 4

#define MIN(a, b) ((a) < (b) ? (a) : (b))