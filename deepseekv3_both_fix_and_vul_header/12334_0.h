#include <stdint.h>

#define VOP_START_CODE 0x1B6
#define VISUAL_OBJECT_START_CODE 0x1B5
#define AVPROBE_SCORE_EXTENSION 50

typedef struct AVProbeData {
    const uint8_t *buf;
    int buf_size;
} AVProbeData;