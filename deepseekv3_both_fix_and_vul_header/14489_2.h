#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;
typedef uint8_t u8;
typedef uint64_t u64;

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_HEVCConfig {
    u8 profile_space;
    u8 tier_flag;
    u8 profile_idc;
    u32 general_profile_compatibility_flags;
    u64 constraint_indicator_flags;
} GF_HEVCConfig;

typedef struct GF_OperatingPointsInformation {
    void *profile_tier_levels;
} GF_OperatingPointsInformation;

typedef struct GF_TrackBox {
    struct {
        struct {
            struct {
                struct {
                    void *child_boxes;
                } *SampleDescription;
            } *sampleTable;
        } *information;
    } *Media;
} GF_TrackBox;

typedef struct GF_MPEGVisualSampleEntryBox {
    u32 internal_type;
    struct {
        GF_HEVCConfig *config;
    } *lhvc_config;
} GF_MPEGVisualSampleEntryBox;

typedef struct LHEVC_ProfileTierLevel {
    u8 general_profile_space;
    u8 general_tier_flag;
    u8 general_profile_idc;
    u32 general_profile_compatibility_flags;
    u64 general_constraint_indicator_flags;
} LHEVC_ProfileTierLevel;

#define GF_EXPORT
#define GF_ISOM_HEVCTYPE_NONE 0
#define GF_ISOM_SAMPLE_ENTRY_VIDEO 0

extern GF_TrackBox *gf_isom_get_track_from_file(GF_ISOFile *the_file, u32 trackNumber);
extern u32 gf_isom_get_hevc_lhvc_type(GF_ISOFile *the_file, u32 trackNumber, u32 DescriptionIndex);
extern GF_HEVCConfig *HEVC_DuplicateConfig(GF_HEVCConfig *config);
extern void gf_isom_get_oinf_info(GF_ISOFile *the_file, u32 trackNumber, GF_OperatingPointsInformation **oinf);
extern void *gf_list_get(void *list, u32 index);
extern void *gf_list_last(void *list);