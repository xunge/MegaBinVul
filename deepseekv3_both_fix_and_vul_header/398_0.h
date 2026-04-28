#include <stddef.h>
#include <string.h>

struct mobj;
struct mobj *mobj_paged_alloc(size_t size);
struct mobj *mobj_mm_alloc(void *pool, size_t size, void *mm);
void *mobj_get_va(struct mobj *mobj, size_t offset);
extern void *mobj_sec_ddr;
extern struct {
    int shift;
} tee_mm_sec_ddr;

#define BIT(n) (1 << (n))
#define ROUNDUP(x, y) (((x) + (y) - 1) & ~((y) - 1))