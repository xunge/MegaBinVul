#include <stdlib.h>
#include <errno.h>

#define HWXMIT_ENTRY 5
#define GFP_KERNEL 0

struct xmit_priv {
    int hwxmit_entry;
    struct hw_xmit *hwxmits;
    void *bm_pending;
    void *vo_pending;
    void *vi_pending;
    void *bk_pending;
    void *be_pending;
};

struct hw_xmit {
    void **sta_queue;
};

struct adapter {
    struct xmit_priv xmitpriv;
};

void *kzalloc(size_t size, int flags) {
    return calloc(1, size);
}