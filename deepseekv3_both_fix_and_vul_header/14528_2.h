#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

typedef uint32_t u32;
#define LLD PRId64

#define GF_ODF_OD_UPDATE_TAG 0x01
#define GF_ODF_ESD_TAG 0x03
#define GF_ODF_MUXINFO_TAG 0x04

typedef struct {
    u32 ESID;
    u32 timeScale;
} GF_ESOwner;

typedef struct {
    u32 tag;
    u32 streamType;
    u32 objectTypeIndication;
} GF_DecoderConfig;

typedef struct {
    u32 tag;
    GF_DecoderConfig *decoderConfig;
    u32 ESID;
    void *extensionDescriptors;
} GF_ESD;

typedef struct {
    u32 tag;
    char *file_name;
} GF_MuxInfo;

typedef struct {
    void *ESDescriptors;
    char *URLString;
} GF_ObjectDescriptor;

typedef struct {
    u32 tag;
    void *objectDescriptors;
} GF_ODUpdate;

typedef struct {
    void *commands;
    GF_ESOwner *owner;
    u32 timing;
} GF_AUContext;

typedef struct {
    FILE *trace;
} GF_SceneDumper;

typedef void* (*gf_list_get_func)(void*, u32);
typedef u32 (*gf_list_count_func)(void*);
typedef int (*gf_fprintf_func)(FILE*, const char*, ...);

extern gf_list_get_func gf_list_get;
extern gf_list_count_func gf_list_count;
extern gf_fprintf_func gf_fprintf;