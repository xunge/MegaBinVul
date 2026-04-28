#include <stdlib.h>

typedef unsigned int u32;
typedef int GF_Err;

#define GF_OK 0
#define GF_ISOM_REF_TBAS 0

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_TrackBox GF_TrackBox;
typedef struct GF_MPEGVisualSampleEntryBox GF_MPEGVisualSampleEntryBox;
typedef struct GF_AV1Config GF_AV1Config;

#define GF_EXPORT

struct GF_TrackBox {
    struct {
        struct {
            struct {
                struct {
                    void** child_boxes;
                }* SampleDescription;
            }* sampleTable;
        }* information;
    }* Media;
};

struct GF_MPEGVisualSampleEntryBox {
    struct {
        GF_AV1Config* config;
    }* av1_config;
};

GF_Err gf_isom_get_reference(GF_ISOFile* the_file, u32 trackNumber, u32 ref_type, u32 index, u32* ref_track);
u32 gf_isom_get_reference_count(GF_ISOFile* the_file, u32 trackNumber, u32 ref_type);
GF_TrackBox* gf_isom_get_track_from_file(GF_ISOFile* the_file, u32 trackNumber);
GF_AV1Config* AV1_DuplicateConfig(GF_AV1Config* config);