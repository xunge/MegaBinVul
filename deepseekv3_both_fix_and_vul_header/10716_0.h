#include <stddef.h>

#define LAYOUT_TYPE_MAX 64
#define dprintk(fmt, ...) do {} while (0)

struct svc_export {
    unsigned int ex_layout_types;
};

struct nfsd4_layout_ops;

static const struct nfsd4_layout_ops *nfsd4_layout_ops[LAYOUT_TYPE_MAX];