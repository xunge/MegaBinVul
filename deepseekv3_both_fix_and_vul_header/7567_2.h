#include <stdint.h>
#include <stddef.h>

typedef int32_t GF_Err;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int32_t s32;
typedef uint8_t u8;
typedef uint16_t u16;

typedef struct GF_ISOFile GF_ISOFile;

typedef struct GF_DataBox {
    u32 flags;
    u8 *data;
    u32 dataSize;
} GF_DataBox;

typedef struct GF_Box {
    u32 type;
    void *child_boxes;
} GF_Box;

typedef struct GF_MetaBox {
    GF_Box box;
    void *child_boxes;
} GF_MetaBox;

typedef struct GF_ItemListBox {
    GF_Box box;
    void *child_boxes;
} GF_ItemListBox;

typedef struct GF_ListItemBox {
    GF_Box box;
    u32 type;
    void *child_boxes;
    struct GF_DataBox *data;
} GF_ListItemBox;

typedef struct GF_UnknownBox {
    GF_Box box;
    u32 original_4cc;
} GF_UnknownBox;

typedef uint32_t GF_ISOiTunesTag;

#define GF_EXPORT
#define GF_FALSE 0
#define GF_OK 0
#define GF_URL_ERROR 1
#define GF_ISOM_BOX_TYPE_ILST 0
#define GF_ISOM_BOX_TYPE_DATA 0
#define GF_ISOM_BOX_TYPE_UNKNOWN 0
#define GF_ISOM_ITUNE_GENRE 0

enum {
    GF_ITAG_BOOL,
    GF_ITAG_INT8,
    GF_ITAG_INT16,
    GF_ITAG_INT32,
    GF_ITAG_INT64,
    GF_ITAG_FRAC6,
    GF_ITAG_FRAC8
};

GF_Err gf_isom_get_meta_extensions(GF_ISOFile *mov, int flag);
void* gf_isom_locate_box(void* boxes, u32 box_type, void* ptr);
void* gf_list_enum(void* list, u32* index);
int gf_itags_find_by_itag(u32 tag);
void* gf_isom_box_find_child(void* boxes, u32 box_type);
u32 gf_itags_get_type(u32 tag_idx);