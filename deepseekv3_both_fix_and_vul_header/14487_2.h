#include <stdint.h>

typedef uint32_t u32;

typedef enum {
    GF_ISOM_AVCTYPE_NONE,
    GF_ISOM_AVCTYPE_AVC_ONLY,
    GF_ISOM_AVCTYPE_AVC_SVC,
    GF_ISOM_AVCTYPE_AVC_MVC,
    GF_ISOM_AVCTYPE_SVC_ONLY,
    GF_ISOM_AVCTYPE_MVC_ONLY
} GF_ISOMAVCType;

#define GF_EXPORT

typedef struct GF_ISOFile GF_ISOFile;

typedef struct GF_HandlerBox {
    u32 handlerType;
} GF_HandlerBox;

typedef struct GF_MediaBox {
    GF_HandlerBox *handler;
    struct GF_MediaInformationBox *information;
} GF_MediaBox;

typedef struct GF_TrackBox {
    GF_MediaBox *Media;
} GF_TrackBox;

typedef struct GF_OriginalFormatBox {
    u32 data_format;
} GF_OriginalFormatBox;

typedef struct GF_RestrictedSchemeInfoBox {
    GF_OriginalFormatBox *original_format;
} GF_RestrictedSchemeInfoBox;

typedef struct GF_ProtectionSchemeInfoBox {
    GF_OriginalFormatBox *original_format;
} GF_ProtectionSchemeInfoBox;

typedef struct GF_SampleDescriptionBox {
    void *child_boxes;
} GF_SampleDescriptionBox;

typedef struct GF_SampleTableBox {
    GF_SampleDescriptionBox *SampleDescription;
} GF_SampleTableBox;

typedef struct GF_MediaInformationBox {
    GF_SampleTableBox *sampleTable;
} GF_MediaInformationBox;

typedef struct GF_MPEGVisualSampleEntryBox {
    u32 type;
    u32 internal_type;
    void *child_boxes;
    GF_RestrictedSchemeInfoBox *rinf;
    void *avc_config;
    void *svc_config;
    void *mvc_config;
} GF_MPEGVisualSampleEntryBox;

#define GF_ISOM_BOX_TYPE_ENCV 0x656E6376
#define GF_ISOM_BOX_TYPE_SINF 0x73696E66
#define GF_ISOM_BOX_TYPE_RESV 0x72657376
#define GF_ISOM_BOX_TYPE_AVC1 0x61766331
#define GF_ISOM_BOX_TYPE_AVC2 0x61766332
#define GF_ISOM_BOX_TYPE_AVC3 0x61766333
#define GF_ISOM_BOX_TYPE_AVC4 0x61766334
#define GF_ISOM_BOX_TYPE_SVC1 0x73766331
#define GF_ISOM_BOX_TYPE_MVC1 0x6D766331

#define GF_ISOM_SAMPLE_ENTRY_VIDEO 1

GF_TrackBox* gf_isom_get_track_from_file(GF_ISOFile* the_file, u32 trackNumber);
int gf_isom_is_video_handler_type(u32 handlerType);
void* gf_list_get(void* list, u32 index);
void* gf_isom_box_find_child(void* child_boxes, u32 box_type);