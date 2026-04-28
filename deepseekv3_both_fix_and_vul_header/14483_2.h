#include <stdint.h>
#include <stddef.h>

#define GF_EXPORT

typedef uint32_t u32;
typedef int GF_Err;
typedef enum {
    GF_OK,
    GF_ISOM_REF_TBAS,
    GF_ISOM_HEVCTYPE_NONE,
    GF_ISOM_SAMPLE_ENTRY_VIDEO
} GF_EnumConstants;

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_TrackBox GF_TrackBox;
typedef struct GF_MPEGVisualSampleEntryBox GF_MPEGVisualSampleEntryBox;
typedef struct GF_HEVCConfig GF_HEVCConfig;

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
    int internal_type;
    struct {
        GF_HEVCConfig* config;
    }* hevc_config;
};

GF_Err gf_isom_get_reference(GF_ISOFile*, u32, u32, u32, u32*);
u32 gf_isom_get_reference_count(GF_ISOFile*, u32, u32);
GF_TrackBox* gf_isom_get_track_from_file(GF_ISOFile*, u32);
u32 gf_isom_get_hevc_lhvc_type(GF_ISOFile*, u32, u32);
void* gf_list_get(void*, u32);
GF_HEVCConfig* HEVC_DuplicateConfig(GF_HEVCConfig*);