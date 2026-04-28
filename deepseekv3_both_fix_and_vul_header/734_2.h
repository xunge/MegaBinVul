#include <stdint.h>
#include <string.h>

#define LSI_ISTAT1_SRUN 0x01
#define LSI_MAX_INSN 10000
#define LSI_SIST0_UDC 0x04
#define LSI_SIST0_MA 0x02
#define LSI_SIST1_STO 0x80
#define LSI_SCNTL1_CON 0x08
#define LSI_SCNTL1_IARB 0x10
#define LSI_SSTAT0_WOA 0x01
#define LSI_SOCL_ATN 0x02
#define LSI_SBCL_ATN 0x02
#define LSI_SBCL_BSY 0x01
#define LSI_SBCL_ACK 0x01
#define LSI_ISTAT0_SIGP 0x02
#define LSI_ISTAT0_INTF 0x01
#define LSI_DSTAT_SIR 0x04
#define LSI_DSTAT_IID 0x01
#define LSI_DSTAT_SSI 0x02
#define LSI_DCNTL_SSM 0x01
#define LOG_GUEST_ERROR 0
#define LOG_UNIMP 0

#define PHASE_MASK 0x07
#define PHASE_DO 0x00
#define PHASE_DI 0x01
#define PHASE_CMD 0x02
#define PHASE_ST 0x03
#define PHASE_MO 0x06
#define PHASE_MI 0x07

#define LSI_NOWAIT 0
#define LSI_DMA_SCRIPTS 1
#define LSI_DMA_IN_PROGRESS 2

typedef struct LSIState {
    uint32_t istat1;
    uint32_t sien0;
    uint32_t dsp;
    uint32_t dsps;
    uint32_t dcmd;
    uint32_t sist1;
    uint32_t dbc;
    uint32_t rbc;
    uint32_t ia;
    uint32_t dsa;
    uint32_t scratch[32];
    uint32_t mmrs;
    uint32_t mmws;
    uint32_t sfs;
    uint32_t drs;
    uint32_t sbms;
    uint32_t dbms;
    uint32_t sstat1;
    uint32_t dnad;
    uint32_t dnad64;
    uint32_t waiting;
    uint32_t dfifo;
    uint32_t ctest5;
    uint32_t sbc;
    uint32_t ua;
    uint32_t scntl1;
    uint32_t sstat0;
    uint32_t socl;
    uint32_t sbcl;
    uint32_t carry;
    uint32_t sfbr;
    uint32_t istat0;
    uint32_t dcntl;
    uint32_t temp;
    uint32_t adder;
    uint32_t sdid;
    uint32_t select_tag;
    void *bus;
    void *current;
} LSIState;

typedef struct PCIDevice {
    // Minimal PCI device structure
} PCIDevice;

typedef struct lsi_request {
    // Minimal request structure
} lsi_request;

static inline uint32_t sextract32(uint32_t value, int start, int length) {
    return (int32_t)(value << (32 - start - length)) >> (32 - length);
}

static inline uint32_t cpu_to_le32(uint32_t x) {
    return x;
}

static void qemu_log_mask(int mask, const char *fmt, ...) {
    // Empty implementation
}

static void trace_lsi_execute_script_stop(void) {}
static void trace_lsi_execute_script(uint32_t dsp, uint32_t insn, uint32_t addr) {}
static void trace_lsi_execute_script_blockmove_delayed(void) {}
static void trace_lsi_execute_script_blockmove_badphase(const char *phase1, const char *phase2) {}
static void trace_lsi_execute_script_io_alreadyreselected(void) {}
static void trace_lsi_execute_script_io_selected(int id, const char *atn) {}
static void trace_lsi_execute_script_io_disconnect(void) {}
static void trace_lsi_execute_script_io_set(const char *atn, const char *ack, const char *tm, const char *cc) {}
static void trace_lsi_execute_script_io_clear(const char *atn, const char *ack, const char *tm, const char *cc) {}
static void trace_lsi_execute_script_io_opcode(const char *op, int reg, const char *oper, uint8_t data, uint8_t sfbr, const char *sfbr_str) {}
static void trace_lsi_execute_script_tc_nop(void) {}
static void trace_lsi_execute_script_tc_delayedselect_timeout(void) {}
static void trace_lsi_execute_script_tc_compc(int cond) {}
static void trace_lsi_execute_script_tc_compp(const char *phase1, char cmp, const char *phase2) {}
static void trace_lsi_execute_script_tc_compd(uint8_t sfbr, uint8_t mask, char cmp, uint8_t val) {}
static void trace_lsi_execute_script_tc_jump(uint32_t addr) {}
static void trace_lsi_execute_script_tc_call(uint32_t addr) {}
static void trace_lsi_execute_script_tc_return(uint32_t addr) {}
static void trace_lsi_execute_script_tc_interrupt(uint32_t dsps) {}
static void trace_lsi_execute_script_tc_illegal(void) {}
static void trace_lsi_execute_script_tc_cc_failed(void) {}
static void trace_lsi_execute_script_mm_load(int reg, int n, uint32_t addr, int data) {}
static void trace_lsi_execute_script_mm_store(int reg, int n, uint32_t addr) {}

static const char *scsi_phase_name(int stat) {
    return "";
}

static PCIDevice *PCI_DEVICE(void *s) {
    return (PCIDevice *)s;
}

static uint32_t read_dword(LSIState *s, uint32_t addr) {
    return 0;
}

static void pci_dma_read(PCIDevice *dev, uint32_t addr, void *buf, int len) {}
static void pci_dma_write(PCIDevice *dev, uint32_t addr, void *buf, int len) {}

static void lsi_script_scsi_interrupt(LSIState *s, int stat0, int stat1) {}
static void lsi_disconnect(LSIState *s) {}
static void lsi_stop_script(LSIState *s) {}
static void lsi_do_dma(LSIState *s, int out) {}
static void lsi_do_command(LSIState *s) {}
static void lsi_do_status(LSIState *s) {}
static void lsi_do_msgout(LSIState *s) {}
static void lsi_do_msgin(LSIState *s) {}
static void lsi_bad_selection(LSIState *s, int id) {}
static void lsi_set_phase(LSIState *s, int phase) {}
static void lsi_wait_reselect(LSIState *s) {}
static void lsi_reselect(LSIState *s, lsi_request *p) {}
static lsi_request *get_pending_req(LSIState *s) { return NULL; }
static void lsi_script_dma_interrupt(LSIState *s, int stat) {}
static void lsi_update_irq(LSIState *s) {}
static void lsi_memcpy(LSIState *s, uint32_t dest, uint32_t src, int count) {}
static uint8_t lsi_reg_readb(LSIState *s, int reg) { return 0; }
static void lsi_reg_writeb(LSIState *s, int reg, uint8_t val) {}
static int lsi_dma_40bit(LSIState *s) { return 0; }
static int lsi_dma_ti64bit(LSIState *s) { return 0; }
static int lsi_dma_64bit(LSIState *s) { return 0; }
static int lsi_irq_on_rsl(LSIState *s) { return 0; }
static int scsi_device_find(void *bus, int channel, int target, int lun) { return 0; }