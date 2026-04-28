#include <stdint.h>
#include <stdbool.h>

typedef uint32_t u32;

struct domain;
struct page_info;

typedef struct {
    unsigned long mfn;
} mfn_t;

#define mfn_x(_mfn) ((_mfn).mfn)
#define mfn_valid(_mfn) (1)
#define unlikely(x) (x)
#define ASSERT(x) 
#define SHADOW_PRINTK(fmt, ...) 

#define PAGE_SH_REFCOUNT_WIDTH 10

struct page_info {
    union {
        struct {
            u32 count;
            u32 type;
            bool head;
        } sh;
    } u;
    uint64_t up;
};

typedef uint64_t paddr_t;

static inline struct page_info *mfn_to_page(mfn_t mfn) { return (struct page_info *)0; }
static inline int sh_type_has_up_pointer(struct domain *d, uint32_t type) { return 0; }
static inline unsigned long __backpointer(struct page_info *sp) { return 0; }