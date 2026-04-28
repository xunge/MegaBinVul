#include <stdint.h>
#include <stddef.h>

#define GF_EXPORT
#define GF_ISOM_SAMPLE_ENTRY_VIDEO 1

typedef uint32_t u32;
typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_AV1Config GF_AV1Config;

typedef struct GF_TrackBox {
    struct {
        struct {
            struct {
                struct {
                    void* child_boxes;
                }* SampleDescription;
            }* sampleTable;
        }* information;
    }* Media;
} GF_TrackBox;

typedef struct GF_MPEGVisualSampleEntryBox {
    int internal_type;
    struct {
        GF_AV1Config* config;
    }* av1_config;
} GF_MPEGVisualSampleEntryBox;

typedef enum {
    GF_OK,
    GF_ISOM_REF_TBAS
} GF_Err;

GF_AV1Config* AV1_DuplicateConfig(const GF_AV1Config* cfg);
GF_TrackBox* gf_isom_get_track_from_file(GF_ISOFile* the_file, u32 trackNumber);
u32 gf_isom_get_reference_count(GF_ISOFile* the_file, u32 trackNumber, u32 reference_type);
GF_Err gf_isom_get_reference(GF_ISOFile* the_file, u32 trackNumber, u32 reference_type, u32 index, u32* out_ref_track);
void* gf_list_get(void* list, u32 index);