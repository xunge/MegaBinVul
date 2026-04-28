#include <stdlib.h>
#include <string.h>
#include <strings.h>

typedef int pj_status_t;
typedef unsigned pj_bool_t;
typedef unsigned pj_uint32_t;

#define PJ_EINVAL 1
#define PJ_SUCCESS 0
#define PJMEDIA_CODEC_EUNSUP -1
#define PJ_ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

typedef struct pj_str_t {
    char *ptr;
    pj_uint32_t slen;
} pj_str_t;

typedef struct pjmedia_codec_info {
    pj_str_t encoding_name;
    unsigned clock_rate;
    unsigned channel_cnt;
} pjmedia_codec_info;

typedef struct pjmedia_codec_op {
    // Placeholder for codec operations
} pjmedia_codec_op;

typedef struct pjmedia_codec {
    struct pjmedia_codec_op *op;
    void *factory;
    void *codec_data;
} pjmedia_codec;

typedef struct pjmedia_codec_factory {
    void *base;
    void *mutex;
    void *endpt;
} pjmedia_codec_factory;

typedef struct pj_pool_t {
    // Placeholder for pool structure
} pj_pool_t;

typedef struct codec_private_t {
    pj_pool_t *pool;
    int codec_idx;
} codec_private_t;

struct codec_desc_t {
    const char *name;
    int clock_rate;
    int channel_count;
    pj_bool_t enabled;
};

extern pjmedia_codec_factory codec_factory;
extern const struct codec_desc_t codec_desc[1];  // Changed to array of size 1
extern pjmedia_codec_op codec_op;

static int pj_stricmp(const pj_str_t *s1, const pj_str_t *s2) {
    return strcasecmp(s1->ptr, s2->ptr);
}

static pj_str_t pj_str(char *s) {
    pj_str_t str;
    str.ptr = s;
    str.slen = strlen(s);
    return str;
}

#define PJ_ASSERT_RETURN(expr, retval) if (!(expr)) return (retval)

static void pj_mutex_lock(void *mutex) {}
static void pj_mutex_unlock(void *mutex) {}

static pj_pool_t* pjmedia_endpt_create_pool(void *endpt, const char *name, int size1, int size2) {
    return NULL;
}

#define PJ_POOL_ZALLOC_T(pool, type) ((type*)calloc(1, sizeof(type)))