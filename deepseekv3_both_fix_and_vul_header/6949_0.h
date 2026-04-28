#include <stdint.h>

typedef int32_t s32;
typedef uint32_t u32;
typedef int64_t s64;

typedef enum {
    GF_OK,
    GF_BAD_PARAM
} GF_Err;

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_TrackBox GF_TrackBox;
typedef struct GF_MediaBox GF_MediaBox;
typedef struct GF_MediaInformationBox GF_MediaInformationBox;
typedef struct GF_SampleTableBox GF_SampleTableBox;
typedef struct GF_CompositionOffsetBox GF_CompositionOffsetBox;
typedef struct GF_MediaHeaderBox GF_MediaHeaderBox;

struct GF_CompositionOffsetBox {
    u32 nb_entries;
    struct {
        s32 decodingOffset;
    } *entries;
    u32 unpack_mode;
};

struct GF_MediaHeaderBox {
    u32 duration;
};

struct GF_SampleTableBox {
    GF_CompositionOffsetBox *CompositionOffset;
};

struct GF_MediaInformationBox {
    GF_SampleTableBox *sampleTable;
};

struct GF_MediaBox {
    GF_MediaInformationBox *information;
    GF_MediaHeaderBox *mediaHeader;
};

struct GF_TrackBox {
    GF_MediaBox *Media;
};

#define GF_EXPORT

GF_TrackBox *gf_isom_get_track_from_file(GF_ISOFile *the_file, u32 trackNumber);