#include <stddef.h>
#include <string.h>
#include <stdio.h>

#define FIT_SIG_NODENAME "signature"
#define FDT_ERR_TRUNCATED (-1)
#define FDT_ERR_BADSTRUCTURE (-2)
#define EPERM 1

struct fdt_header;
#define fdt_for_each_subnode(noffset, fit, parent_offset) \
    for (noffset = fdt_first_subnode(fit, parent_offset); \
         noffset >= 0; \
         noffset = fdt_next_subnode(fit, noffset))

int fdt_first_subnode(const void *fit, int parent_offset);
int fdt_next_subnode(const void *fit, int offset);
const char *fit_get_name(const void *fit, int noffset, int *len);
int fit_image_check_sig(const void *fit, int noffset, const char *data, size_t size, int region, char **err_msg);