#include <stdbool.h>

typedef unsigned long pte_t;
#define pte_write(x) (0)
#define pte_dirty(x) (0)
#define FOLL_FORCE (0)
#define FOLL_COW (0)