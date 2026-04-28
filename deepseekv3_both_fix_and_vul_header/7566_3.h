#include <stdint.h>

#define GF_EXPORT

typedef int32_t GF_Err;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int64_t s64;
typedef int32_t s32;
typedef double Double;
typedef uint8_t u8;

typedef enum {
    GF_ISOM_SEARCH_FORWARD,
    GF_ISOM_SEARCH_BACKWARD,
    GF_ISOM_SEARCH_SYNC_FORWARD,
    GF_ISOM_SEARCH_SYNC_BACKWARD
} GF_ISOSearchMode;

typedef struct GF_ISOSample {
    u64 DTS;
    u32 dataLength;
    s32 CTS_Offset;
} GF_ISOSample;

typedef struct GF_MediaHeader {
    u32 timeScale;
} GF_MediaHeader;

typedef struct GF_SampleSizeBox {
    u32 sampleCount;
} GF_SampleSizeBox;

typedef struct GF_SampleTableBox {
    struct GF_SampleSizeBox *SampleSize;
} GF_SampleTableBox;

typedef struct GF_MediaInformationBox {
    struct GF_SampleTableBox *sampleTable;
} GF_MediaInformationBox;

typedef struct GF_MediaBox {
    struct GF_MediaHeader *mediaHeader;
    struct GF_MediaInformationBox *information;
} GF_MediaBox;

typedef struct GF_TrackHeaderBox {
    u64 initial_duration;
} GF_TrackHeaderBox;

typedef struct GF_MovieHeaderBox {
    u32 timeScale;
} GF_MovieHeaderBox;

typedef struct GF_MovieBox {
    struct GF_MovieHeaderBox *mvhd;
    struct GF_MovieExtendsBox *mvex;
} GF_MovieBox;

typedef struct GF_TrackBox {
    struct GF_TrackHeaderBox *Header;
    struct GF_MediaBox *Media;
    struct GF_MovieBox *moov;
    u64 dts_at_seg_start;
} GF_TrackBox;

typedef struct GF_ISOFile {
    struct GF_MovieBox *moov;
} GF_ISOFile;

#define GF_BAD_PARAM (-1)
#define GF_EOS (-2)
#define GF_OK (0)
#define GF_OUT_OF_MEM (-3)
#define GF_TRUE (1)
#define GF_FALSE (0)

GF_TrackBox *gf_isom_get_track_from_file(GF_ISOFile *the_file, u32 trackNumber);
int gf_timestamp_greater(u64 movieTime, u32 timeScale1, u64 duration, u32 timeScale2);
GF_Err GetMediaTime(GF_TrackBox *trak, int forward, u64 movieTime, u64 *mediaTime, s64 *segStartTime, s64 *mediaOffset, u8 *useEdit, u64 *nextMediaTime);
GF_Err GetNextMediaTime(GF_TrackBox *trak, u64 movieTime, u64 *mediaTime);
GF_Err GetPrevMediaTime(GF_TrackBox *trak, u64 movieTime, u64 *mediaTime);
GF_ISOSample *gf_isom_sample_new();
GF_Err gf_isom_get_sample_for_media_time(GF_ISOFile *the_file, u32 trackNumber, u64 mediaTime, u32 *StreamDescriptionIndex, GF_ISOSearchMode SearchMode, GF_ISOSample **sample, u32 *sampleNumber, u64 *data_offset);