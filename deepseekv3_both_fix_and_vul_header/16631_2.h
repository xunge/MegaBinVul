#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#define PJMEDIA_MAX_SDP_MEDIA 32

typedef int pj_status_t;
typedef int pj_bool_t;
#define PJ_FALSE 0
#define PJ_TRUE 1

typedef struct pj_pool_t {
    void* dummy;
} pj_pool_t;

typedef struct pj_str_t {
    char* ptr;
    size_t slen;
} pj_str_t;

typedef struct pjmedia_sdp_origin {
    pj_str_t user;
    pj_str_t id;
    pj_str_t net_type;
    pj_str_t addr_type;
    pj_str_t addr;
    int version;
} pjmedia_sdp_origin;

typedef struct pjmedia_sdp_media_desc {
    pj_str_t media;
} pjmedia_sdp_media_desc;

typedef struct pjmedia_sdp_media {
    pjmedia_sdp_media_desc desc;
} pjmedia_sdp_media;

typedef struct pjmedia_sdp_session {
    pjmedia_sdp_origin origin;
    pjmedia_sdp_media** media;
    unsigned media_count;
} pjmedia_sdp_session;

typedef struct pjmedia_sdp_neg {
    int state;
    pjmedia_sdp_session* active_local_sdp;
    pjmedia_sdp_session* initial_sdp;
    pjmedia_sdp_session* initial_sdp_tmp;
    pjmedia_sdp_session* neg_local_sdp;
} pjmedia_sdp_neg;

#define PJ_EINVAL (-1)
#define PJ_SUCCESS 0
#define PJMEDIA_SDPNEG_EINSTATE (-2)

#define PJMEDIA_SDP_NEG_STATE_DONE 0
#define PJMEDIA_SDP_NEG_STATE_LOCAL_OFFER 1
#define PJMEDIA_SDP_NEG_ALLOW_MEDIA_CHANGE 0x01

#define PJ_ASSERT_RETURN(expr, ret) if (!(expr)) return (ret)

static inline void pj_bzero(void *dst, size_t len) {
    memset(dst, 0, len);
}

static inline void pj_strdup(pj_pool_t *pool, pj_str_t *dst, const pj_str_t *src) {
    (void)pool;
    *dst = *src;
}

static inline int pj_strcmp(const pj_str_t *s1, const pj_str_t *s2) {
    if (s1->slen != s2->slen) return s1->slen - s2->slen;
    return memcmp(s1->ptr, s2->ptr, s1->slen);
}

static inline void pj_array_insert(void *arr, size_t elmt_size, 
                                 unsigned count, unsigned pos, void *new_elmt) {
    memmove((char*)arr + (pos+1)*elmt_size, 
           (char*)arr + pos*elmt_size, 
           (count - pos) * elmt_size);
    memcpy((char*)arr + pos*elmt_size, new_elmt, elmt_size);
}

static pjmedia_sdp_session* pjmedia_sdp_session_clone(pj_pool_t *pool, const pjmedia_sdp_session *src) {
    (void)pool;
    return (pjmedia_sdp_session*)src;
}

static pjmedia_sdp_media* sdp_media_clone_deactivate(pj_pool_t *pool, const pjmedia_sdp_media *src, 
                                                    const pjmedia_sdp_media *base, const pjmedia_sdp_session *local) {
    (void)pool; (void)base; (void)local;
    return (pjmedia_sdp_media*)src;
}

static pj_status_t pjmedia_sdp_validate(const pjmedia_sdp_session *sdp) {
    (void)sdp;
    return PJ_SUCCESS;
}

static pj_status_t pjmedia_sdp_session_cmp(const pjmedia_sdp_session *s1, 
                                          const pjmedia_sdp_session *s2, int flags) {
    (void)s1; (void)s2; (void)flags;
    return PJ_SUCCESS;
}

#define PJ_DEF(type) type