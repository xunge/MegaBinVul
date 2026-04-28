#include <stdlib.h>

typedef unsigned int u32;
typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_TrackBox GF_TrackBox;
typedef struct GF_MPEGVisualSampleEntryBox GF_MPEGVisualSampleEntryBox;
typedef struct GF_VPConfig GF_VPConfig;

#define GF_EXPORT
#define GF_ISOM_SAMPLE_ENTRY_VIDEO 1
#define VP_DuplicateConfig(config) ((GF_VPConfig*)config)

struct GF_TrackBox {
    struct {
        struct {
            struct {
                struct {
                    void** child_boxes;
                } *SampleDescription;
            } *sampleTable;
        } *information;
    } *Media;
};

struct GF_MPEGVisualSampleEntryBox {
    int internal_type;
    struct {
        GF_VPConfig* config;
    } *vp_config;
};

GF_TrackBox* gf_isom_get_track_from_file(GF_ISOFile* file, u32 trackNumber);
void* gf_list_get(void* list, u32 index);