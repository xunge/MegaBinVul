#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef int pj_status_t;
typedef unsigned int pj_uint32_t;

typedef struct pj_str_t {
    char *ptr;
    unsigned int slen;
} pj_str_t;

typedef struct pj_pool_t {
    void *factory;
} pj_pool_t;

typedef struct pjmedia_ratio {
    int num;
    int denum;
} pjmedia_ratio;

typedef struct pjmedia_video_size {
    int width;
    int height;
} pjmedia_video_size;

typedef struct pjmedia_video_format_detail {
    pjmedia_video_size size;
    pjmedia_ratio fps;
} pjmedia_video_format_detail;

typedef struct pjmedia_format {
    int type;
    int detail_type;
    int id;
    union {
        pjmedia_video_format_detail vid;
    } det;
} pjmedia_format;

typedef struct pjmedia_port {
    struct {
        pjmedia_format fmt;
        pj_str_t name;
    } info;
    int (*put_frame)(struct pjmedia_port*, void*);
    int (*get_frame)(struct pjmedia_port*, void*);
} pjmedia_port;

typedef struct pjmedia_video_format_info {
    int (*apply_fmt)(const struct pjmedia_video_format_info*, void*);
} pjmedia_video_format_info;

typedef struct pjmedia_video_apply_fmt_param {
    pjmedia_video_size size;
    unsigned framebytes;
} pjmedia_video_apply_fmt_param;

typedef struct pjmedia_vid_conf {
    void *mutex;
    unsigned int port_cnt;
    struct {
        unsigned int max_slot_cnt;
        unsigned int frame_rate;
    } opt;
    struct vconf_port **ports;
} pjmedia_vid_conf;

typedef struct vconf_port {
    pj_pool_t *pool;
    pjmedia_port *port;
    pjmedia_format format;
    unsigned idx;
    pj_str_t name;
    pj_uint32_t ts_interval;
    unsigned put_buf_size;
    void *put_buf;
    unsigned get_buf_size;
    void *get_buf;
    unsigned *listener_slots;
    unsigned *transmitter_slots;
    struct render_state **render_states;
    pj_pool_t **render_pool;
} vconf_port;

typedef struct render_state {
    int dummy;
} render_state;

#define PJ_EINVAL 1
#define PJ_ENOMEM 2
#define PJ_ETOOMANY 3
#define PJ_SUCCESS 0
#define PJMEDIA_EBADFMT 4
#define PJMEDIA_TYPE_VIDEO 1
#define PJMEDIA_FORMAT_DETAIL_VIDEO 1
#define TS_CLOCK_RATE 90000
#define THIS_FILE "vid_conf.c"

#define PJ_DEF(ret_type) ret_type
#define PJ_ASSERT_RETURN(expr, ret) if (!(expr)) return (ret)
#define PJ_UNUSED_ARG(arg) (void)(arg)
#define PJ_LOG(level, args) printf args
#define pj_mutex_lock(mtx) 
#define pj_mutex_unlock(mtx) 
#define pj_pool_create(factory, name, size1, size2, cb) malloc(1)
#define PJ_POOL_ZALLOC_T(pool, type) calloc(1, sizeof(type))
#define pj_strdup_with_null(pool, dst, src) { \
    (dst)->ptr = strdup((src)->ptr); \
    (dst)->slen = (src)->slen; \
}
#define pj_pool_zalloc(pool, size) calloc(1, size)
#define pj_bzero(ptr, size) memset(ptr, 0, size)
#define pj_assert(expr) assert(expr)

static const pjmedia_video_format_info* pjmedia_get_video_format_info(void* a, int b) {
    static pjmedia_video_format_info vfi;
    return &vfi;
}