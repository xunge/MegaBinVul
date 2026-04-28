#include <stdlib.h>
#include <string.h>

typedef int GF_Err;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned long long u64;
typedef unsigned char u8;

#define GF_BAD_PARAM 1
#define GF_OK 0
#define GF_OUT_OF_MEM 2
#define GF_ISOM_INVALID_FILE 3

#define GF_ODF_OD_UPDATE_TAG 1
#define GF_ODF_ESD_UPDATE_TAG 2
#define GF_ODF_ESD_REMOVE_TAG 3
#define GF_ODF_ESD_REMOVE_REF_TAG 4
#define GF_ODF_OD_TAG 5
#define GF_ODF_ISOM_OD_TAG 6
#define GF_ODF_ISOM_IOD_TAG 7

#define GF_ISOM_BOX_TYPE_MPOD 0x6d706f64

typedef struct GF_ISOSample {
    void *data;
    u32 dataLength;
    u64 DTS;
} GF_ISOSample;

typedef struct GF_MediaBox {
    struct {
        void *moov;
        u32 *trackIDs;
        u32 trackIDCount;
    } *mediaTrack;
} GF_MediaBox;

typedef struct GF_TrackReferenceTypeBox {
    u32 *trackIDs;
    u32 trackIDCount;
} GF_TrackReferenceTypeBox;

typedef struct GF_Descriptor {
    u32 tag;
} GF_Descriptor;

typedef struct GF_ObjectDescriptor {
    u32 tag;
    u16 objectDescriptorID;
    char *URLString;
    void *extensionDescriptors;
    void *IPMP_Descriptors;
    void *OCIDescriptors;
    void *ESDescriptors;
} GF_ObjectDescriptor;

typedef struct GF_InitialObjectDescriptor {
    GF_ObjectDescriptor base;
    u8 audio_profileAndLevel;
    u8 inlineProfileFlag;
    u8 graphics_profileAndLevel;
    u8 OD_profileAndLevel;
    u8 scene_profileAndLevel;
    u8 visual_profileAndLevel;
    void *IPMPToolList;
} GF_InitialObjectDescriptor;

typedef struct GF_IsomObjectDescriptor {
    u32 tag;
    u16 objectDescriptorID;
    char *URLString;
    void *extensionDescriptors;
    void *IPMP_Descriptors;
    void *OCIDescriptors;
    void *ES_ID_RefDescriptors;
} GF_IsomObjectDescriptor;

typedef struct GF_IsomInitialObjectDescriptor {
    GF_IsomObjectDescriptor base;
    u8 audio_profileAndLevel;
    u8 inlineProfileFlag;
    u8 graphics_profileAndLevel;
    u8 OD_profileAndLevel;
    u8 scene_profileAndLevel;
    u8 visual_profileAndLevel;
    void *IPMPToolList;
} GF_IsomInitialObjectDescriptor;

typedef struct GF_ESD {
    GF_Descriptor base;
} GF_ESD;

typedef struct GF_ES_ID_Ref {
    u16 trackRef;
} GF_ES_ID_Ref;

typedef struct GF_ODCom {
    u32 tag;
} GF_ODCom;

typedef struct GF_ODUpdate {
    GF_ODCom base;
    void *objectDescriptors;
} GF_ODUpdate;

typedef struct GF_ESDUpdate {
    GF_ODCom base;
    u16 ODID;
    void *ESDescriptors;
} GF_ESDUpdate;

typedef struct GF_ESDRemove {
    GF_ODCom base;
    u16 ODID;
    u32 NbESDs;
    u16 *ES_ID;
} GF_ESDRemove;

typedef struct GF_ODCodec GF_ODCodec;

GF_Err Track_FindRef(void *track, u32 type, GF_TrackReferenceTypeBox **ref);
GF_Err GetESDForTime(void *moov, u32 trackID, u64 DTS, GF_ESD **esd);
GF_Err gf_isom_get_track_from_id(void *moov, u32 trackID);
GF_ODCodec *gf_odf_codec_new();
void gf_odf_codec_del(GF_ODCodec *codec);
GF_Err gf_odf_codec_set_au(GF_ODCodec *codec, void *data, u32 length);
GF_Err gf_odf_codec_decode(GF_ODCodec *codec);
GF_ODCom *gf_odf_codec_get_com(GF_ODCodec *codec);
GF_ODCom *gf_odf_com_new(u32 tag);
GF_Err gf_odf_desc_copy(GF_Descriptor *desc, GF_Descriptor **copy);
void *gf_malloc(size_t size);
void *gf_realloc(void *ptr, size_t size);
void gf_free(void *ptr);
GF_Err gf_odf_desc_add_desc(GF_Descriptor *parent, GF_Descriptor *child);
void gf_odf_desc_del(GF_Descriptor *desc);
void gf_odf_com_del(GF_ODCom **com);
GF_Err gf_odf_codec_add_com(GF_ODCodec *codec, GF_ODCom *com);
GF_Err gf_odf_codec_encode(GF_ODCodec *codec, int flag);
GF_Err gf_odf_codec_get_au(GF_ODCodec *codec, void **data, u32 *length);
void *gf_list_new();
void *gf_list_enum(void *list, u32 *pos);
void gf_list_add(void *list, void *item);