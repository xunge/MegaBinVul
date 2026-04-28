#include <stdlib.h>
#include <string.h>

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct {
    u32 *vals;
    u32 nb_items;
} GF_PropUIntList;

typedef struct {
    char **vals;
    u32 nb_items;
} GF_PropStringList;

typedef struct {
    int type;
    union {
        GF_PropUIntList uint_list;
        GF_PropStringList string_list;
    } value;
} GF_PropertyValue;

typedef struct GF_ISOFile GF_ISOFile;
typedef struct GF_FilterPid GF_FilterPid;
typedef struct GF_BitStream GF_BitStream;

typedef struct GF_ISOSample {
    u8 *data;
    u32 dataLength;
    u64 DTS;
} GF_ISOSample;

typedef struct GF_TextSample {
    char *text;
} GF_TextSample;

#define GF_PROP_UINT_LIST 1
#define GF_PROP_STRING_LIST 2
#define GF_PROP_PID_CHAP_TIMES 3
#define GF_PROP_PID_CHAP_NAMES 4
#define GF_ISOM_REF_CHAP 5
#define GF_BITSTREAM_READ 6

static u32 gf_isom_get_chapter_count(GF_ISOFile *file, u32 track);
static void gf_isom_get_chapter(GF_ISOFile *file, u32 track, u32 chapter, u64 *start, const char **name);
static u32 gf_isom_get_track_count(GF_ISOFile *file);
static u32 gf_isom_get_reference_count(GF_ISOFile *file, u32 track, u32 ref_type);
static void gf_isom_get_reference(GF_ISOFile *file, u32 track, u32 ref_type, u32 idx, u32 *ref_track);
static u32 gf_isom_get_sample_count(GF_ISOFile *file, u32 track);
static GF_ISOSample *gf_isom_get_sample(GF_ISOFile *file, u32 track, u32 sample, u32 *di);
static void gf_isom_sample_del(GF_ISOSample **sample);
static GF_BitStream *gf_bs_new(const void *data, u64 size, u32 mode);
static void gf_bs_del(GF_BitStream *bs);
static GF_TextSample *gf_isom_parse_text_sample(GF_BitStream *bs);
static void gf_isom_delete_text_sample(GF_TextSample *txt);
static void gf_filter_pid_set_property(GF_FilterPid *pid, u32 prop, GF_PropertyValue *value);
static void *gf_malloc(size_t size);
static void gf_free(void *ptr);
static char *gf_strdup(const char *str);