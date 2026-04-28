#include <stdint.h>
#include <stddef.h>

typedef int32_t GF_Err;
typedef uint32_t u32;

#define GF_EXPORT
#define GF_BAD_PARAM 1
#define GF_ISOM_INVALID_FILE 2
#define GF_OK 0

#define GF_ISOM_BOX_TYPE_MP4S 0x6D703473
#define GF_ISOM_BOX_TYPE_MP4A 0x6D703461
#define GF_ISOM_BOX_TYPE_MP4V 0x6D703476

#define SLPredef_MP4 0

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_Descriptor GF_Descriptor;

struct GF_SLConfig {
    u32 predefined;
};

struct GF_ESDescriptor {
    struct GF_SLConfig *slConfig;
};

struct GF_ESDBox {
    struct GF_ESDescriptor *desc;
};

struct GF_SampleEntryBox {
    u32 type;
};

struct GF_MPEGSampleEntryBox {
    struct GF_SampleEntryBox base;
    struct GF_ESDBox *esd;
    struct GF_SLConfig *slc;
};

struct GF_MPEGAudioSampleEntryBox {
    struct GF_SampleEntryBox base;
    struct GF_ESDBox *esd;
    struct GF_SLConfig *slc;
};

struct GF_MPEGVisualSampleEntryBox {
    struct GF_SampleEntryBox base;
    struct GF_ESDBox *esd;
    struct GF_SLConfig *slc;
};

struct GF_MediaBox {
    // dummy definition
};

struct GF_TrackBox {
    struct GF_MediaBox *Media;
};

typedef struct GF_TrackBox GF_TrackBox;
typedef struct GF_SampleEntryBox GF_SampleEntryBox;
typedef struct GF_SLConfig GF_SLConfig;
typedef struct GF_ESDBox GF_ESDBox;
typedef struct GF_MPEGSampleEntryBox GF_MPEGSampleEntryBox;
typedef struct GF_MPEGAudioSampleEntryBox GF_MPEGAudioSampleEntryBox;
typedef struct GF_MPEGVisualSampleEntryBox GF_MPEGVisualSampleEntryBox;

extern GF_TrackBox *gf_isom_get_track_from_file(GF_ISOFile *the_file, u32 trackNumber);
extern GF_Err Media_GetSampleDesc(struct GF_MediaBox *media, u32 StreamDescriptionIndex, GF_SampleEntryBox **entry, void *ptr);
extern void gf_odf_desc_del(GF_Descriptor *desc);
extern GF_Err gf_odf_desc_copy(GF_Descriptor *src, GF_Descriptor **dst);