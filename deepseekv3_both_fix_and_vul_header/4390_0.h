#include <stddef.h>

struct mm_struct {
    struct {
        unsigned long asce_limit;
    } context;
};

void crst_table_downgrade(struct mm_struct *mm, unsigned long limit);