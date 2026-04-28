#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GF_EXPORT

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed int s32;

typedef enum {
    GF_OK,
    GF_BAD_PARAM,
    GF_OUT_OF_MEM,
    GF_ISOM_OPEN_WRITE
} GF_Err;

typedef enum {
    GF_ITAG_STR,
    GF_ITAG_INT8,
    GF_ITAG_INT16,
    GF_ITAG_INT32,
    GF_ITAG_INT64,
    GF_ITAG_BOOL,
    GF_ITAG_FRAC6,
    GF_ITAG_FRAC8
} GF_ITagType;

typedef enum {
    GF_ISOM_ITUNE_RESET,
    GF_ISOM_ITUNE_GENRE,
    GF_ISOM_ITUNE_COPYRIGHT,
    GF_ISOM_ITUNE_COVER_ART,
    GF_ISOM_ITUNE_GENRE_USER,
    GF_ISOM_ITUNE_TOOL
} GF_ISOiTunesTag;

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_Box GF_Box;
typedef struct GF_UnknownBox GF_UnknownBox;
typedef struct GF_DataBox GF_DataBox;
typedef struct GF_ListItemBox GF_ListItemBox;
typedef struct GF_ItemListBox GF_ItemListBox;
typedef struct GF_MetaBox GF_MetaBox;

struct GF_DataBox {
    u32 flags;
    u32 dataSize;
    char* data;
};

struct GF_ListItemBox {
    u32 type;
    GF_DataBox* data;
    void* child_boxes;
};

struct GF_ItemListBox {
    void* child_boxes;
};

struct GF_MetaBox {
    void* child_boxes;
};

struct GF_UnknownBox {
    u32 original_4cc;
};

struct GF_ISOFile {
    struct {
        void* child_boxes;
        struct {
            void* recordList;
        }* udta;
    }* moov;
};

#define GF_ISOM_BOX_TYPE_ILST 0
#define GF_ISOM_BOX_TYPE_UNKNOWN 0
#define GF_ISOM_BOX_TYPE_DATA 0
#define GF_FALSE 0

#define LLU "%llu"

GF_Err CanAccessMovie(GF_ISOFile* mov, u32 mode);
s32 gf_itags_find_by_itag(GF_ISOiTunesTag tag);
GF_ITagType gf_itags_get_type(s32 tag_idx);
GF_MetaBox* gf_isom_create_meta_extensions(GF_ISOFile* mov, u32 flag);
GF_ItemListBox* gf_isom_locate_box(void* child_boxes, u32 type, void* ptr);
GF_Box* gf_isom_box_new(u32 type);
GF_Box* gf_isom_box_new_parent(void** child_boxes, u32 type);
void gf_isom_box_del_parent(void** child_boxes, GF_Box* box);
void gf_isom_box_del(GF_Box* box);
u32 gf_list_count(void* list);
void* gf_list_enum(void* list, u32* index);
void* gf_list_new();
u32 gf_list_add(void* list, void* item);
u32 gf_id3_get_genre_tag(const u8* data);
void* gf_malloc(size_t size);