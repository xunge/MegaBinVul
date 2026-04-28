#include <stdint.h>
#include <string.h>

struct e1000_tx_desc {
    union {
        uint32_t data;
        struct {
            uint16_t special;
            uint16_t css;
        } fields;
    } upper;
    union {
        uint32_t data;
    } lower;
    uint64_t buffer_addr;
};

struct e1000_context_desc {
    uint32_t cmd_and_length;
    uint32_t tso_mss;
    uint32_t status;
    uint32_t hdr_addr;
};

struct e1000_tx {
    uint8_t data[4096];
    uint8_t header[256];
    uint16_t vlan_header[2];
    uint32_t size;
    uint32_t sum_needed;
    uint32_t tso_frames;
    uint16_t vlan_needed;
    uint16_t cptse;
    struct {
        uint32_t hdr_len;
        uint32_t mss;
    } tso_props;
    struct {
        uint32_t hdr_len;
        uint32_t mss;
    } props;
};

typedef struct E1000State {
    uint32_t mac_reg[128];
    uint32_t mit_ide;
    uint8_t use_tso_for_migration;
    struct e1000_tx tx;
} E1000State;

typedef struct PCIDevice PCIDevice;

#define E1000_TXD_CMD_DEXT    0x00200000
#define E1000_TXD_DTYP_D      0x00100000
#define E1000_TXD_CMD_TSE     0x01000000
#define E1000_TXD_CMD_EOP     0x00000001
#define E1000_TXD_CMD_IDE     0x00000004

#define VET 0x00

static inline uint32_t le32_to_cpu(uint32_t x) { return x; }
static inline uint64_t le64_to_cpu(uint64_t x) { return x; }
static inline uint16_t le16_to_cpu(uint16_t x) { return x; }
static inline void stw_be_p(uint16_t *p, uint16_t v) { *p = v; }

static void e1000x_read_tx_ctx_descr(struct e1000_context_desc *xp, void *props);
static int e1000x_vlan_enabled(uint32_t *mac_reg);
static int e1000x_is_vlan_txd(uint32_t txd_lower);
static void pci_dma_read(PCIDevice *d, uint64_t addr, void *buf, size_t len);
static void xmit_seg(E1000State *s);
#define MIN(a, b) ((a) < (b) ? (a) : (b))