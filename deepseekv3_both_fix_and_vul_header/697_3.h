#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef int32_t GF_Err;
typedef uint32_t u32;
typedef uint64_t u64;

#define GF_OK 0
#define GF_ISOM_INVALID_MEDIA 1
#define ERROR_ON_DUPLICATED_BOX(a, ptr) { return GF_ISOM_INVALID_MEDIA; }

#define GF_BITSTREAM_READ 0
#define GF_LOG_WARNING 1
#define GF_LOG_CONTAINER 2

typedef struct GF_Box {
    u32 type;
} GF_Box;

typedef struct GF_ESDBox {
    GF_Box box;
} GF_ESDBox;

typedef struct GF_3GPPConfigBox {
    GF_Box box;
    struct {
        u32 type;
    } cfg;
} GF_3GPPConfigBox;

typedef struct GF_AC3ConfigBox {
    GF_Box box;
} GF_AC3ConfigBox;

typedef struct GF_MHAConfigBox {
    GF_Box box;
} GF_MHAConfigBox;

typedef struct GF_UnknownBox {
    GF_Box box;
    u32 original_4cc;
    char* data;
    u32 dataSize;
    void* other_boxes;
} GF_UnknownBox;

typedef struct GF_MPEGAudioSampleEntryBox {
    GF_Box box;
    GF_ESDBox* esd;
    void* protections;
    GF_3GPPConfigBox* cfg_3gpp;
    GF_AC3ConfigBox* cfg_ac3;
    GF_MHAConfigBox* cfg_mha;
    u32 type;
} GF_MPEGAudioSampleEntryBox;

typedef struct GF_BitStream GF_BitStream;

enum {
    GF_ISOM_BOX_TYPE_ESDS,
    GF_ISOM_BOX_TYPE_SINF,
    GF_ISOM_BOX_TYPE_DAMR,
    GF_ISOM_BOX_TYPE_DEVC,
    GF_ISOM_BOX_TYPE_DQCP,
    GF_ISOM_BOX_TYPE_DSMV,
    GF_ISOM_BOX_TYPE_DAC3,
    GF_ISOM_BOX_TYPE_DEC3,
    GF_ISOM_BOX_TYPE_MHA1,
    GF_ISOM_BOX_TYPE_MHA2,
    GF_ISOM_BOX_TYPE_MHM1,
    GF_ISOM_BOX_TYPE_MHM2,
    GF_ISOM_BOX_TYPE_WAVE,
    GF_ISOM_BOX_TYPE_UNKNOWN
};

GF_Err gf_isom_box_add_default(GF_Box *s, GF_Box *a);
GF_Err gf_isom_box_parse(GF_Box **a, GF_BitStream *bs);
void gf_isom_box_add_for_dump_mode(GF_Box *ptr, GF_Box *a);
void gf_isom_box_del(GF_Box *a);
void GF_LOG(u32 level, u32 category, const char* fmt, ...);

void* gf_list_add(void* list, void* item);
u32 gf_list_count(void* list);
void* gf_list_get(void* list, u32 index);

GF_BitStream* gf_bs_new(const void* data, u64 size, u32 mode);
void gf_bs_del(GF_BitStream* bs);

char* gf_4cc_to_str(u32 type);