#include <stdlib.h>

typedef unsigned int u32;

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_MediaBox GF_MediaBox;
typedef struct GF_MediaInformationBox GF_MediaInformationBox;
typedef struct GF_SampleTableBox GF_SampleTableBox;
typedef struct GF_SampleDescriptionBox GF_SampleDescriptionBox;
typedef struct GF_Box GF_Box;
typedef struct GF_List GF_List;
typedef struct GF_VVCConfigurationBox GF_VVCConfigurationBox;
typedef struct GF_VVCConfig GF_VVCConfig;

typedef struct GF_TrackBox {
    GF_MediaBox *Media;
} GF_TrackBox;

typedef struct GF_MPEGVisualSampleEntryBox {
    u32 internal_type;
    GF_VVCConfigurationBox *vvc_config;
} GF_MPEGVisualSampleEntryBox;

typedef struct GF_MediaBox {
    GF_MediaInformationBox *information;
} GF_MediaBox;

typedef struct GF_MediaInformationBox {
    GF_SampleTableBox *sampleTable;
} GF_MediaInformationBox;

typedef struct GF_SampleTableBox {
    GF_SampleDescriptionBox *SampleDescription;
} GF_SampleTableBox;

typedef struct GF_SampleDescriptionBox {
    GF_List *child_boxes;
} GF_SampleDescriptionBox;

typedef struct GF_VVCConfigurationBox {
    GF_VVCConfig *config;
} GF_VVCConfigurationBox;

#define GF_EXPORT
#define GF_ISOM_VVCTYPE_NONE 0
#define GF_ISOM_SAMPLE_ENTRY_VIDEO 0

GF_TrackBox *gf_isom_get_track_from_file(GF_ISOFile *the_file, u32 trackNumber);
u32 gf_isom_get_vvc_type(GF_ISOFile *the_file, u32 trackNumber, u32 DescriptionIndex);
void *gf_list_get(GF_List *list, u32 position);
GF_VVCConfig *VVC_DuplicateConfig(GF_VVCConfig *config);