#include <stddef.h>

typedef struct {
    const char *name;
} WASSP_SUBTLV_DECODER_ENTRY_t;

typedef struct {
    int max_entry;
    WASSP_SUBTLV_DECODER_ENTRY_t *entry;
} WASSP_SUBTLV_DECODER_INFO_t;