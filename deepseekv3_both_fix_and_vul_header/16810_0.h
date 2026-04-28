#include <stdint.h>

typedef uint8_t u8;
typedef uint32_t u32;

typedef enum {
    GF_OK,
    GF_NON_COMPLIANT_BITSTREAM
} GF_Err;

typedef struct {
    void* opaque;
} GF_BitStream;

typedef struct {
    int version;
    int isProtected;
    int crypt_byte_block;
    int skip_byte_block;
    u8 key_info[37];
} GF_TrackEncryptionBox;

typedef struct {
    int dummy;
} GF_Box;

#define ISOM_DECREASE_SIZE(ptr, size) do {} while(0)
#define GF_LOG(level, category, message) do {} while(0)

u8 gf_bs_read_u8(GF_BitStream *bs);
int gf_bs_read_int(GF_BitStream *bs, int bits);
void gf_bs_read_data(GF_BitStream *bs, void *data, u32 size);