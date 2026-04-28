#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint32_t u32;
typedef uint64_t u64;
typedef uint8_t u8;

#define GF_PROP_UINT_LIST 1
#define GF_PROP_STRING_LIST 2
#define GF_PROP_PID_CHAP_TIMES 3
#define GF_PROP_PID_CHAP_NAMES 4
#define GF_ISOM_REF_CHAP 5
#define GF_BITSTREAM_READ 6

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

typedef struct {
    u8 *data;
    u32 dataLength;
    u64 DTS;
} GF_ISOSample;

typedef struct {
    char *text;
} GF_TextSample;

u32 gf_isom_get_chapter_count(GF_ISOFile *file, u32 track);
void gf_isom_get_chapter(GF_ISOFile *file, u32 track, u32 chapter, u64 *start, const char **name);
u32 gf_isom_get_track_count(GF_ISOFile *file);
u32 gf_isom_get_reference_count(GF_ISOFile *file, u32 track, u32 reference_type);
void gf_isom_get_reference(GF_ISOFile *file, u32 track, u32 reference_type, u32 reference_index, u32 *reference_track);
u32 gf_isom_get_sample_count(GF_ISOFile *file, u32 track);
GF_ISOSample *gf_isom_get_sample(GF_ISOFile *file, u32 track, u32 sample_number, u32 *description_index);
void gf_isom_sample_del(GF_ISOSample **sample);
GF_BitStream *gf_bs_new(const void *buffer, u64 size, u32 mode);
void gf_bs_del(GF_BitStream *bs);
GF_TextSample *gf_isom_parse_text_sample(GF_BitStream *bs);
void gf_isom_delete_text_sample(GF_TextSample *sample);
void *gf_malloc(size_t size);
void gf_free(void *ptr);
char *gf_strdup(const char *str);
void gf_filter_pid_set_property(GF_FilterPid *pid, u32 property, GF_PropertyValue *value);