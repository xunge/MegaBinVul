#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char bin128[16];

typedef enum {
    GF_OK,
    GF_BAD_PARAM,
    GF_OUT_OF_MEM,
    GF_ISOM_OPEN_WRITE
} GF_Err;

typedef struct GF_Box GF_Box;
typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_TrackBox GF_TrackBox;
typedef struct GF_UserDataBox GF_UserDataBox;
typedef struct GF_UnknownBox GF_UnknownBox;
typedef struct GF_UnknownUUIDBox GF_UnknownUUIDBox;
typedef struct GF_MoovBox GF_MoovBox;

struct GF_Box {
    u32 type;
};

struct GF_ISOFile {
    GF_MoovBox *moov;
};

struct GF_TrackBox {
    GF_UserDataBox *udta;
    GF_Box **child_boxes;
};

struct GF_UserDataBox {
    GF_Box **child_boxes;
};

struct GF_UnknownBox {
    GF_Box box;
    u32 original_4cc;
    char *data;
    u32 dataSize;
};

struct GF_UnknownUUIDBox {
    GF_Box box;
    bin128 uuid;
    char *data;
    u32 dataSize;
};

struct GF_MoovBox {
    GF_UserDataBox *udta;
    GF_Box **child_boxes;
};

#define GF_ISOM_BOX_TYPE_UDTA 0
#define GF_ISOM_BOX_TYPE_UNKNOWN 0
#define GF_ISOM_BOX_TYPE_UUID 0
#define GF_EXPORT
#define GF_FALSE 0

GF_Err CanAccessMovie(GF_ISOFile *movie, u32 mode);
GF_TrackBox *gf_isom_get_track_from_file(GF_ISOFile *movie, u32 trackNumber);
GF_Box *gf_isom_box_new(u32 boxType);
GF_Box *gf_isom_box_new_parent(GF_Box ***child_boxes, u32 boxType);
GF_Err trak_on_child_box(GF_Box *trak, GF_Box *box, u32 is_rem);
GF_Err moov_on_child_box(GF_Box *moov, GF_Box *box, u32 is_rem);
GF_Err udta_on_child_box(GF_Box *udta, GF_Box *box, u32 is_rem);
void *gf_malloc(size_t size);