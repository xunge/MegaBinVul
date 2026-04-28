#include <string.h>
#include <stdlib.h>

typedef unsigned char u8;
typedef unsigned int u32;

typedef enum {
    GF_FPROBE_NOT_SUPPORTED,
    GF_FPROBE_MAYBE_SUPPORTED,
    GF_FPROBE_EXT_MATCH
} GF_FilterProbeScore;

typedef enum {
    GF_OK = 0,
    GF_OTHER_ERROR
} GF_Err;

void gf_free(void *ptr);
GF_Err gf_utf_get_utf8_string_from_bom_v1(const u8 *data, u32 size, char **dst, char **res);
u8 *gf_utf_get_utf8_string_from_bom_v2(char *data, u32 size, char **dst);