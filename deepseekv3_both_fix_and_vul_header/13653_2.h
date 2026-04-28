#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef uint16_t u16;
typedef uint8_t u8;

struct list_head {
    struct list_head *next, *prev;
};

struct net_device {
    int dummy;
};

struct i40e_hw {
    struct {
        int asq_last_status;
    } aq;
    int pf_id;
};

struct i40e_pf {
    struct i40e_hw hw;
    struct {
        struct net_device dev;
    } *pdev;
};

struct i40e_vsi_info {
    u16 valid_sections;
    u16 tc_mapping[8];
    u16 mapping_flags;
    u16 queue_mapping[8];
};

struct i40e_vsi_context {
    int seid;
    int pf_num;
    int vf_num;
    int uplink_seid;
    struct i40e_vsi_info info;
};

struct i40e_channel {
    struct list_head list;
    int num_queue_pairs;
    struct i40e_vsi *parent_vsi;
};

struct i40e_vsi {
    int type;
    struct i40e_pf *back;
    int num_queue_pairs;
    int seid;
    int uplink_seid;
    struct i40e_vsi_info info;
    int base_queue;
    int rss_size;
    bool reconfig_rss;
    int next_base_queue;
    int cnt_q_avail;
    int macvlan_cnt;
    struct list_head macvlan_list;
};

#define INIT_LIST_HEAD(ptr) do { \
    (ptr)->next = (ptr); (ptr)->prev = (ptr); \
} while (0)

#define I40E_VSI_MAIN 0
#define I40E_AQ_VSI_PROP_QUEUE_MAP_VALID 0
#define I40E_AQ_VSI_PROP_SCHED_VALID 0
#define I40E_AQ_VSI_QUE_MAP_CONTIG 0
#define I40E_AQ_VSI_TC_QUE_OFFSET_SHIFT 0
#define I40E_AQ_VSI_TC_QUE_NUMBER_SHIFT 0

#define EINVAL 1
#define ENOMEM 2

#define GFP_KERNEL 0

#define cpu_to_le16(x) (x)
#define le16_to_cpu(x) (x)
#define max_t(type, x, y) ((x) > (y) ? (x) : (y))

static inline int fls(int x) {
    if (!x) return 0;
    int r = 32;
    if (!(x & 0xffff0000u)) { x <<= 16; r -= 16; }
    if (!(x & 0xff000000u)) { x <<= 8; r -= 8; }
    if (!(x & 0xf0000000u)) { x <<= 4; r -= 4; }
    if (!(x & 0xc0000000u)) { x <<= 2; r -= 2; }
    if (!(x & 0x80000000u)) { x <<= 1; r -= 1; }
    return r;
}

static inline unsigned long roundup_pow_of_two(unsigned long x) {
    return 1UL << fls(x - 1);
}

static inline void *kzalloc(size_t size, int flags) {
    return calloc(1, size);
}

static inline void list_add_tail(struct list_head *new, struct list_head *head) {
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}

static inline void dev_info(const struct net_device *dev, const char *fmt, ...) {}
static inline void dev_dbg(const struct net_device *dev, const char *fmt, ...) {}

static inline int i40e_vsi_config_rss(struct i40e_vsi *vsi) { return 0; }
static inline int i40e_aq_update_vsi_params(struct i40e_hw *hw, struct i40e_vsi_context *ctxt, void *null) { return 0; }
static inline void i40e_vsi_update_queue_map(struct i40e_vsi *vsi, struct i40e_vsi_context *ctxt) {}
static inline int i40e_setup_channel(struct i40e_pf *pf, struct i40e_vsi *vsi, struct i40e_channel *ch) { return 0; }
static inline void i40e_free_macvlan_channels(struct i40e_vsi *vsi) {}
static inline const char *i40e_stat_str(struct i40e_hw *hw, int err) { return ""; }
static inline const char *i40e_aq_str(struct i40e_hw *hw, int err) { return ""; }