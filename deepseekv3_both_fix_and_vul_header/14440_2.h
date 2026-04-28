#include <stddef.h>

typedef int pj_status_t;
typedef struct pjmedia_codec_mgr pjmedia_codec_mgr;
typedef struct pjmedia_endpt pjmedia_endpt;
typedef struct pj_pool_t pj_pool_t;
typedef struct pj_mutex_t pj_mutex_t;

struct pjmedia_codec_factory {
    int dummy;  // Placeholder for incomplete type
};

#define PJ_DEF(x) x
#define PJ_SUCCESS 0
#define PJ_EBUSY (-1)
#define PJ_EINVALIDOP (-2)

struct spx_factory_t {
    pj_pool_t *pool;
    pj_mutex_t *mutex;
    pjmedia_endpt *endpt;
    struct pjmedia_codec_factory base;
    void *codec_list;
};

extern struct spx_factory_t spx_factory;

pjmedia_codec_mgr* pjmedia_endpt_get_codec_mgr(pjmedia_endpt *endpt);
void pj_mutex_lock(pj_mutex_t *mutex);
void pj_mutex_unlock(pj_mutex_t *mutex);
void pj_mutex_destroy(pj_mutex_t *mutex);
void pj_pool_release(pj_pool_t *pool);
pj_status_t pjmedia_codec_mgr_unregister_factory(pjmedia_codec_mgr *mgr, 
                                               struct pjmedia_codec_factory *factory);