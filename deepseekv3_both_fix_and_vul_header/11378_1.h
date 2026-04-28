#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

typedef struct git_pkt git_pkt;
typedef struct git_pkt_ng git_pkt_ng;

enum {
    GIT_PKT_NG
};

struct git_pkt_ng {
    char *ref;
    char *msg;
    int type;
};

#define GITERR_NET 1
#define GITERR_CHECK_ALLOC(ptr) if (!(ptr)) { giterr_set_oom(); return -1; }
#define GITERR_CHECK_ALLOC_ADD(out, a, b) if ((a) > SIZE_MAX - (b)) { giterr_set_oom(); return -1; } else { *(out) = (a) + (b); }

extern void giterr_set(int error_class, const char *message);
extern void giterr_set_oom(void);
extern void *git__malloc(size_t size);
extern void git__free(void *ptr);