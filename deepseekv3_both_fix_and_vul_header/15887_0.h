#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct stream_t stream_t;

typedef struct MP4_Box_data_string_t {
    char *psz_text;
} MP4_Box_data_string_t;

typedef struct MP4_Box_t {
    uint32_t i_type;
    uint64_t i_size;
    union {
        MP4_Box_data_string_t *p_string;
    } data;
} MP4_Box_t;

#define MP4_READBOX_ENTER(type) \
    const uint8_t *p_peek = NULL; \
    p_box->data.p_string = calloc(1, sizeof(type)); \
    if(p_box->data.p_string == NULL) \
        return 0;

#define MP4_READBOX_EXIT(ret) \
    free(p_box->data.p_string); \
    return ret;

#define SIZE_MAX UINT64_MAX