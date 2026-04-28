#include <stdbool.h>
#include <stddef.h>

struct domain;
struct p2m_domain;

typedef unsigned long gfn_t;

#define gfn_x(gfn) ((unsigned long)(gfn))
#define gfn_to_gaddr(gfn) ((unsigned long)(gfn))

#define P2M_ROOT_LEVEL 0
#define GUEST_TABLE_MAP_FAILED (-1)
#define GUEST_TABLE_NORMAL_PAGE 0

#define BUG_ON(condition) do { if (condition) { *(volatile int *)0 = 0; } } while (0)

typedef struct {
    struct {
        unsigned int valid;
    } p2m;
    unsigned long mfn;
} lpae_t;

#define DECLARE_OFFSETS(name, addr) unsigned int name[4]

static inline bool lpae_is_valid(lpae_t entry) { return entry.p2m.valid; }
static inline bool lpae_is_table(lpae_t entry, unsigned int level) { return false; }
static inline unsigned long lpae_get_mfn(lpae_t entry) { return entry.mfn; }
static inline bool p2m_is_valid(lpae_t entry) { return true; }

struct p2m_domain {
    gfn_t max_mapped_gfn;
    unsigned long clean_pte;
};

static inline struct p2m_domain *p2m_get_hostp2m(struct domain *d) { return NULL; }
static inline void p2m_write_lock(struct p2m_domain *p2m) {}
static inline void p2m_write_unlock(struct p2m_domain *p2m) {}
static inline lpae_t *p2m_get_root_pointer(struct p2m_domain *p2m, gfn_t gfn) { return NULL; }
static inline int p2m_next_level(struct p2m_domain *p2m, bool write, unsigned int level, lpae_t **table, unsigned int offset) { return 0; }
static inline void p2m_invalidate_table(struct p2m_domain *p2m, unsigned long mfn) {}
static inline void p2m_write_pte(lpae_t *table, lpae_t entry, unsigned long clean_pte) {}
static inline void unmap_domain_page(lpae_t *table) {}