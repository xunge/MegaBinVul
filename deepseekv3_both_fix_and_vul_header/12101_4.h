#include <stdlib.h>
#include <string.h>

typedef unsigned int u32;
typedef int s32;
typedef int GF_Err;
#define GF_EXPORT
#define GF_BAD_PARAM 1
#define GF_OUT_OF_MEM 2
#define GF_OK 0

#define GF_ISOM_BOX_TYPE_TX3G 0x74783367
#define GF_ISOM_BOX_TYPE_TEXT 0x74657874

#define GF_ISOM_MEDIA_TEXT 0x74657874
#define GF_ISOM_MEDIA_SUBT 0x73756274
#define GF_ISOM_MEDIA_MPEG_SUBT 0x6D707367

#define GF_ODF_TX3G_TAG 0x74783367

typedef struct {
    u32 fontID;
    char* fontName;
} GF_FontRecord;

typedef struct {
    u32 style_flags;
    u32 text_color;
} GF_DefaultStyle;

typedef struct {
    u32 back_color;
    u32 default_pos;
    GF_DefaultStyle default_style;
    u32 displayFlags;
    s32 vert_justif;
    u32 horiz_justif;
    u32 font_count;
    GF_FontRecord* fonts;
} GF_TextSampleDescriptor;

typedef struct {
    u32 entry_count;
    GF_FontRecord* fonts;
} GF_FontTable;

typedef struct {
    u32 type;
    u32 back_color;
    u32 default_box;
    GF_DefaultStyle default_style;
    u32 displayFlags;
    u32 vertical_justification;
    u32 horizontal_justification;
    GF_FontTable* font_table;
} GF_Tx3gSampleEntryBox;

typedef struct {
    u32 type;
    u32 background_color;
    u32 default_box;
    u32 foreground_color;
    u32 displayFlags;
    u32 textJustification;
    char* textName;
} GF_TextSampleEntryBox;

typedef struct {
    u32 handlerType;
} GF_HandlerBox;

typedef struct {
    void* child_boxes;
} GF_SampleDescriptionBox;

typedef struct {
    GF_SampleDescriptionBox* SampleDescription;
} GF_SampleTable;

typedef struct {
    GF_SampleTable* sampleTable;
} GF_MediaInformation;

typedef struct {
    GF_HandlerBox* handler;
    GF_MediaInformation* information;
} GF_MediaBox;

typedef struct {
    GF_MediaBox* Media;
} GF_TrackBox;

typedef struct {
} GF_ISOFile;

GF_TrackBox* gf_isom_get_track_from_file(GF_ISOFile* movie, u32 trackNumber);
void* gf_list_get(void* list, u32 index);
void* gf_odf_desc_new(u32 tag);
void* gf_malloc(size_t size);
char* gf_strdup(const char* str);
u32 rgb_48_to_32(u32 color);