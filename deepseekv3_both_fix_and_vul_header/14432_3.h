#include <stdlib.h>
#include <string.h>
#include <strings.h>

typedef int pj_status_t;
typedef unsigned pj_bool_t;
typedef unsigned pj_uint32_t;

#define PJ_EINVAL 1
#define PJ_ENOMEM 2
#define PJ_SUCCESS 0
#define PJMEDIA_CODEC_EFAILED -1

typedef struct pj_str_t {
    char *ptr;
    pj_uint32_t slen;
} pj_str_t;

typedef struct pj_pool_t pj_pool_t;
typedef struct pj_mutex_t pj_mutex_t;

typedef struct pjmedia_codec_info {
    pj_str_t encoding_name;
    unsigned clock_rate;
    unsigned channel_cnt;
} pjmedia_codec_info;

typedef struct pjmedia_codec_op pjmedia_codec_op;

typedef struct pjmedia_codec {
    const pjmedia_codec_op *op;
    void *factory;
    void *codec_data;
} pjmedia_codec;

typedef struct pjmedia_codec_factory {
    void *base;
    pj_mutex_t *mutex;
    void *endpt;
} pjmedia_codec_factory;

typedef struct ipp_private_t {
    pj_pool_t *pool;
    int codec_idx;
    void *plc;
    void *vad;
} ipp_private_t;

struct ipp_codec_info {
    const char *name;
    int clock_rate;
    int channel_count;
    int samples_per_frame;
    pj_bool_t enabled;
    pj_bool_t has_native_plc;
    pj_bool_t has_native_vad;
};

extern pjmedia_codec_factory ipp_factory;
extern struct ipp_codec_info ipp_codec[1];  // 使用固定大小数组声明
extern pjmedia_codec_op ipp_op;

#define PJ_POOL_ZALLOC_T(pool, type) ((type*)calloc(1, sizeof(type)))
#define PJ_ASSERT_RETURN(expr, retval) do { if (!(expr)) return (retval); } while(0)
#define PJ_ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

static pj_pool_t* pjmedia_endpt_create_pool(void* endpt, const char* name, int size, int increment);
static void pj_pool_release(pj_pool_t* pool);
static void pj_mutex_lock(pj_mutex_t* mutex);
static void pj_mutex_unlock(pj_mutex_t* mutex);
static pj_status_t pjmedia_plc_create(pj_pool_t* pool, int clock_rate, int samples, int options, void** plc);
static pj_status_t pjmedia_silence_det_create(pj_pool_t* pool, int clock_rate, int samples, void** vad);
static pj_str_t pj_str(char *s);
static int pj_stricmp(const pj_str_t *s1, const pj_str_t *s2);