#include <stdbool.h>

typedef struct hb_buffer_t {
    bool have_output;
    bool have_positions;
    bool in_error;
    unsigned int len;
    unsigned int out_len;
    unsigned int i;
    void *out_info;
    void *info;
    unsigned int max_lig_id;
} hb_buffer_t;

#define FALSE false