#include <stdint.h>

typedef uint32_t u32;
typedef int32_t GF_Err;
typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_TrackBox GF_TrackBox;
typedef struct GF_MPEGAudioSampleEntryBox GF_MPEGAudioSampleEntryBox;

#define GF_EXPORT
#define GF_BAD_PARAM 0
#define GF_ISOM_INVALID_FILE 0
#define GF_OK 0
#define GF_ISOM_SAMPLE_ENTRY_AUDIO 0
#define GF_ISOM_SUBTYPE_MLPA 0

struct GF_MPEGAudioSampleEntryBox {
    u32 internal_type;
    u32 type;
    struct {
        u32 format_info;
        u32 peak_data_rate;
    } *cfg_mlp;
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