#include <stdint.h>
#include <stddef.h>

typedef int32_t GF_Err;
typedef uint32_t u32;

#define GF_OK 0
#define GF_ISOM_INVALID_FILE 1

typedef struct GF_Box GF_Box;
typedef struct GF_BitStream GF_BitStream;
typedef struct GF_MovieBox GF_MovieBox;
typedef struct GF_MovieFileMap GF_MovieFileMap;
typedef struct GF_SampleEncryptionBox GF_SampleEncryptionBox;
typedef struct GF_TrackBox GF_TrackBox;

struct GF_TrackBox {
    GF_SampleEncryptionBox *sample_encryption;
    GF_MovieBox *moov;
    GF_Box *Header;
    GF_Box *Aperture;
    GF_Box *References;
    GF_Box *editBox;
    GF_Box *Media;
    GF_Box *meta;
    GF_Box *groups;
    GF_Box *udta;
};

struct GF_MovieBox {
    struct {
        GF_MovieFileMap *movieFileMap;
    } *mov;
};

struct GF_MovieFileMap {
    GF_BitStream *bs;
};

struct GF_SampleEncryptionBox {
    u32 load_needed;
};

GF_Err senc_Parse(GF_BitStream *bs, GF_TrackBox *ptr, void *null, GF_SampleEncryptionBox *senc);
void gf_isom_check_position(GF_Box *s, GF_Box *box, u32 *pos);