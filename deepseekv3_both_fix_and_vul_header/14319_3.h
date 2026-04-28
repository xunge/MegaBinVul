#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define GF_ODF_OD_UPDATE_TAG 0x01
#define GF_ODF_ESD_TAG 0x03
#define GF_ODF_MUXINFO_TAG 0x06

typedef uint32_t u32;
typedef int64_t LLD;

typedef struct {
    u32 tag;
    void *extensionDescriptors;
    u32 ESID;
    struct {
        u32 streamType;
        u32 objectTypeIndication;
    } *decoderConfig;
} GF_ESD;

typedef struct {
    u32 tag;
    char *URLString;
    void *ESDescriptors;
} GF_ObjectDescriptor;

typedef struct {
    u32 tag;
    void *objectDescriptors;
} GF_ODUpdate;

typedef struct {
    u32 tag;
    char *file_name;
} GF_MuxInfo;

typedef struct {
    u32 ESID;
    u32 timeScale;
} GF_AUOwner;

typedef struct {
    void *commands;
    GF_AUOwner *owner;
    LLD timing;
} GF_AUContext;

typedef struct {
    FILE *trace;
} GF_SceneDumper;

void *gf_list_get(void *list, u32 index);
u32 gf_list_count(void *list);
int gf_fprintf(FILE *stream, const char *format, ...);

#define LLD PRId64