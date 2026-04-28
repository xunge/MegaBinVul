#include <stdint.h>

typedef int32_t GF_Err;
#define GF_OK 0
#define GF_BAD_PARAM 1

typedef struct GF_BitStream GF_BitStream;
typedef struct GF_Box GF_Box;

struct GF_ISMACrypSaltBox {
    GF_Box *s;
    uint64_t salt;
};

typedef struct GF_ISMACrypSaltBox GF_ISMACrypSaltBox;

GF_Err gf_isom_full_box_write(GF_Box *s, GF_BitStream *bs);
void gf_bs_write_u64(GF_BitStream *bs, uint64_t val);