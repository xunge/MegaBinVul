#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;
typedef unsigned int u32;

typedef enum {
    GF_OK,
    GF_BAD_PARAM
} GF_Err;

#define GF_EXPORT
#define GF_ISOM_BOX_TYPE_ENCA 0
#define GF_ISOM_BOX_TYPE_FLAC 0
#define GF_ISOM_SAMPLE_ENTRY_AUDIO 0

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_TrackBox GF_TrackBox;
typedef struct GF_MediaBox GF_MediaBox;
typedef struct GF_MediaInformationBox GF_MediaInformationBox;
typedef struct GF_SampleTableBox GF_SampleTableBox;
typedef struct GF_SampleDescriptionBox GF_SampleDescriptionBox;
typedef struct GF_Box GF_Box;
typedef struct GF_MPEGAudioSampleEntryBox GF_MPEGAudioSampleEntryBox;
typedef struct GF_FlacConfigBox GF_FlacConfigBox;

struct GF_MPEGAudioSampleEntryBox {
    u32 type;
    u32 internal_type;
    GF_FlacConfigBox *cfg_flac;
};

struct GF_FlacConfigBox {
    u32 dataSize;
    u8 *data;
};

struct GF_TrackBox {
    GF_MediaBox *Media;
};

struct GF_MediaBox {
    GF_MediaInformationBox *information;
};

struct GF_MediaInformationBox {
    GF_SampleTableBox *sampleTable;
};

struct GF_SampleTableBox {
    GF_SampleDescriptionBox *SampleDescription;
};

struct GF_SampleDescriptionBox {
    GF_Box **child_boxes;
};

void *gf_malloc(size_t size);
GF_TrackBox *gf_isom_get_track_from_file(GF_ISOFile *the_file, u32 trackNumber);
GF_Err gf_isom_get_original_format_type(GF_ISOFile *the_file, u32 trackNumber, u32 StreamDescriptionIndex, u32 *type);