#include <stdint.h>

typedef int32_t GF_Err;
#define GF_OK 0

typedef struct GF_BitStream GF_BitStream;
typedef struct GF_Box {
    uint32_t type;
} GF_Box;

typedef struct {
    int is_ec3;
    int atmos_ec3_ext;
    int complexity_index_type;
} GF_AC3Config;

typedef struct GF_AC3ConfigBox {
    GF_Box box;
    GF_AC3Config cfg;
} GF_AC3ConfigBox;

#define GF_ISOM_BOX_TYPE_DEC3 0x64656333
#define GF_ISOM_BOX_TYPE_DAC3 0x64616333

GF_Err gf_isom_box_write_header(GF_Box *s, GF_BitStream *bs);
GF_Err gf_odf_ac3_cfg_write_bs(GF_AC3Config *cfg, GF_BitStream *bs);
void gf_bs_write_int(GF_BitStream *bs, int value, int bits);
void gf_bs_write_u8(GF_BitStream *bs, uint8_t value);