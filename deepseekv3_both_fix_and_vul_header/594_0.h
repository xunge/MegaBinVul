#include <stdint.h>

#define MAX_CHANNELS 64
#define DEBUGVAR(a, b, c)

typedef struct {
    uint8_t exclude_mask[MAX_CHANNELS];
    uint8_t additional_excluded_chns[MAX_CHANNELS];
} drc_info;

typedef struct {
    // bitfile structure members would need to be defined here
    // but since it's not fully shown in the original code, we'll leave it as incomplete
} bitfile;

uint8_t faad_get1bit(bitfile* ld);