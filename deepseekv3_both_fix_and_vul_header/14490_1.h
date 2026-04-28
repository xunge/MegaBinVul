#include <stddef.h>

typedef unsigned int u32;
typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_TrackBox GF_TrackBox;
typedef struct GF_MPEGVisualSampleEntryBox GF_MPEGVisualSampleEntryBox;
typedef struct GF_DOVIDecoderConfigurationRecord GF_DOVIDecoderConfigurationRecord;

#define GF_EXPORT
#define GF_ISOM_SAMPLE_ENTRY_VIDEO 0

struct GF_DOVIDecoderConfigurationRecord {
    // 这里可以添加实际需要的字段
    // 由于原代码没有使用具体字段，保持空结构体
};

struct GF_MPEGVisualSampleEntryBox {
    int internal_type;
    struct {
        GF_DOVIDecoderConfigurationRecord *DOVIConfig;
    } *dovi_config;
};

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

GF_TrackBox* gf_isom_get_track_from_file(GF_ISOFile* the_file, u32 trackNumber);
void* gf_list_get(void* list, u32 index);
GF_DOVIDecoderConfigurationRecord* DOVI_DuplicateConfig(GF_DOVIDecoderConfigurationRecord* config);