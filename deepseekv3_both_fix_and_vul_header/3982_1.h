#include <stdlib.h>
#include <string.h>

typedef unsigned int u32;
typedef unsigned char bin128[16];

typedef enum {
    GF_OK,
    GF_BAD_PARAM
} GF_Err;

#define GF_EXPORT

typedef struct GF_List {
    // Minimal definition to make the code compile
    void* data;
} GF_List;

typedef struct GF_UserDataMap {
    u32 boxType;
    bin128 uuid;
} GF_UserDataMap;

typedef struct GF_UserDataBox {
    GF_List* recordList;
} GF_UserDataBox;

typedef struct GF_MovieBox {
    GF_UserDataBox* udta;
} GF_MovieBox;

typedef struct GF_TrackBox {
    GF_UserDataBox* udta;
} GF_TrackBox;

typedef struct GF_ISOFile {
    GF_MovieBox* moov;
} GF_ISOFile;

unsigned int gf_list_count(GF_List* list);
void* gf_list_get(GF_List* list, unsigned int index);
GF_TrackBox* gf_isom_get_track_from_file(GF_ISOFile *movie, u32 trackNumber);