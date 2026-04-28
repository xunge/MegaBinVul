#include <stdint.h>
#include <stddef.h>

#define MPEG12_SEQUENCE_START_CODE 0x000001B3
#define MPEG12_EXT_START_CODE 0x000001B5
#define MPEG12_PICTURE_START_CODE 0x00000100
#define SEQ_ID 1

typedef uint32_t u32;
typedef int32_t s32;
typedef double Double;

static const Double mpeg12_frame_rate_table[] = {
    0.0, 23.976, 24.0, 25.0, 29.97, 30.0, 50.0, 59.94, 60.0
};