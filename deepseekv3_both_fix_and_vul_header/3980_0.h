#include <stdint.h>
#include <string.h>

typedef uint32_t u32;
typedef uint8_t bin128[16];

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_TrackBox GF_TrackBox;
typedef struct GF_UserDataBox GF_UserDataBox;
typedef struct GF_UserDataMap GF_UserDataMap;
typedef struct GF_List GF_List;

#define GF_EXPORT
#define GF_ISOM_BOX_TYPE_UUID 0

struct GF_UserDataBox {
    GF_List *recordList;
};

struct GF_UserDataMap {
    u32 boxType;
    bin128 uuid;
    GF_List *boxes;
};

struct GF_TrackBox {
    GF_UserDataBox *udta;
};

struct GF_ISOFile {
    struct {
        GF_UserDataBox *udta;
    } *moov;
};

extern GF_TrackBox *gf_isom_get_track_from_file(GF_ISOFile *movie, u32 trackNumber);
extern void *gf_list_enum(GF_List *list, u32 *index);
extern u32 gf_list_count(GF_List *list);