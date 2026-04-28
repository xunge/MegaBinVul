#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>

typedef uint64_t dma_addr_t;

#define MIN_BUF_SIZE 60
#define MAXIMUM_ETHERNET_VLAN_SIZE 1522
#define E1000_RCTL_EN 0x2
#define E1000_RCTL_LPE 0x20
#define E1000_RCTL_SBP 0x40
#define E1000_RXD_STAT_VP 0x8
#define E1000_RXD_STAT_DD 0x1
#define E1000_RXD_STAT_EOP 0x2
#define E1000_RXD_STAT_IXSM 0x4
#define E1000_ICS_RXO 0x80
#define E1000_ICS_RXT0 0x10
#define E1000_ICS_RXDMT0 0x8

struct e1000_rx_desc {
    uint64_t buffer_addr;
    uint16_t length;
    uint16_t checksum;
    uint8_t status;
    uint8_t errors;
    uint16_t special;
};

typedef struct NetClientState NetClientState;
typedef struct NICState NICState;
typedef struct E1000State E1000State;

struct NetClientState {
    int dummy;
};

struct NICState {
    NetClientState nc;
    void *opaque;
};

struct E1000State {
    uint32_t mac_reg[0x10000];
    size_t rxbuf_size;
    size_t rxbuf_min_shift;
    void *dev;
};

#define DO_UPCAST(type, field, obj) ((type *)(((char *)(obj)) - offsetof(type, field)))

#define RCTL 0x100
#define RDH 0x2810
#define RDT 0x2818
#define RDLEN 0x2808
#define GPRC 0x4074
#define TPR 0x40D0
#define TORL 0x40C0
#define TORH 0x40C4

#define DBGOUT(type, fmt, ...) do {} while (0)
#define RX 0
#define RXERR 1

static int receive_filter(E1000State *s, const uint8_t *buf, size_t size);
static int vlan_enabled(E1000State *s);
static int is_vlan_packet(E1000State *s, const uint8_t *buf);
static uint16_t cpu_to_le16(uint16_t val);
static uint16_t be16_to_cpup(const uint16_t *p);
static uint64_t le64_to_cpu(uint64_t val);
static size_t fcs_len(E1000State *s);
static int e1000_has_rxbufs(E1000State *s, size_t size);
static uint64_t rx_desc_base(E1000State *s);
static void pci_dma_read(void *dev, dma_addr_t addr, void *buf, size_t len);
static void pci_dma_write(void *dev, dma_addr_t addr, const void *buf, size_t len);
static void set_ics(E1000State *s, int index, uint32_t val);