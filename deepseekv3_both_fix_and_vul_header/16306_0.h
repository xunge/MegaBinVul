#include <stdbool.h>

typedef unsigned long pmd_t;
#define pmd_write(pmd) (0)
#define pmd_dirty(pmd) (0)
#define FOLL_FORCE (0x01)
#define FOLL_COW (0x02)