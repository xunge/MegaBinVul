#include <stdlib.h>
#include <string.h>

typedef unsigned int u32;
typedef unsigned char bin128[16];

typedef enum {
    GF_OK,
    GF_BAD_PARAM,
    GF_ISOM_OPEN_WRITE
} GF_Err;

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_Box GF_Box;
typedef struct GF_TrackBox GF_TrackBox;
typedef struct GF_UserDataBox GF_UserDataBox;
typedef struct GF_UserDataMap GF_UserDataMap;

#define GF_ISOM_BOX_TYPE_UUID 0

#define GF_EXPORT

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

struct GF_ISOFile {
    struct {
        GF_UserDataBox* udta;
    }* moov;
};

GF_Err CanAccessMovie(GF_ISOFile* movie, u32 mode);
GF_TrackBox* gf_isom_get_track_from_file(GF_ISOFile* movie, u32 trackNumber);
void* gf_list_enum(void* list, u32* index);
u32 gf_list_count(void* list);
void gf_list_rem(void* list, u32 index);
void gf_isom_box_del_parent(void** boxes, GF_Box* box);
void gf_isom_box_array_del(void* boxes);
void* gf_list_get(void* list, u32 index);