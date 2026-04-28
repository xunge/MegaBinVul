#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint32_t u32;
typedef uint64_t u64;
typedef uint8_t u8;
typedef uint8_t bin128[16];

typedef enum {
    GF_OK,
    GF_BAD_PARAM,
    GF_OUT_OF_MEM,
    GF_NOT_SUPPORTED
} GF_Err;

#define GF_EXPORT
#define GF_ISOM_BOX_TYPE_UUID 0x75756964
#define GF_ISOM_BOX_TYPE_UNKNOWN 0
#define GF_ISOM_BOX_TYPE_NAME 0x6E616D65
#define GF_ISOM_BOX_TYPE_KIND 0x6B696E64
#define GF_BITSTREAM_WRITE 0
#define GF_LOG_WARNING 1
#define GF_LOG_CONTAINER 2

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_TrackBox GF_TrackBox;
typedef struct GF_UserDataBox GF_UserDataBox;
typedef struct GF_UserDataMap GF_UserDataMap;
typedef struct GF_UnknownBox GF_UnknownBox;
typedef struct GF_UnknownUUIDBox GF_UnknownUUIDBox;
typedef struct GF_NameBox GF_NameBox;
typedef struct GF_KindBox GF_KindBox;
typedef struct GF_BitStream GF_BitStream;
typedef struct GF_Box GF_Box;

struct GF_ISOFile {
    struct {
        GF_UserDataBox *udta;
    } *moov;
};

struct GF_TrackBox {
    GF_UserDataBox *udta;
};

struct GF_UserDataBox {
    void *recordList;
};

struct GF_UserDataMap {
    u32 boxType;
    bin128 uuid;
    void *boxes;
};

struct GF_UnknownBox {
    u32 type;
    u32 original_4cc;
    u32 dataSize;
    char *data;
    void *child_boxes;
};

struct GF_UnknownUUIDBox {
    u32 type;
    u32 dataSize;
    char *data;
};

struct GF_NameBox {
    char *string;
};

struct GF_KindBox {
    char *value;
};

struct GF_Box {
    // Base box structure
};

extern GF_TrackBox *gf_isom_get_track_from_file(GF_ISOFile *movie, u32 trackNumber);
extern GF_BitStream *gf_bs_new(void *buffer, u64 size, u32 mode);
extern void gf_bs_del(GF_BitStream *bs);
extern void gf_bs_get_content(GF_BitStream *bs, u8 **output, u32 *outSize);
extern void gf_bs_write_u32(GF_BitStream *bs, u32 value);
extern void gf_bs_write_data(GF_BitStream *bs, const char *data, u32 dataSize);
extern void *gf_malloc(size_t size);
extern void *gf_list_enum(void *list, u32 *index);
extern u32 gf_list_count(void *list);
extern void *gf_list_get(void *list, u32 index);
extern void gf_isom_box_write(GF_Box *box, GF_BitStream *bs);
extern void gf_isom_box_array_write(GF_Box *box, void *child_boxes, GF_BitStream *bs);
extern void GF_LOG(u32 level, u32 module, const char *format);