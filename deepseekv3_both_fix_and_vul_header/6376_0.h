#include <stdint.h>
#include <stdlib.h>

struct frame_info {
    uint32_t ents;
    uint32_t maxsize;
    uint32_t *data;
};

struct mp4config_struct {
    struct frame_info frame;
};

extern struct mp4config_struct mp4config;
extern uint32_t u32in(void);

#define ERR_FAIL (-1)