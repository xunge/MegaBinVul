#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef unsigned int uint;

/* Basic type definitions */
typedef int spinlock_t;
typedef int seqlock_t;
typedef int atomic_t;
typedef int wait_queue_head_t;
typedef int kref;
typedef int completion;
typedef int list_head;
typedef int tasklet_struct;
typedef int work_struct;
typedef int timer_list;
typedef int device;

/* Constants */
#define GFP_KERNEL 0
#define ENOMEM 12
#define SDMA_BLOCK_SIZE 4096
#define L1_CACHE_BYTES 64
#define HFI1_HAS_SEND_DMA (1 << 0)
#define HFI1_HAS_SDMA_TIMEOUT (1 << 1)
#define TXE_NUM_SDMA_ENGINES 8
#define SDMA_DESC1_HEAD_TO_HOST_FLAG (1 << 0)
#define SDMA_DESC1_INT_REQ_FLAG (1 << 1)
#define SDMA_DESC_INTR 1
#define SDMA_AHG 0
#define SDMA 0
#define TAIL 0

/* SDMA states */
enum sdma_states {
    sdma_state_s00_hw_down
};

/* Forward declarations */
struct pci_dev {
    device dev;
};

struct hfi1_pportdata {
    u8 vls_operational;
};

struct sdma_state {
    kref kref;
    completion comp;
};

struct sdma_txreq;

struct rhashtable {
    int dummy;
};

struct sdma_engine {
    struct hfi1_devdata *dd;
    struct hfi1_pportdata *ppd;
    unsigned int this_idx;
    u16 descq_cnt;
    u16 desc_avail;
    u8 sdma_shift;
    u16 sdma_mask;
    u64 int_mask;
    u64 progress_mask;
    u64 idle_mask;
    u64 imask;
    spinlock_t tail_lock;
    seqlock_t head_lock;
    spinlock_t senddmactrl_lock;
    spinlock_t flushlist_lock;
    seqlock_t waitlock;
    u64 ahg_bits;
    struct sdma_state state;
    list_head flushlist;
    list_head dmawait;
    void *tail_csr;
    tasklet_struct sdma_hw_clean_up_task;
    tasklet_struct sdma_sw_clean_up_task;
    work_struct err_halt_worker;
    work_struct flush_worker;
    u32 progress_check_head;
    timer_list err_progress_check_timer;
    void *descq;
    uintptr_t descq_phys;
    struct sdma_txreq **tx_ring;
    void *head_dma;
    uintptr_t head_phys;
};

struct hfi1_devdata {
    struct hfi1_pportdata *pport;
    struct sdma_engine *per_sdma;
    int node;
    u32 default_desc1;
    u32 flags;
    u32 num_sdma;
    void *sdma_heads_dma;
    void *sdma_pad_dma;
    uintptr_t sdma_heads_phys;
    uintptr_t sdma_pad_phys;
    size_t sdma_heads_size;
    struct rhashtable *sdma_rht;
    struct pci_dev *pcidev;
    wait_queue_head_t sdma_unfreeze_wq;
    atomic_t sdma_unfreeze_count;
};

struct rhashtable_params {
    int dummy;
} sdma_rht_params;

/* Global variables */
static unsigned int mod_num_sdma;
static unsigned int num_vls;
static unsigned int sdma_idle_cnt;
static unsigned int sdma_desct_intr;

/* Function declarations */
static inline size_t chip_sdma_engines(struct hfi1_devdata *dd) { return 0; }
static inline size_t chip_sdma_mem_size(struct hfi1_devdata *dd) { return 0; }
static inline u16 sdma_get_descq_cnt(void) { return 0; }
static inline u16 sdma_descq_freecnt(struct sdma_engine *sde) { return 0; }
static inline void sdma_set_state(struct sdma_engine *sde, int state) {}
static inline void init_sdma_regs(struct sdma_engine *sde, u32 credits, unsigned int idle_cnt) {}
static inline int sdma_map_init(struct hfi1_devdata *dd, u8 port, u8 vls, void *arg) { return 0; }
static inline void sdma_clean(struct hfi1_devdata *dd, size_t num_engines) {}
static inline unsigned int ns_to_cclock(struct hfi1_devdata *dd, unsigned int ns) { return 0; }
static inline void *get_kctxt_csr_addr(struct hfi1_devdata *dd, unsigned int idx, unsigned int reg) { return NULL; }
static inline void sdma_hw_clean_up_task(unsigned long data) {}
static inline void sdma_sw_clean_up_task(unsigned long data) {}
static inline void sdma_err_halt_wait(work_struct *work) {}
static inline void sdma_field_flush(work_struct *work) {}
static inline void sdma_err_progress_check(timer_list *t) {}
static inline void *kcalloc_node(size_t n, size_t size, int flags, int node) { return NULL; }
static inline void *kzalloc(size_t size, int flags) { return NULL; }
static inline void *dma_alloc_coherent(device *dev, size_t size, uintptr_t *dma_handle, int flags) { return NULL; }
static inline void *kvzalloc_node(size_t size, int flags, int node) { return NULL; }
static inline void init_waitqueue_head(wait_queue_head_t *wq) {}
static inline void atomic_set(atomic_t *v, int i) {}
static inline void spin_lock_init(spinlock_t *lock) {}
static inline void seqlock_init(seqlock_t *lock) {}
static inline void kref_init(kref *kref) {}
static inline void init_completion(completion *comp) {}
static inline void INIT_LIST_HEAD(list_head *list) {}
static inline void tasklet_init(tasklet_struct *t, void (*func)(unsigned long), unsigned long data) {}
static inline void INIT_WORK(work_struct *work, void (*func)(work_struct *)) {}
static inline void timer_setup(timer_list *timer, void (*func)(timer_list *), int flags) {}
static inline int rhashtable_init(struct rhashtable *ht, struct rhashtable_params *params) { return 0; }
static inline void dd_dev_info(struct hfi1_devdata *dd, const char *fmt, ...) {}
static inline void dd_dev_err(struct hfi1_devdata *dd, const char *fmt, ...) {}
static inline size_t array_size(size_t a, size_t b) { return a * b; }
static inline int ilog2(unsigned long n) { return 0; }
static inline int HFI1_CAP_IS_KSET(int cap) { return 0; }
static inline void HFI1_CAP_CLEAR(int cap) {}
static inline unsigned int SD(unsigned int reg) { return reg; }