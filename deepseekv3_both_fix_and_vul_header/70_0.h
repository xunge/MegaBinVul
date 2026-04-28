#include <stdlib.h>
#include <stdint.h>

typedef uint32_t u32;
typedef uint8_t u8;

typedef enum {
    GF_OK,
    GF_BAD_PARAM
} GF_Err;

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_BitStream GF_BitStream;
typedef struct GF_TrackBox GF_TrackBox;
typedef struct GF_Tx3gSampleEntryBox GF_Tx3gSampleEntryBox;
typedef struct GF_Box GF_Box;
typedef struct GF_List GF_List;

#define GF_ISOM_BOX_TYPE_TX3G 0x74783367
#define GF_ISOM_BOX_TYPE_TEXT 0x74657874
#define GF_BITSTREAM_WRITE 1

struct GF_TrackBox {
    struct {
        struct {
            struct {
                struct {
                    GF_List* child_boxes;
                }* SampleDescription;
            }* sampleTable;
        }* information;
    }* Media;
};

struct GF_Tx3gSampleEntryBox {
    u32 type;
};

GF_TrackBox* gf_isom_get_track_from_file(GF_ISOFile* file, u32 track);
void gf_isom_write_tx3g(GF_Tx3gSampleEntryBox* a, GF_BitStream* bs, u32 sidx, u32 sidx_offset);
GF_BitStream* gf_bs_new(void* data, u32 size, u32 mode);
void gf_bs_get_content(GF_BitStream* bs, u8** data, u32* size);
void gf_bs_del(GF_BitStream* bs);