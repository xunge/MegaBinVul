#include <stdint.h>

#define GF_EXPORT

typedef uint64_t u64;
typedef uint32_t u32;

typedef struct GF_ISOFile GF_ISOFile;

typedef struct GF_MediaBox {
    struct GF_MediaInformationBox *information;
} GF_MediaBox;

typedef struct GF_MediaInformationBox {
    struct GF_SampleTableBox *sampleTable;
} GF_MediaInformationBox;

typedef struct GF_SampleTableBox {
    struct GF_SampleSizeBox *SampleSize;
} GF_SampleTableBox;

typedef struct GF_SampleSizeBox {
    u32 sampleSize;
    u32 sampleCount;
    u32 *sizes;
} GF_SampleSizeBox;

typedef struct GF_TrackBox {
    GF_MediaBox *Media;
} GF_TrackBox;

GF_TrackBox *gf_isom_get_track_from_file(GF_ISOFile *movie, u32 trackNumber);