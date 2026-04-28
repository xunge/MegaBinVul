#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint16_t domid_t;
typedef uint32_t grant_ref_t;
typedef int16_t s16;

struct domain {
    domid_t domain_id;
    bool is_dying;
    struct grant_table *grant_table;
};

struct page_info;

typedef struct {
    uint32_t flags;
} grant_entry_header_t;

typedef union {
    struct {
        uint32_t flags;
    } hdr;
    struct {
        uint32_t flags;
        unsigned long frame;
    } full_page;
    struct {
        uint32_t flags;
        unsigned long frame;
        uint16_t page_off;
        uint16_t length;
    } sub_page;
    struct {
        uint32_t flags;
        domid_t trans_domid;
        grant_ref_t gref;
    } transitive;
} grant_entry_v2_t;

typedef struct {
    uint32_t flags;
    unsigned long frame;
} grant_entry_v1_t;

typedef uint32_t grant_status_t;

struct grant_table {
    unsigned int gt_version;
    grant_entry_v2_t *shared_v2;
    grant_entry_header_t *shared;
    grant_status_t *status;
};

struct active_grant_entry {
    uint32_t pin;
    domid_t domid;
    unsigned long frame;
    uint16_t start;
    uint16_t length;
    struct domain *trans_domain;
    grant_ref_t trans_gref;
    bool is_sub_page;
};

#define GTF_type_mask        0x0f
#define GTF_transitive       0x04
#define GTF_sub_page         0x08
#define GTF_reading          0x01
#define GTF_writing          0x02
#define _GTF_reading         GTF_reading
#define _GTF_writing         GTF_writing

#define GNTPIN_hstr_inc      0x01
#define GNTPIN_hstw_inc      0x02
#define GNTPIN_devw_mask     0x04
#define GNTPIN_hstw_mask     0x08

#define GNTST_okay           0
#define GNTST_bad_gntref     (-1)
#define GNTST_general_error  (-2)
#define GNTST_bad_domain     (-3)
#define ERESTART            (-4)

#define INVALID_GFN         (~0UL)

#define unlikely(x) (x)
#define likely(x) (x)

#define ASSERT(x) ((void)0)
#define barrier() __asm__ __volatile__("": : :"memory")

static unsigned int nr_grant_entries(struct grant_table *rgt) { return 0; }
static void grant_read_lock(struct grant_table *rgt) {}
static void grant_read_unlock(struct grant_table *rgt) {}
static struct active_grant_entry *active_entry_acquire(struct grant_table *rgt, grant_ref_t gref) { return NULL; }
static void active_entry_release(struct active_grant_entry *act) {}
static grant_entry_header_t *shared_entry_header(struct grant_table *rgt, grant_ref_t gref) { return &rgt->shared[gref]; }
static grant_entry_v2_t *shared_entry_v2(struct grant_table *rgt, grant_ref_t gref) { return &rgt->shared_v2[gref]; }
static grant_entry_v1_t shared_entry_v1(struct grant_table *rgt, grant_ref_t gref) { return *(grant_entry_v1_t*)&rgt->shared[gref]; }
static grant_status_t *status_entry(struct grant_table *rgt, grant_ref_t gref) { return &rgt->status[gref]; }
static s16 _set_status_v2(domid_t ldom, bool readonly, int flags, grant_entry_header_t *shah, struct active_grant_entry *act, grant_status_t *status) { return 0; }
static s16 _set_status(unsigned int version, domid_t ldom, bool readonly, int flags, grant_entry_header_t *shah, struct active_grant_entry *act, grant_status_t *status) { return 0; }
static void fixup_status_for_copy_pin(struct active_grant_entry *act, grant_status_t *status) {}
static void release_grant_for_copy(struct domain *td, grant_ref_t trans_gref, bool readonly) {}
static s16 get_paged_frame(unsigned long gfn, unsigned long *frame, struct page_info **page, bool readonly, struct domain *rd) { return 0; }
static void act_set_gfn(struct active_grant_entry *act, unsigned long gfn) {}
static void gnttab_clear_flag(uint32_t flag, grant_status_t *status) {}
static struct domain *rcu_lock_domain_by_id(domid_t domid) { return NULL; }
static void rcu_unlock_domain(struct domain *d) {}
static struct page_info *mfn_to_page(unsigned long mfn) { return NULL; }
static struct domain *page_get_owner_and_reference(struct page_info *page) { return NULL; }
static void put_page(struct page_info *page) {}
#define _mfn(x) (x)
#define _gfn(x) (x)
#define mfn_valid(x) (1)
#define PAGE_SIZE 4096

#define PIN_FAIL(label, err, fmt, ...) do { rc = err; goto label; } while (0)

#define shared_entry_v2(rgt, gref) (rgt->shared_v2[gref])
#define status_entry(rgt, gref) (rgt->status[gref])