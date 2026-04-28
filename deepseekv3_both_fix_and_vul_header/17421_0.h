#include <stdio.h>
#include <stdint.h>

typedef uint32_t u32;
typedef int32_t GF_Err;

#define GF_OK 0
#define GF_BAD_PARAM 1

typedef struct __tag_box GF_Box;
typedef struct __tag_list GF_List;

typedef struct {
    GF_Box *a;
    uint32_t grouping_type;
    uint32_t version;
    uint32_t default_length;
    uint32_t default_description_index;
    GF_List *group_descriptions;
    uint32_t size;
} GF_SampleGroupDescriptionBox;

typedef struct {
    int32_t roll_distance;
} GF_RollRecoveryEntry;

typedef struct {
    uint8_t level_independently_decodable;
} GF_TemporalLevelEntry;

typedef struct {
    uint8_t num_leading_samples_known;
    uint32_t num_leading_samples;
} GF_VisualRandomAccessEntry;

typedef struct {
    uint8_t NALU_type;
} GF_SYNCEntry;

typedef struct {
    uint8_t IsProtected;
    uint8_t Per_Sample_IV_size;
    uint8_t KID[16];
    uint8_t constant_IV_size;
    uint8_t *constant_IV;
} GF_CENCSampleEncryptionGroupEntry;

typedef struct {
    uint32_t length;
    uint8_t *data;
} GF_DefaultSampleGroupDescriptionEntry;

typedef struct {
    uint8_t dependent_flag;
    uint8_t SAP_type;
} GF_SAPEntry;

void gf_isom_box_dump_start(GF_Box *a, const char *name, FILE *trace);
void gf_isom_box_dump_done(const char *name, GF_Box *a, FILE *trace);
const char *gf_4cc_to_str(uint32_t type);
uint32_t gf_list_count(GF_List *list);
void *gf_list_get(GF_List *list, uint32_t index);
void dump_data_hex(FILE *trace, char *data, uint32_t size);
void dump_data(FILE *trace, char *data, uint32_t size);
void oinf_entry_dump(void *entry, FILE *trace);
void linf_dump(void *entry, FILE *trace);
void trif_dump(FILE *trace, char *data, uint32_t length);
void nalm_dump(FILE *trace, char *data, uint32_t length);

#define GF_ISOM_SAMPLE_GROUP_ROLL 0
#define GF_ISOM_SAMPLE_GROUP_PROL 1
#define GF_ISOM_SAMPLE_GROUP_TELE 2
#define GF_ISOM_SAMPLE_GROUP_RAP 3
#define GF_ISOM_SAMPLE_GROUP_SYNC 4
#define GF_ISOM_SAMPLE_GROUP_SEIG 5
#define GF_ISOM_SAMPLE_GROUP_OINF 6
#define GF_ISOM_SAMPLE_GROUP_LINF 7
#define GF_ISOM_SAMPLE_GROUP_TRIF 8
#define GF_ISOM_SAMPLE_GROUP_NALM 9
#define GF_ISOM_SAMPLE_GROUP_SAP 10