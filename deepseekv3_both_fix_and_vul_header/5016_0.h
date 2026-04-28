#include <string.h>

#define PAGE_SHIFT 12

struct mm_walk {
    void *private;
    void *vma;
};