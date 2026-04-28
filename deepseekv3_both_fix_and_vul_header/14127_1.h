#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

typedef uint32_t u32;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint64_t u64;
typedef int Bool;

#define GF_FALSE 0
#define GF_TRUE 1

typedef struct GF_BitStream GF_BitStream;

typedef struct {
    int roll_distance;
} GF_RollRecoveryEntry;

typedef struct {
    int num_leading_samples_known;
    int num_leading_samples;
} GF_VisualRandomAccessEntry;

typedef struct {
    int dependent_flag;
    int SAP_type;
} GF_SAPEntry;

typedef struct {
    int NALU_type;
} GF_SYNCEntry;

typedef struct {
    int level_independently_decodable;
} GF_TemporalLevelEntry;

typedef struct {
    int crypt_byte_block;
    int skip_byte_block;
    u8 IsProtected;
    u8 Per_Sample_IV_size;
    u8 KID[16];
    u8 constant_IV_size;
    u8 constant_IV[16];
} GF_CENCSampleEncryptionGroupEntry;

typedef struct {
    u32 length;
    u8 *data;
} GF_DefaultSampleGroupDescriptionEntry;

typedef struct GF_OperatingPointsInformation GF_OperatingPointsInformation;
typedef struct GF_LHVCLayerInformation GF_LHVCLayerInformation;

enum {
    GF_ISOM_SAMPLE_GROUP_ROLL = 0x726f6c6c,
    GF_ISOM_SAMPLE_GROUP_PROL = 0x70726f6c,
    GF_ISOM_SAMPLE_GROUP_RAP = 0x72617020,
    GF_ISOM_SAMPLE_GROUP_SAP = 0x73617020,
    GF_ISOM_SAMPLE_GROUP_SYNC = 0x73796e63,
    GF_ISOM_SAMPLE_GROUP_TELE = 0x74656c65,
    GF_ISOM_SAMPLE_GROUP_SEIG = 0x73656967,
    GF_ISOM_SAMPLE_GROUP_OINF = 0x6f696e66,
    GF_ISOM_SAMPLE_GROUP_LINF = 0x6c696e66,
    GF_ISOM_SAMPLE_GROUP_TRIF = 0x74726966,
    GF_ISOM_SAMPLE_GROUP_NALM = 0x6e616c6d,
    GF_ISOM_SAMPLE_GROUP_TSAS = 0x74736173,
    GF_ISOM_SAMPLE_GROUP_STSA = 0x73747361,
    GF_ISOM_SAMPLE_GROUP_TSCL = 0x7473636c,
    GF_ISOM_SAMPLE_GROUP_LBLI = 0x6c626c69
};

#define GF_SAFEALLOC(ptr, type) ptr = (type *)malloc(sizeof(type))
#define gf_bs_read_int(bs, bits) 0
#define gf_bs_read_u8(bs) 0
#define gf_bs_read_data(bs, buf, size) 0
#define gf_bs_get_position(bs) 0
#define gf_bs_peek_bits(bs, bits, pos) 0
#define gf_bs_seek(bs, pos) 0
#define gf_malloc(size) malloc(size)
#define GF_LOG(level, category, message)

GF_OperatingPointsInformation *gf_isom_oinf_new_entry() { return NULL; }
void gf_isom_oinf_read_entry(GF_OperatingPointsInformation *ptr, GF_BitStream *bs) {}

GF_LHVCLayerInformation *gf_isom_linf_new_entry() { return NULL; }
void gf_isom_linf_read_entry(GF_LHVCLayerInformation *ptr, GF_BitStream *bs) {}

char *gf_4cc_to_str(u32 type) { return ""; }