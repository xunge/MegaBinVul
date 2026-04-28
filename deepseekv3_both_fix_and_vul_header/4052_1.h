#include <stdatomic.h>

struct kref {
    _Atomic int refcount;
};

struct nfc_llcp_local {
    struct kref ref;
};