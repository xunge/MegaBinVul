#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#define FIT_SIG_NODENAME "signatures"
#define FIT_KEY_REQUIRED "required"
#define EPERM 1

int fdt_subnode_offset(const void *fdt, int parentoffset, const char *name);
const char *fdt_strerror(int errval);
const char *fdt_getprop(const void *fdt, int nodeoffset, const char *name, int *lenp);
#define fdt_for_each_subnode(node, fdt, parent) \
    for (node = fdt_first_subnode(fdt, parent); \
         node >= 0; \
         node = fdt_next_subnode(fdt, node))
int fdt_first_subnode(const void *fdt, int offset);
int fdt_next_subnode(const void *fdt, int offset);

int fit_config_verify_sig(const void *fit, int conf_noffset, const void *sig_blob, int noffset);
const char *fit_get_name(const void *fit, int noffset, int *len);
int debug(const char *fmt, ...);