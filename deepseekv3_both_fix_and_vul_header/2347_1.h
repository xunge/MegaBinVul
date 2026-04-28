#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

typedef uint64_t l2_pgentry_t;

#define _PAGE_PRESENT (1ULL << 0)
#define _PAGE_PSE (1ULL << 7)
#define PAGETABLE_ORDER 9

struct page_info {
    // Minimal definition to allow pointer arithmetic
    char dummy[1];
};

struct page_info *l2e_get_page(l2_pgentry_t l2e);
unsigned long l2e_get_pfn(l2_pgentry_t l2e);
unsigned long l2e_get_flags(l2_pgentry_t l2e);
void put_page_and_type(struct page_info *page);
void put_page(struct page_info *page);
int _put_page_type(struct page_info *pg, bool b, struct page_info *page);
struct page_info *mfn_to_page(unsigned long mfn);
unsigned long _mfn(unsigned long pfn);

#define ASSERT(x) assert(x)