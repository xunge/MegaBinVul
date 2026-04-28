#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef unsigned char Bool;
#define GF_TRUE 1
#define GF_FALSE 0

typedef unsigned int u32;
typedef unsigned char u8;

typedef enum {
    GF_OK = 0,
    GF_OUT_OF_MEM,
    GF_BAD_PARAM,
    GF_ISOM_BOX_TYPE_SENC,
    GF_ISOM_BOX_UUID_PSEC,
    GF_CRYPT_TYPE_PIFF,
    GF_CRYPT_TYPE_CENC,
    GF_CRYPT_TYPE_CBC1,
    GF_CRYPT_TYPE_CENS,
    GF_ISOM_OMADRM_SCHEME,
    GF_CRYPT_SELENC_RAP,
    GF_CRYPT_SELENC_NON_RAP,
    GF_CRYPT_SELENC_RAND,
    GF_CRYPT_SELENC_RAND_RANGE,
    GF_CRYPT_SELENC_RANGE,
    GF_CRYPT_SELENC_PREVIEW,
    GF_CRYPT_SELENC_CLEAR,
    GF_CRYPT_SELENC_CLEAR_FORCED,
    GF_KEYROLL_SAMPLES,
    GF_KEYROLL_SEGMENTS,
    GF_KEYROLL_PERIODS,
    GF_KEYROLL_SAPS
} GF_Err;

typedef struct {
    char *name;
    char *value;
} GF_XMLAttribute;

typedef struct {
    u8 key[16];
    u8 KID[16];
    u8 IV[16];
    u8 IV_size;
    u8 constant_IV_size;
    char *hls_info;
} GF_CryptKeyInfo;

typedef struct {
    u32 trackID;
    u32 scheme_type;
    Bool force_type;
    u32 sel_enc_type;
    u32 sel_enc_range;
    u32 force_clear_stsd_idx;
    u32 ipmp_type;
    u32 ipmp_desc_id;
    u32 encryption;
    char TransactionID[17];
    Bool IsEncrypted;
    u32 sai_saved_box_type;
    GF_CryptKeyInfo *keys;
    u32 nb_keys;
    char *KMS_URI;
    char *Scheme_URI;
    u32 roll_type;
    u32 keyRoll;
    u32 defaultKeyIdx;
    Bool rand_keys;
    char *metadata;
    u32 crypt_byte_block;
    u32 skip_byte_block;
    u32 clear_bytes;
    Bool allow_encrypted_slice_header;
    u32 block_align;
    char *subs_crypt;
    u32 subs_rand;
    Bool multi_key;
    u32 mkey_roll_plus_one;
    char *mkey_subs;
} GF_TrackCryptInfo;

typedef struct {
    u32 in_text_header;
    u32 def_crypt_type;
    GF_Err last_parse_error;
    Bool has_common_key;
    void *tcis;
} GF_CryptInfo;

static GF_Err gf_bin128_parse(const char *value, u8 *out) {
    return GF_OK;
}

static u32 cryptinfo_get_crypt_type(const char *value) {
    return 0;
}

static void *gf_list_last(void *list) {
    return NULL;
}

static void gf_list_add(void *list, void *item) {
}

static void *gf_malloc(size_t size) {
    return malloc(size);
}

static void *gf_realloc(void *ptr, size_t size) {
    return realloc(ptr, size);
}

static void gf_free(void *ptr) {
    free(ptr);
}

static char *gf_strdup(const char *str) {
    return strdup(str);
}

static size_t gf_base64_encode(const void *in, size_t in_size, char *out, size_t out_size) {
    return 0;
}

static int stricmp(const char *s1, const char *s2) {
    return strcasecmp(s1, s2);
}

static int strnicmp(const char *s1, const char *s2, size_t n) {
    return strncasecmp(s1, s2, n);
}

#define GF_SAFEALLOC(ptr, type) ptr = (type *)gf_malloc(sizeof(type)); if (ptr) memset(ptr, 0, sizeof(type))

#define GF_LOG(level, category, message)