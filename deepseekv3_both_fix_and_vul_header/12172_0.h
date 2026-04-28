#include <stdlib.h>
#include <string.h>

typedef unsigned int u32;
typedef unsigned char Bool;

typedef enum {
    GF_OK,
    GF_BAD_PARAM,
    GF_ISOM_INVALID_FILE,
    GF_OUT_OF_MEM
} GF_Err;

#define GF_EXPORT
#define GF_ISOM_OPEN_WRITE 1
#define GF_ISOM_BOX_TYPE_STSZ 0x7374737A
#define GF_ISOM_BOX_TYPE_STZ2 0x73747A32

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_TrackBox GF_TrackBox;
typedef struct GF_MediaBox GF_MediaBox;
typedef struct GF_MediaInformationBox GF_MediaInformationBox;
typedef struct GF_SampleTableBox GF_SampleTableBox;
typedef struct GF_SampleSizeBox GF_SampleSizeBox;

struct GF_SampleSizeBox {
    u32 type;
    u32 sampleSize;
    u32 sampleCount;
    u32* sizes;
};

struct GF_SampleTableBox {
    GF_SampleSizeBox *SampleSize;
};

struct GF_MediaInformationBox {
    GF_SampleTableBox *sampleTable;
};

struct GF_MediaBox {
    GF_MediaInformationBox *information;
};

struct GF_TrackBox {
    GF_MediaBox *Media;
};

GF_Err CanAccessMovie(GF_ISOFile *movie, u32 mode);
GF_TrackBox* gf_isom_get_track_from_file(GF_ISOFile *movie, u32 trackNumber);
void* gf_malloc(size_t size);
void gf_free(void *ptr);