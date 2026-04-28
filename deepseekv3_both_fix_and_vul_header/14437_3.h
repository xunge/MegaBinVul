#include <stdint.h>
#include <string.h>

#define PJ_DEF(type) type
#define PJ_ASSERT_RETURN(expr, retval) if (!(expr)) return (retval)
#define PJ_UNUSED_ARG(arg) (void)(arg)
#define PJ_EINVAL (-1)
#define PJ_SUCCESS 0
#define PJ_LOG(level, args)
#define PJ_PERROR(level, args)
#define THIS_FILE __FILE__

#define PJMEDIA_COLOR_MODEL_RGB 1
#define PJMEDIA_FORMAT_I420 2
#define PJMEDIA_FORMAT_YV12 3

typedef int pj_status_t;
typedef uint8_t pj_uint8_t;

typedef struct {
    unsigned max_slot_cnt;
} vid_conf_opt;

typedef struct {
    int w;
    int h;
} pjmedia_video_size;

typedef struct {
    pjmedia_video_size size;
} pjmedia_video_format_detail;

typedef struct {
    int id;
    struct {
        pjmedia_video_format_detail vid;
    } det;
} pjmedia_format;

typedef struct {
    pjmedia_format fmt;
} port_info;

typedef struct {
    char *ptr;
    unsigned slen;
} pj_str_t;

typedef struct port_operations {
    port_info info;
    int (*get_frame)(void);
    int (*put_frame)(void);
} port_operations;

typedef struct vconf_port {
    port_operations *port;
    pj_str_t name;
    unsigned listener_cnt;
    unsigned *listener_slots;
    unsigned transmitter_cnt;
    unsigned *transmitter_slots;
    void *get_buf;
} vconf_port;

typedef struct pjmedia_vid_conf {
    vid_conf_opt opt;
    vconf_port **ports;
    void *mutex;
    unsigned connect_cnt;
    void *clock;
} pjmedia_vid_conf;

typedef struct pjmedia_video_format_info {
    int (*apply_fmt)(const struct pjmedia_video_format_info*, void*);
    int color_model;
} pjmedia_video_format_info;

typedef struct {
    int framebytes;
    int plane_bytes[3];
    pjmedia_video_size size;
} pjmedia_video_apply_fmt_param;

static void pj_mutex_lock(void *mutex) {}
static void pj_mutex_unlock(void *mutex) {}
static void pj_bzero(void *buf, unsigned size) { memset(buf, 0, size); }
static void pj_memset(void *buf, int val, unsigned size) { memset(buf, val, size); }
static pjmedia_video_format_info* pjmedia_get_video_format_info(void *pool, int fmt_id) { return NULL; }
static pj_status_t pjmedia_clock_start(void *clock) { return 0; }
static void update_render_state(pjmedia_vid_conf *vid_conf, vconf_port *port) {}