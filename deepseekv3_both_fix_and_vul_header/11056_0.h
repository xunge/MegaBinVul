#include <stdint.h>
#include <stdlib.h>

typedef struct __tag_bitstream GF_BitStream;
typedef struct __tag_box GF_Box;

typedef enum {
    GF_OK,
    GF_ISOM_INVALID_FILE
} GF_Err;

typedef struct {
    GF_Box *s;
    uint8_t version;
    uint8_t crypt_byte_block;
    uint8_t skip_byte_block;
    uint8_t isProtected;
    uint8_t Per_Sample_IV_Size;
    uint8_t KID[16];
    uint8_t constant_IV_size;
    uint8_t constant_IV[16];
} GF_TrackEncryptionBox;

uint8_t gf_bs_read_u8(GF_BitStream *bs);
uint32_t gf_bs_read_int(GF_BitStream *bs, uint32_t numBits);
uint32_t gf_bs_read_data(GF_BitStream *bs, char *data, uint32_t size);

#define ISOM_DECREASE_SIZE(ptr, size)