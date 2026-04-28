#include <stdint.h>

typedef uint32_t u32;
typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_TrackBox GF_TrackBox;
typedef struct GF_UserDataBox GF_UserDataBox;
typedef struct GF_List GF_List;
typedef struct GF_MovieBox GF_MovieBox;

#define GF_EXPORT

struct GF_UserDataBox {
    GF_List *recordList;
};

struct GF_TrackBox {
    GF_UserDataBox *udta;
};

struct GF_MovieBox {
    GF_UserDataBox *udta;
};

struct GF_ISOFile {
    GF_MovieBox *moov;
};

GF_TrackBox *gf_isom_get_track_from_file(GF_ISOFile *movie, u32 trackNumber);
u32 gf_list_count(GF_List *list);