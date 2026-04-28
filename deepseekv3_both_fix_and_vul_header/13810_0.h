#include <stddef.h>

typedef struct Walker Walker;
typedef struct Select Select;

#define WRC_Continue 0
#define WRC_Prune 1
#define SF_View 0x0001

struct Select {
    unsigned selFlags;
};

static void renameWalkWith(Walker *pWalker, Select *p);