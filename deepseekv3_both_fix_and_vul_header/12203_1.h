#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint32_t u32;
typedef uint8_t u8;
typedef uint8_t bin128[16];

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_UserDataMap GF_UserDataMap;
typedef struct GF_UnknownBox GF_UnknownBox;
typedef struct GF_BitStream GF_BitStream;
typedef struct GF_TrackBox GF_TrackBox;
typedef struct GF_UserDataBox GF_UserDataBox;
typedef struct GF_UnknownUUIDBox GF_UnknownUUIDBox;
typedef struct GF_NameBox GF_NameBox;
typedef struct GF_KindBox GF_KindBox;
typedef struct GF_Box GF_Box;

typedef enum {
    GF_OK,
    GF_BAD_PARAM,
    GF_OUT_OF_MEM,
    GF_NOT_SUPPORTED
} GF_Err;

enum {
    GF_ISOM_BOX_TYPE_UUID = 0x75756964,
    GF_ISOM_BOX_TYPE_UNKNOWN = 0x756E6B6E,
    GF_ISOM_BOX_TYPE_NAME = 0x6E616D65,
    GF_ISOM_BOX_TYPE_KIND = 0x6B696E64
};

enum {
    GF_LOG_WARNING = 1,
    GF_LOG_CONTAINER = 2
};

#define GF_EXPORT
#define GPAC_DISABLE_ISOM_WRITE 0
#define GF_BITSTREAM_WRITE 0

struct GF_UserDataMap {
    u32 boxType;
    bin128 uuid;
    void* boxes;
};

struct GF_UserDataBox {
    void* recordList;
};

struct GF_TrackBox {
    GF_UserDataBox* udta;
};

struct GF_UnknownBox {
    u32 type;
    u32 original_4cc;
    u32 dataSize;
    char* data;
    void* child_boxes;
};

struct GF_UnknownUUIDBox {
    u32 type;
    u32 dataSize;
    char* data;
};

struct GF_NameBox {
    char* string;
};

struct GF_KindBox {
    char* value;
};

struct GF_ISOFile {
    struct {
        GF_UserDataBox* udta;
    } *moov;
};

extern GF_TrackBox* gf_isom_get_track_from_file(GF_ISOFile*, u32);
extern void* gf_list_enum(void*, u32*);
extern u32 gf_list_count(void*);
extern void* gf_list_get(void*, u32);
extern void* gf_malloc(size_t);
extern void gf_bs_write_u32(GF_BitStream*, u32);
extern void gf_bs_write_data(GF_BitStream*, char*, u32);
extern GF_BitStream* gf_bs_new(void*, u32, u32);
extern void gf_bs_get_content(GF_BitStream*, u8**, u32*);
extern void gf_bs_del(GF_BitStream*);
extern void gf_isom_box_write(GF_Box*, GF_BitStream*);
extern void gf_isom_box_array_write(GF_Box*, void*, GF_BitStream*);
extern void GF_LOG(int, int, const char*);