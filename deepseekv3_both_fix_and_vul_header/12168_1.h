#include <stdint.h>
#include <stdlib.h>

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int GF_Err;
typedef enum {
    GF_BAD_PARAM,
    GF_ISOM_INVALID_FILE,
    GF_OK
} GF_ErrorCodes;

typedef struct GF_BitStream GF_BitStream;
typedef struct GF_Box GF_Box;
typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_TrackBox GF_TrackBox;
typedef struct GF_List GF_List;

#define GF_FALSE 0
#define GF_TRUE 1
typedef int Bool;

#define GF_BITSTREAM_READ 0
#define GF_ISOM_BOX_TYPE_STSD 0x73747364
#define GF_ISOM_BOX_TYPE_SINF 0x73696E66
#define GF_ISOM_BOX_TYPE_RINF 0x72696E66
#define GF_ISOM_BOX_TYPE_BTRT 0x62747274

struct GF_Box {
    u32 type;
    GF_List *child_boxes;
};

struct GF_TrackBox {
    struct {
        struct {
            struct {
                struct {
                    GF_Box *SampleDescription;
                } *sampleTable;
            } *information;
            struct {
            } *handler;
        } *Media;
    };
};

GF_BitStream *gf_bs_new(u8 *data, u32 size, int mode);
void gf_bs_del(GF_BitStream *bs);
GF_Err gf_isom_box_parse_ex(GF_Box **box, GF_BitStream *bs, u32 parent_type, Bool is_root_box, u64 *bytes_expected);
void gf_isom_box_del(GF_Box *box);
GF_TrackBox *gf_isom_get_track_from_file(GF_ISOFile *file, u32 track);
GF_Box *gf_isom_box_find_child(GF_List *list, u32 box_type);
GF_List *gf_list_new();
void gf_list_del(GF_List *list);
void gf_list_del_item(GF_List *list, void *item);
void *gf_list_pop_front(GF_List *list);
void *gf_list_get(GF_List *list, u32 index);
u32 gf_list_count(GF_List *list);
void gf_list_add(GF_List *list, void *item);