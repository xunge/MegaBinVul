#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef int32_t pj_status_t;
typedef uint32_t pj_uint32_t;
typedef int pj_bool_t;
#define PJ_FALSE 0
#define PJ_SUCCESS 0
#define PJSIP_EINVALIDALGORITHM -1
#define PJSIP_EINVALIDQOP -2

#define PJSIP_AUTH_HAS_DIGEST_SHA256 1
#define PJSIP_SHA256STRLEN 64
#define PJSIP_MD5STRLEN 32
#define EXT_MASK 0x0F
#define PJSIP_CRED_DATA_EXT_AKA 1

#define THIS_FILE "respond_digest.c"

typedef struct {
    char *ptr;
    int slen;
} pj_str_t;

typedef struct {
    pj_str_t username;
    pj_str_t realm;
    pj_str_t nonce;
    pj_str_t uri;
    pj_str_t response;
    pj_str_t algorithm;
    pj_str_t opaque;
    pj_str_t qop;
    pj_str_t nc;
    pj_str_t cnonce;
} pjsip_digest_credential;

typedef struct {
    pj_str_t algorithm;
    pj_str_t realm;
    pj_str_t nonce;
    pj_str_t opaque;
    pj_str_t qop;
} pjsip_digest_challenge;

typedef struct {
    pj_str_t username;
    int data_type;
    union {
        struct {
            pj_status_t (*cb)(void*, void*, void*, void*, void*);
        } aka;
    } ext;
} pjsip_cred_info;

typedef struct pj_pool_t pj_pool_t;

static const pj_str_t pjsip_MD5_STR = { "MD5", 3 };
static const pj_str_t pjsip_SHA256_STR = { "SHA-256", 7 };
static const pj_str_t pjsip_AUTH_STR = { "auth", 4 };
static const pj_str_t pjsip_AKAv1_MD5_STR = { "AKAv1-MD5", 9 };

static pj_bool_t has_auth_qop(pj_pool_t *pool, const pj_str_t *qop);
static int pj_stricmp(const pj_str_t *s1, const pj_str_t *s2);
static void pj_strdup(pj_pool_t *pool, pj_str_t *dst, const pj_str_t *src);
static void* pj_pool_alloc(pj_pool_t *pool, int size);
static int pj_ansi_snprintf(char *buf, int size, const char *format, ...);
static void PJ_LOG(int level, const char *format, ...);
static pj_status_t pjsip_auth_create_digest(pj_str_t *digest, ...);
static pj_status_t pjsip_auth_create_digestSHA256(pj_str_t *digest, ...);