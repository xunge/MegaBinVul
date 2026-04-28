#include <stdint.h>
#include <string.h>

#define FDT_MAX_DEPTH 32
#define FDT_ERR_BADSTRUCTURE -11
#define FDT_ERR_NOSPACE -3
#define FDT_ERR_BADLAYOUT -15

#define FDT_PROP 3
#define FDT_NOP 4
#define FDT_BEGIN_NODE 1
#define FDT_END_NODE 2
#define FDT_END 9

struct fdt_property {
    uint32_t nameoff;
};

struct fdt_region {
    int offset;
    int size;
};

int fdt_off_dt_struct(const void *fdt);
int fdt_next_tag(const void *fdt, int offset, int *nextoffset);
const struct fdt_property *fdt_get_property_by_offset(const void *fdt, int offset, int *lenp);
const char *fdt_string(const void *fdt, int stroffset);
int fdt_size_dt_struct(const void *fdt);
int fdt_size_dt_strings(const void *fdt);
const char *fdt_get_name(const void *fdt, int offset, int *len);
int str_in_list(const char *str, char * const *list, int count);
uint32_t fdt32_to_cpu(uint32_t x);