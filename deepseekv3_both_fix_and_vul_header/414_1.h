#include <stdint.h>

typedef uint32_t u32;
typedef int Bool;

typedef struct GF_M2TS_Demuxer {
    unsigned char *buffer;
    u32 buffer_size;
    Bool prefix_present;
} GF_M2TS_Demuxer;

enum {
    GF_LOG_DEBUG,
    GF_LOG_CONTAINER
};

void GF_LOG(int level, int category, const char *format, ...);