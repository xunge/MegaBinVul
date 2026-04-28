#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define IWL_TRANS_GET_PCIE_TRANS(trans) ((struct iwl_trans_pcie *)(trans)->trans_specific)
#define IWL_CMD_QUEUE_SIZE 256
#define CSR_HW_REV 0x00
#define IWL_PRPH_SCRATCH_RB_SIZE_4K 0x00000001
#define IWL_PRPH_SCRATCH_MTR_MODE 0x00000002
#define IWL_PRPH_MTR_FORMAT_256B 0x00000004
#define IWL_PRPH_SCRATCH_MTR_FORMAT 0x00000008
#define IWL_PRPH_SCRATCH_EARLY_DEBUG_EN 0x00000010
#define IWL_PRPH_SCRATCH_EDBG_DEST_DRAM 0x00000020
#define IWL_NUM_OF_COMPLETION_RINGS 1
#define IWL_NUM_OF_TRANSFER_RINGS 1
#define MQ_RX_TABLE_SIZE 256
#define CSR_CTXT_INFO_ADDR 0x00
#define CSR_IML_DATA_ADDR 0x00
#define CSR_IML_SIZE_ADDR 0x00
#define CSR_CTXT_INFO_BOOT_CTRL 0x00
#define CSR_AUTO_FUNC_BOOT_ENA 0x01
#define UREG_CPU_INIT_RUN 0x00
#define CSR_GP_CNTRL 0x00
#define CSR_AUTO_FUNC_INIT 0x01
#define IWL_DEVICE_FAMILY_AX210 0
#define ENOMEM 12
#define GFP_KERNEL 0

typedef uint32_t u32;
typedef uint16_t u16;
typedef uint64_t u64;
typedef uint64_t dma_addr_t;

struct iwl_trans {
    void *dev;
    void *iml;
    u32 iml_len;
    void *trans_specific;
    struct {
        u32 min_txq_size;
    } *cfg;
    struct {
        int num_blocks;
        struct {
            u64 physical;
            u32 size;
        } fw_mon[1];
    } dbg;
    struct {
        int device_family;
    } *trans_cfg;
};

struct iwl_trans_pcie {
    dma_addr_t prph_scratch_dma_addr;
    dma_addr_t prph_info_dma_addr;
    dma_addr_t ctxt_info_dma_addr;
    dma_addr_t iml_dma_addr;
    struct {
        dma_addr_t bd_dma;
        dma_addr_t rb_stts_dma;
        dma_addr_t tr_tail_dma;
        dma_addr_t cr_tail_dma;
        dma_addr_t used_bd_dma;
    } *rxq;
    struct {
        dma_addr_t dma_addr;
    } **txq;
    int cmd_queue;
    struct iwl_context_info_gen3 *ctxt_info_gen3;
    struct iwl_prph_info *prph_info;
    struct iwl_prph_scratch *prph_scratch;
};

struct iwl_prph_scratch_ctrl_cfg {
    struct {
        u32 version;
        u16 mac_id;
        u16 size;
    } version;
    struct {
        u32 control_flags;
    } control;
    struct {
        u64 free_rbd_addr;
    } rbd_cfg;
    struct {
        u64 hwm_base_addr;
        u32 hwm_size;
    } hwm_cfg;
};

struct iwl_prph_scratch {
    struct iwl_prph_scratch_ctrl_cfg ctrl_cfg;
    void *dram;
};

struct iwl_prph_info {
    // Empty placeholder
};

struct iwl_context_info_gen3 {
    u64 prph_info_base_addr;
    u64 prph_scratch_base_addr;
    u32 prph_scratch_size;
    u64 cr_head_idx_arr_base_addr;
    u64 tr_tail_idx_arr_base_addr;
    u64 cr_tail_idx_arr_base_addr;
    u16 cr_idx_arr_size;
    u16 tr_idx_arr_size;
    u64 mtr_base_addr;
    u64 mcr_base_addr;
    u16 mtr_size;
    u16 mcr_size;
};

struct fw_img {
    // Empty placeholder
};

static inline u16 iwl_read32(struct iwl_trans *trans, u32 reg) { return 0; }
static inline void iwl_write64(struct iwl_trans *trans, u32 reg, u64 val) {}
static inline void iwl_write32(struct iwl_trans *trans, u32 reg, u32 val) {}
static inline void iwl_set_bit(struct iwl_trans *trans, u32 reg, u32 mask) {}
static inline void iwl_write_umac_prph(struct iwl_trans *trans, u32 reg, u32 val) {}
static inline bool iwl_trans_dbg_ini_valid(struct iwl_trans *trans) { return false; }
static inline void iwl_pcie_alloc_fw_monitor(struct iwl_trans *trans, int alloc) {}
static inline int iwl_pcie_init_fw_sec(struct iwl_trans *trans, const struct fw_img *fw, void *dram) { return 0; }
static inline void iwl_enable_fw_load_int_ctx_info(struct iwl_trans *trans) {}
static inline void *dma_alloc_coherent(void *dev, size_t size, dma_addr_t *dma_handle, int gfp) { return NULL; }
static inline void dma_free_coherent(void *dev, size_t size, void *vaddr, dma_addr_t dma_handle) {}

#define max_t(type, x, y) ({ type __x = (x); type __y = (y); __x > __y ? __x : __y; })
#define cpu_to_le16(x) (x)
#define cpu_to_le32(x) (x)
#define cpu_to_le64(x) (x)

#define TFD_QUEUE_CB_SIZE(size) (size)
#define RX_QUEUE_CB_SIZE(size) (size)