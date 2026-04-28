#include <stdlib.h>
#include <string.h>

typedef unsigned char bin128[16];
typedef unsigned int u32;
typedef int GF_Err;

#define GF_EXPORT
#define GF_ISOM_OPEN_WRITE 0
#define GF_ISOM_BOX_TYPE_UUID 0
#define GF_EOS 0
#define GF_BAD_PARAM 0
#define GF_OK 0

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_TrackBox GF_TrackBox;
typedef struct GF_UserDataBox GF_UserDataBox;
typedef struct GF_UserDataMap GF_UserDataMap;
typedef struct GF_List GF_List;

struct GF_ISOFile {
    struct {
        GF_UserDataBox *udta;
    } *moov;
};

struct GF_TrackBox {
    GF_UserDataBox *udta;
};

struct GF_UserDataBox {
    GF_List *recordList;
};

struct GF_UserDataMap {
    u32 boxType;
    bin128 uuid;
    void* boxes;
};

GF_Err CanAccessMovie(GF_ISOFile *movie, u32 mode);
GF_TrackBox *gf_isom_get_track_from_file(GF_ISOFile *movie, u32 trackNumber);
void *gf_list_enum(GF_List *list, u32 *index);
void gf_list_rem(GF_List *list, u32 index);
void gf_isom_box_array_del(void *boxes);
void gf_free(void *ptr);