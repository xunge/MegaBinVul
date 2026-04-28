#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;
typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_TrackBox GF_TrackBox;
typedef struct GF_UserDataMap GF_UserDataMap;
typedef struct GF_TrackSelectionBox GF_TrackSelectionBox;
typedef struct GF_List GF_List;

#define GF_EXPORT
#define GF_ISOM_BOX_TYPE_TSEL 0

struct GF_TrackSelectionBox {
    u32 switchGroup;
    u32 attributeListCount;
    u32 *attributeList;
};

struct GF_UserDataMap {
    GF_List *boxes;
};

struct GF_TrackBox {
    void *udta;
};

GF_TrackBox *gf_isom_get_track_from_file(GF_ISOFile *movie, u32 trackNumber);
GF_UserDataMap *udta_getEntry(void *udta, u32 boxType, void *unused);
void *gf_list_get(GF_List *list, u32 index);