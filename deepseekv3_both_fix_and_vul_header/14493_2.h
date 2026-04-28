#include <stdint.h>

typedef uint32_t u32;

typedef enum {
    GF_ISOM_VVCTYPE_NONE,
    GF_ISOM_VVCTYPE_ONLY
} GF_ISOMVVCType;

#define GF_EXPORT
#define GF_ISOM_BOX_TYPE_ENCV 0x656E6376
#define GF_ISOM_BOX_TYPE_RESV 0x72657376
#define GF_ISOM_BOX_TYPE_SINF 0x73696E66
#define GF_ISOM_BOX_TYPE_VVC1 0x56564331
#define GF_ISOM_BOX_TYPE_VVI1 0x56564931
#define GF_ISOM_SAMPLE_ENTRY_VIDEO 0

typedef struct GF_ISOFile GF_ISOFile;

typedef struct GF_MediaBox GF_MediaBox;
typedef struct GF_HandlerBox GF_HandlerBox;
typedef struct GF_MediaInformationBox GF_MediaInformationBox;
typedef struct GF_SampleTableBox GF_SampleTableBox;
typedef struct GF_SampleDescriptionBox GF_SampleDescriptionBox;
typedef struct GF_OriginalFormatBox GF_OriginalFormatBox;
typedef struct GF_ProtectionSchemeInfoBox GF_ProtectionSchemeInfoBox;
typedef struct GF_RestrictedSchemeInfoBox GF_RestrictedSchemeInfoBox;

typedef struct GF_TrackBox {
    GF_MediaBox *Media;
} GF_TrackBox;

typedef struct GF_MediaBox {
    GF_HandlerBox *handler;
    GF_MediaInformationBox *information;
} GF_MediaBox;

typedef struct GF_HandlerBox {
    char *handlerType;
} GF_HandlerBox;

typedef struct GF_MediaInformationBox {
    GF_SampleTableBox *sampleTable;
} GF_MediaInformationBox;

typedef struct GF_SampleTableBox {
    GF_SampleDescriptionBox *SampleDescription;
} GF_SampleTableBox;

typedef struct GF_SampleDescriptionBox {
    void *child_boxes;
} GF_SampleDescriptionBox;

typedef struct GF_MPEGVisualSampleEntryBox {
    void *child_boxes;
    u32 type;
    u32 internal_type;
    GF_RestrictedSchemeInfoBox *rinf;
} GF_MPEGVisualSampleEntryBox;

typedef struct GF_ProtectionSchemeInfoBox {
    GF_OriginalFormatBox *original_format;
} GF_ProtectionSchemeInfoBox;

typedef struct GF_RestrictedSchemeInfoBox {
    GF_OriginalFormatBox *original_format;
} GF_RestrictedSchemeInfoBox;

typedef struct GF_OriginalFormatBox {
    u32 data_format;
} GF_OriginalFormatBox;

GF_TrackBox *gf_isom_get_track_from_file(GF_ISOFile *the_file, u32 trackNumber);
int gf_isom_is_video_handler_type(const char *handlerType);
void *gf_list_get(void *list, u32 position);
void *gf_isom_box_find_child(void *child_boxes, u32 box_type);