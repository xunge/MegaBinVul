#include <stdint.h>
#include <stdlib.h>

#define MAX_ELEM_ID 16
#define FF_ARRAY_ELEMS(a) (sizeof(a) / sizeof((a)[0]))
#define FFSWAP(type, a, b) do { type SWAP_tmp = b; b = a; a = SWAP_tmp; } while (0)

enum {
    TYPE_SCE,
    TYPE_LFE
};

enum {
    AAC_CHANNEL_FRONT,
    AAC_CHANNEL_SIDE,
    AAC_CHANNEL_BACK,
    AAC_CHANNEL_LFE
};

#define AV_CH_FRONT_LEFT             0x00000001
#define AV_CH_FRONT_RIGHT            0x00000002
#define AV_CH_FRONT_CENTER           0x00000004
#define AV_CH_LOW_FREQUENCY          0x00000008
#define AV_CH_BACK_LEFT              0x00000010
#define AV_CH_BACK_RIGHT             0x00000020
#define AV_CH_FRONT_LEFT_OF_CENTER   0x00000040
#define AV_CH_FRONT_RIGHT_OF_CENTER  0x00000080
#define AV_CH_BACK_CENTER            0x00000100
#define AV_CH_SIDE_LEFT              0x00000200
#define AV_CH_SIDE_RIGHT             0x00000400
#define AV_CH_TOP_CENTER             0x00000800
#define AV_CH_TOP_FRONT_LEFT         0x00001000
#define AV_CH_TOP_FRONT_CENTER       0x00002000
#define AV_CH_TOP_FRONT_RIGHT        0x00004000
#define AV_CH_TOP_BACK_LEFT          0x00008000
#define AV_CH_TOP_BACK_CENTER        0x00010000
#define AV_CH_TOP_BACK_RIGHT         0x00020000
#define AV_CH_STEREO_LEFT            0x20000000
#define AV_CH_STEREO_RIGHT           0x40000000
#define AV_CH_LOW_FREQUENCY_2        0x80000000
#define AV_CH_BOTTOM_FRONT_CENTER    0x100000000ULL
#define AV_CH_BOTTOM_FRONT_LEFT      0x200000000ULL
#define AV_CH_BOTTOM_FRONT_RIGHT     0x400000000ULL
#define AV_CH_TOP_SIDE_LEFT          0x800000000ULL
#define AV_CH_TOP_SIDE_RIGHT         0x1000000000ULL

#define AV_CH_LAYOUT_22POINT2 (AV_CH_FRONT_LEFT | AV_CH_FRONT_RIGHT | AV_CH_FRONT_CENTER | \
                              AV_CH_LOW_FREQUENCY | AV_CH_BACK_LEFT | AV_CH_BACK_RIGHT | \
                              AV_CH_FRONT_LEFT_OF_CENTER | AV_CH_FRONT_RIGHT_OF_CENTER | \
                              AV_CH_BACK_CENTER | AV_CH_SIDE_LEFT | AV_CH_SIDE_RIGHT | \
                              AV_CH_TOP_FRONT_LEFT | AV_CH_TOP_FRONT_RIGHT | AV_CH_TOP_FRONT_CENTER | \
                              AV_CH_TOP_CENTER | AV_CH_TOP_BACK_LEFT | AV_CH_TOP_BACK_RIGHT | \
                              AV_CH_TOP_BACK_CENTER | AV_CH_BOTTOM_FRONT_CENTER | AV_CH_BOTTOM_FRONT_LEFT | \
                              AV_CH_BOTTOM_FRONT_RIGHT | AV_CH_LOW_FREQUENCY_2 | AV_CH_TOP_SIDE_LEFT | \
                              AV_CH_TOP_SIDE_RIGHT)

#define PREFIX_FOR_22POINT2 0

struct elem_to_channel {
    uint64_t av_position;
    int syn_ele;
    int elem_id;
    int aac_position;
};

static const uint8_t aac_channel_layout_map[13][3];

static int count_paired_channels(uint8_t (*layout_map)[3], int tags, int pos, int *current_pos);
static int assign_pair(struct elem_to_channel *e2c_vec, uint8_t (*layout_map)[3], int i, uint64_t pos1, uint64_t pos2, int aac_pos, uint64_t *layout);