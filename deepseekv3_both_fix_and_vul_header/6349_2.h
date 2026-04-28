#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct GF_Descriptor GF_Descriptor;
typedef struct GF_ObjectDescriptor GF_ObjectDescriptor;
typedef struct GF_InitialObjectDescriptor GF_InitialObjectDescriptor;
typedef struct GF_IsomObjectDescriptor GF_IsomObjectDescriptor;
typedef struct GF_IsomInitialObjectDescriptor GF_IsomInitialObjectDescriptor;
typedef struct GF_ESD GF_ESD;
typedef struct GF_ES_ID_Inc GF_ES_ID_Inc;
typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_IsomODS GF_IsomODS;

#define GF_EXPORT
#define GF_ODF_ISOM_OD_TAG 1
#define GF_ODF_ISOM_IOD_TAG 2
#define GF_ODF_OD_TAG 3
#define GF_ODF_IOD_TAG 4

struct GF_Descriptor {
    int tag;
};

struct GF_ObjectDescriptor {
    int objectDescriptorID;
    void *ESDescriptors;
    void *extensionDescriptors;
    void *IPMP_Descriptors;
    void *OCIDescriptors;
    char *URLString;
    int tag;
};

struct GF_InitialObjectDescriptor {
    int objectDescriptorID;
    void *ESDescriptors;
    void *extensionDescriptors;
    void *IPMP_Descriptors;
    void *OCIDescriptors;
    char *URLString;
    int tag;
    int audio_profileAndLevel;
    int graphics_profileAndLevel;
    int inlineProfileFlag;
    int OD_profileAndLevel;
    int scene_profileAndLevel;
    int visual_profileAndLevel;
    void *IPMPToolList;
};

struct GF_IsomObjectDescriptor {
    int objectDescriptorID;
    void *ES_ID_IncDescriptors;
    void *extensionDescriptors;
    void *IPMP_Descriptors;
    void *OCIDescriptors;
    char *URLString;
    int tag;
};

struct GF_IsomInitialObjectDescriptor {
    int objectDescriptorID;
    void *ES_ID_IncDescriptors;
    void *extensionDescriptors;
    void *IPMP_Descriptors;
    void *OCIDescriptors;
    char *URLString;
    int tag;
    int audio_profileAndLevel;
    int graphics_profileAndLevel;
    int inlineProfileFlag;
    int OD_profileAndLevel;
    int scene_profileAndLevel;
    int visual_profileAndLevel;
    void *IPMPToolList;
};

struct GF_ES_ID_Inc {
    int trackID;
};

struct GF_IsomODS {
    GF_Descriptor *descriptor;
};

struct GF_ISOFile {
    struct {
        GF_IsomODS *iods;
    } *moov;
    int LastError;
    int disable_odf_translate;
};

void *gf_malloc(size_t size);
void *gf_list_new();
void *gf_list_enum(void *list, u32 *pos);
int gf_list_add(void *list, void *item);
int gf_odf_desc_copy(GF_Descriptor *src, GF_Descriptor **dst);
void gf_odf_desc_del(GF_Descriptor *desc);
int GetESDForTime(void *moov, int trackID, int time, GF_ESD **esd);