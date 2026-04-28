#include <stdlib.h>

typedef unsigned int u32;
typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_AVCConfig GF_AVCConfig;
typedef struct GF_TrackBox GF_TrackBox;
typedef struct GF_MPEGVisualSampleEntryBox GF_MPEGVisualSampleEntryBox;

#define GF_EXPORT
#define GF_ISOM_AVCTYPE_NONE 0
#define GF_ISOM_SAMPLE_ENTRY_VIDEO 0

extern GF_TrackBox *gf_isom_get_track_from_file(GF_ISOFile *the_file, u32 trackNumber);
extern u32 gf_isom_get_avc_svc_type(GF_ISOFile *the_file, u32 trackNumber, u32 DescriptionIndex);
extern GF_AVCConfig *AVC_DuplicateConfig(GF_AVCConfig *config);

struct GF_MPEGVisualSampleEntryBox {
    u32 internal_type;
    struct {
        GF_AVCConfig *config;
    } *avc_config;
};

struct GF_TrackBox {
    struct {
        struct {
            struct {
                struct {
                    void **child_boxes;
                } *SampleDescription;
            } *sampleTable;
        } *information;
    } *Media;
};