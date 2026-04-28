#include <stddef.h>

typedef int pj_status_t;
typedef struct pjmedia_vid_conf pjmedia_vid_conf;
typedef struct pj_str_t {
    int slen;
    char *ptr;
} pj_str_t;
typedef struct pj_pool_t pj_pool_t;
typedef struct pj_clock_t pj_clock_t;
typedef struct pj_mutex_t pj_mutex_t;

struct pjmedia_vid_conf {
    struct {
        unsigned max_slot_cnt;
    } opt;
    pj_mutex_t *mutex;
    void **ports;
    unsigned port_cnt;
    unsigned connect_cnt;
    pj_clock_t *clock;
};

typedef struct vconf_port {
    pj_str_t name;
    unsigned listener_cnt;
    unsigned *listener_slots;
    unsigned transmitter_cnt;
    unsigned *transmitter_slots;
    pj_pool_t *pool;
} vconf_port;

#define PJ_DEF(x) x
#define PJ_EINVAL 22
#define PJ_SUCCESS 0
#define PJ_LOG(level, args)
#define PJ_PERROR(level, args)
#define THIS_FILE "vid_conf.c"
#define AUTO_STOP_CLOCK 1

void pj_mutex_lock(pj_mutex_t*);
void pj_mutex_unlock(pj_mutex_t*);
void pj_pool_safe_release(pj_pool_t**);
pj_status_t pjmedia_clock_stop(pj_clock_t*);
pj_status_t pjmedia_vid_conf_disconnect_port(pjmedia_vid_conf*, unsigned, unsigned);