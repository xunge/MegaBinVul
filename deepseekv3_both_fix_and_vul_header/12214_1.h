#include <stdint.h>

typedef struct GetBitContext GetBitContext;

typedef struct EVCParserSPS {
    unsigned sps_max_dec_pic_buffering_minus1;
} EVCParserSPS;

typedef struct RefPicListStruct {
    int ref_pic_num;
    int ref_pics[];
} RefPicListStruct;

#define AVERROR_INVALIDDATA (-1)

int get_ue_golomb_long(GetBitContext *gb);
int get_bits(GetBitContext *gb, int n);