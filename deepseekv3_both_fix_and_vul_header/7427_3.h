#include <string.h>
#include <stdlib.h>

typedef unsigned char u8;
typedef unsigned int u32;

typedef enum {
    GF_FPROBE_SUPPORTED,
    GF_FPROBE_MAYBE_SUPPORTED
} GF_FilterProbeScore;

typedef enum {
    GF_OK = 0,
    GF_BAD_PARAM,
    GF_OUT_OF_MEM,
    GF_IO_ERR,
    GF_NOT_SUPPORTED
} GF_Err;

extern GF_Err gf_utf_get_utf8_string_from_bom_4args(char *data, u32 data_size, char **dst, char **res);
extern u8 *gf_utf_get_utf8_string_from_bom_3args(char *data, u32 data_size, char **dst);
extern void gf_free(void *ptr);