#include <stdlib.h>
#include <string.h>
#include <strings.h>

typedef int pj_status_t;
typedef unsigned pj_bool_t;

#define PJ_EINVAL 1
#define PJ_ENOMEM 2
#define PJ_SUCCESS 0
#define PJMEDIA_CODEC_EFAILED 3
#define PJ_ASSERT_RETURN(expr, retval) if (!(expr)) return (retval)
#define PJ_POOL_ZALLOC_T(pool, type) ((type*)calloc(1, sizeof(type)))
#define PJ_ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

struct pj_str_t {
    char *ptr;
    size_t slen;
};

struct pjmedia_codec_info {
    struct pj_str_t encoding_name;
    unsigned clock_rate;
    unsigned channel_cnt;
};

struct pjmedia_codec_op {
    int dummy;
};

struct pjmedia_codec_factory {
    int dummy;
};

struct pjmedia_codec {
    const struct pjmedia_codec_op *op;
    struct pjmedia_codec_factory *factory;
    void *codec_data;
};

struct pj_pool_t {
    int dummy;
};

struct pj_mutex_t {
    int dummy;
};

struct pjmedia_endpt {
    int dummy;
};

struct and_media_private_t {
    struct pj_pool_t *pool;
    int codec_idx;
    void *plc;
    void *vad;
    void *enc;
    void *dec;
};

struct and_media_codec_t {
    const char *name;
    int clock_rate;
    int channel_count;
    int samples_per_frame;
    pj_bool_t enabled;
    pj_bool_t has_native_plc;
    pj_bool_t has_native_vad;
};

struct and_media_factory_t {
    struct pjmedia_codec_factory base;
    struct pj_mutex_t *mutex;
    struct pjmedia_endpt *endpt;
};

extern struct and_media_factory_t and_media_factory;
extern struct and_media_codec_t and_media_codec[10];  // 假设数组大小为10
extern const struct pjmedia_codec_op and_media_op;

static struct pj_str_t pj_str(char *s) {
    struct pj_str_t str;
    str.ptr = s;
    str.slen = strlen(s);
    return str;
}

static int pj_stricmp(const struct pj_str_t *s1, const struct pj_str_t *s2) {
    return strcasecmp(s1->ptr, s2->ptr);
}

static void pj_mutex_lock(struct pj_mutex_t *mutex) {}
static void pj_mutex_unlock(struct pj_mutex_t *mutex) {}

static struct pj_pool_t* pjmedia_endpt_create_pool(struct pjmedia_endpt *endpt, 
                                                  const char *name, 
                                                  int initial_size, 
                                                  int increment_size) {
    return (struct pj_pool_t*)calloc(1, sizeof(struct pj_pool_t));
}

static pj_status_t pjmedia_plc_create(struct pj_pool_t *pool, 
                                     int clock_rate, 
                                     int samples_per_frame, 
                                     int options, 
                                     void **plc) {
    return PJ_SUCCESS;
}

static pj_status_t pjmedia_silence_det_create(struct pj_pool_t *pool,
                                            int clock_rate,
                                            int samples_per_frame,
                                            void **vad) {
    return PJ_SUCCESS;
}

static void and_media_dealloc_codec(struct pjmedia_codec_factory *factory, 
                                  struct pjmedia_codec *codec) {}
static void create_codec(struct and_media_private_t *codec_data) {}