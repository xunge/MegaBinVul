#include <stdint.h>

typedef uint32_t u32;

typedef struct GF_ISOFile GF_ISOFile;

typedef struct GF_MediaBox {
    struct GF_HandlerBox *handler;
    struct GF_MediaInformationBox *information;
} GF_MediaBox;

typedef struct GF_TrackBox {
    GF_MediaBox *Media;
} GF_TrackBox;

typedef struct GF_HandlerBox {
    u32 handlerType;
} GF_HandlerBox;

typedef struct GF_MediaInformationBox {
    struct GF_SampleTableBox *sampleTable;
} GF_MediaInformationBox;

typedef struct GF_SampleTableBox {
    struct GF_SampleDescriptionBox *SampleDescription;
} GF_SampleTableBox;

typedef struct GF_SampleDescriptionBox {
    void *child_boxes;
} GF_SampleDescriptionBox;

typedef struct GF_MPEGVisualSampleEntryBox {
    u32 internal_type;
    u32 type;
    void *child_boxes;
    struct GF_RestrictedSchemeInfoBox *rinf;
    void *hevc_config;
    void *lhvc_config;
} GF_MPEGVisualSampleEntryBox;

typedef struct GF_ProtectionSchemeInfoBox {
    struct GF_OriginalFormatBox *original_format;
} GF_ProtectionSchemeInfoBox;

typedef struct GF_RestrictedSchemeInfoBox {
    struct GF_OriginalFormatBox *original_format;
} GF_RestrictedSchemeInfoBox;

typedef struct GF_OriginalFormatBox {
    u32 data_format;
} GF_OriginalFormatBox;

#define GF_EXPORT
#define GF_ISOMHEVCType int
#define GF_ISOM_HEVCTYPE_NONE 0
#define GF_ISOM_HEVCTYPE_HEVC_ONLY 1
#define GF_ISOM_HEVCTYPE_HEVC_LHVC 2
#define GF_ISOM_HEVCTYPE_LHVC_ONLY 3
#define GF_ISOM_SAMPLE_ENTRY_VIDEO 1
#define GF_ISOM_BOX_TYPE_ENCV 0x656E6376
#define GF_ISOM_BOX_TYPE_SINF 0x73696E66
#define GF_ISOM_BOX_TYPE_RESV 0x72657376
#define GF_ISOM_BOX_TYPE_DVHE 0x64766865
#define GF_ISOM_BOX_TYPE_HEV1 0x68657631
#define GF_ISOM_BOX_TYPE_HVC1 0x68766331
#define GF_ISOM_BOX_TYPE_HVC2 0x68766332
#define GF_ISOM_BOX_TYPE_HEV2 0x68657632
#define GF_ISOM_BOX_TYPE_LHV1 0x6C687631
#define GF_ISOM_BOX_TYPE_LHE1 0x6C686531
#define GF_ISOM_BOX_TYPE_HVT1 0x68767431

GF_TrackBox* gf_isom_get_track_from_file(GF_ISOFile *the_file, u32 trackNumber);
int gf_isom_is_video_handler_type(u32 handlerType);
void* gf_list_get(void* list, u32 index);
void* gf_isom_box_find_child(void* child_boxes, u32 box_type);