#include <stdint.h>

typedef int32_t GF_Err;
#define GF_OK 0

typedef struct {
    uint32_t size;
} GF_Box;

typedef struct {
    uint8_t version;
    struct {
        uint8_t stream_structure;
        uint8_t definedLayout;
        uint32_t channels_count;
        struct {
            uint8_t position;
        } *layouts;
        uint8_t omitted_channels_present;
    } layout;
} GF_ChannelLayoutBox;

typedef uint32_t u32;