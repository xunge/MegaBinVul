#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;
typedef uint8_t u8;

typedef enum {
    GF_OK,
    GF_BAD_PARAM
} GF_Err;

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_TrackBox {
    struct {
        struct {
            struct {
                struct {
                    void* child_boxes;
                }* SampleDescription;
            }* sampleTable;
        }* information;
    }* Media;
} GF_TrackBox;
typedef struct GF_MPEGAudioSampleEntryBox {
    u32 internal_type;
    u32 type;
    void* cfg_opus;
} GF_MPEGAudioSampleEntryBox;
typedef struct GF_BitStream GF_BitStream;
typedef struct GF_Box GF_Box;

#define GF_EXPORT
#define GF_ISOM_BOX_TYPE_ENCA 0
#define GF_ISOM_SAMPLE_ENTRY_AUDIO 0
#define GF_ISOM_SUBTYPE_OPUS 0
#define GF_BITSTREAM_WRITE 0

GF_TrackBox *gf_isom_get_track_from_file(GF_ISOFile *the_file, u32 trackNumber);
void gf_isom_get_original_format_type(GF_ISOFile *the_file, u32 trackNumber, u32 StreamDescriptionIndex, u32 *type);
void gf_isom_box_size(GF_Box *box);
void gf_isom_box_write(GF_Box *box, GF_BitStream *bs);
GF_BitStream *gf_bs_new(void *data, u32 size, u32 mode);
void gf_bs_get_content(GF_BitStream *bs, u8 **data, u32 *size);
void gf_bs_del(GF_BitStream *bs);
void* gf_list_get(void* list, u32 index);