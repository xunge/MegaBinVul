#include <stddef.h>

#define PJ_DEF(x) x
#define PJ_ASSERT_RETURN(expr, retval) if (!(expr)) return (retval)
#define PJ_EINVAL 1
#define PJ_SUCCESS 0
#define PJ_PERROR(level, args)
#define PJ_LOG(level, args)

typedef int pj_status_t;

typedef struct {
    unsigned max_slot_cnt;
} vid_conf_opt;

typedef struct {
    void *mutex;
    vid_conf_opt opt;
    unsigned connect_cnt;
    void *clock;
    void **ports;
} pjmedia_vid_conf;

typedef struct {
    size_t slen;
    char *ptr;
} pj_str_t;

typedef struct vconf_port {
    unsigned listener_cnt;
    unsigned transmitter_cnt;
    unsigned *listener_slots;
    unsigned *transmitter_slots;
    pj_str_t name;
} vconf_port;

#define AUTO_STOP_CLOCK 1
#define THIS_FILE "vid_conf.c"

static void pj_mutex_lock(void *mutex) {}
static void pj_mutex_unlock(void *mutex) {}
static void cleanup_render_state(vconf_port *port, unsigned k) {}
static void update_render_state(pjmedia_vid_conf *vid_conf, vconf_port *port) {}
static void pj_array_erase(void *array, size_t elem_size, unsigned count, unsigned pos) {}
static void pj_assert(int expr) {}
static int pjmedia_clock_stop(void *clock) { return 0; }