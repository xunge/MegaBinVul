#include <stddef.h>

struct mm_struct {
    struct {
        int id;
    } context;
};

static int hash__alloc_context_id(void);
static void slice_init_new_context_exec(struct mm_struct *mm);
static void subpage_prot_init_new_context(struct mm_struct *mm);
static void pkey_mm_init(struct mm_struct *mm);