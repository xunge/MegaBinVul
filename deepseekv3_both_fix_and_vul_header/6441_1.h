#include <stdint.h>
#include <assert.h>
#include <sys/types.h>
#include <stddef.h>
#include <string.h>

enum fetch_step {
    F_STP_FAIL,
    F_STP_RETRY,
    F_STP_DONE
};

struct worker {
    struct {
        int fetch_failed;
    } *stats;
    int handling;
};

struct busyobj {
    struct objcore *fetch_objcore;
    struct http *beresp;
    struct http *bereq;
    void *ws;
    void *vsl;
    void *vcl;
    struct vfp_ctx *vfc;
    struct worker *wrk;
    int retries;
    int director_state;
};

struct objcore {
    unsigned int flags;
    struct stobj *stobj;
    struct objhead *objhead;
    double t_origin;
    int ttl;
    int grace;
    int keep;
};

struct stobj {
    void *stevedore;
};

struct objhead {
    struct {
        int dummy;
    } waitinglist;
};

struct vfp_ctx {
    struct busyobj *bo;
    struct worker *wrk;
    struct objcore *oc;
    struct http *http;
    struct http *esi_req;
};

struct http;
struct vsb;

#define CHECK_OBJ_NOTNULL(obj, magic)
#define AN(expr)
#define AZ(expr)
#define SLT_BerespMethod 0
#define SLT_VCL_Error 0
#define WORKER_MAGIC 0
#define BUSYOBJ_MAGIC 0
#define OBJCORE_MAGIC 0
#define OC_F_BUSY 0
#define DIR_S_NULL 0
#define VCL_RET_ABANDON 0
#define VCL_RET_FAIL 0
#define VCL_RET_RETRY 0
#define VCL_RET_DELIVER 0
#define BOS_FINISHED 0
#define VFP_OK 0
#define OA_LEN 0

#define VTAILQ_EMPTY(head) (1)

void VSLb_ts_busyobj(struct busyobj *bo, const char *tag, double now);
void VSLb(void *vsl, int tag, const char *fmt, ...);
void HTTP_Setup(struct http *h, void *ws, void *vsl, int tag);
void http_PutResponse(struct http *h, const char *proto, int status, const char *reason);
void http_TimeHeader(struct http *h, const char *header, double now);
void http_SetHeader(struct http *h, const char *header);
void ObjFreeObj(struct worker *w, struct objcore *oc);
struct vsb *VSB_new_auto(void);
int VSB_finish(struct vsb *vsb);
void VSB_destroy(struct vsb **vsb);
size_t VSB_len(const struct vsb *vsb);
const char *VSB_data(const struct vsb *vsb);
void VCL_backend_error_method(void *vcl, struct worker *wrk, void *priv, struct busyobj *bo, struct vsb *synth_body);
int vbf_beresp2obj(struct busyobj *bo);
void HSH_Unbusy(struct worker *w, struct objcore *oc);
void ObjSetState(struct worker *w, struct objcore *oc, int state);
int ObjSetU64(struct worker *w, struct objcore *oc, int attr, uint64_t val);
double W_TIM_real(struct worker *w);
int VFP_Error(struct vfp_ctx *vfc, const char *msg);
int VFP_GetStorage(struct vfp_ctx *vfc, ssize_t *len, uint8_t **ptr);
void VFP_Extend(struct vfp_ctx *vfc, ssize_t len);

struct cache_param {
    int max_retries;
};
extern struct cache_param *cache_param;