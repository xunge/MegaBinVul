#include <stdlib.h>
#include <string.h>

typedef int GF_Err;
#define GF_OK 0
#define GF_OUT_OF_MEM -1

typedef struct GF_Descriptor GF_Descriptor;
typedef struct GF_IsomInitialObjectDescriptor GF_IsomInitialObjectDescriptor;
typedef struct GF_IsomObjectDescriptor GF_IsomObjectDescriptor;
typedef struct GF_IsomIODS GF_IsomIODS;
typedef struct GF_MoovBox GF_MoovBox;
typedef struct GF_ISOFile GF_ISOFile;

#define GF_ODF_ISOM_IOD_TAG 0

struct GF_IsomInitialObjectDescriptor {
    void* ES_ID_IncDescriptors;
    void* ES_ID_RefDescriptors;
    void* extensionDescriptors;
    void* IPMP_Descriptors;
    int objectDescriptorID;
    void* OCIDescriptors;
    int tag;
    char* URLString;
};

struct GF_IsomObjectDescriptor {
    void* ES_ID_IncDescriptors;
    void* extensionDescriptors;
    void* IPMP_Descriptors;
    int objectDescriptorID;
    void* OCIDescriptors;
    char* URLString;
};

struct GF_Descriptor {
    int tag;
};

struct GF_IsomIODS {
    GF_Descriptor* descriptor;
};

struct GF_MoovBox {
    GF_IsomIODS* iods;
};

struct GF_ISOFile {
    GF_MoovBox* moov;
};

void* gf_malloc(size_t size);
void gf_odf_desc_del(GF_Descriptor* desc);
GF_Err gf_isom_insert_moov(GF_ISOFile* movie);
void AddMovieIOD(GF_MoovBox* moov, int flag);