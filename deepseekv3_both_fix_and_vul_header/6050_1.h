#include <stddef.h>
#include <assert.h>
#include <pthread.h>
#include <string.h>
#include <sys/types.h>

enum vfp_status {
    VFP_OK,
    VFP_ERROR,
    VFP_END
};

#define v_matchproto_(x) 
#define CHECK_OBJ_NOTNULL(x, y) 
#define CAST_OBJ_NOTNULL(x, y, z) 
#define AN(x) 
#define AZ(x) 

struct vfp_ctx {
    unsigned magic;
    struct worker *wrk;
};
#define VFP_CTX_MAGIC 0

struct vfp_entry {
    void *priv1;
    unsigned magic;
};
#define VFP_ENTRY_MAGIC 0

struct worker {
    pthread_cond_t cond;
};

struct h2_req {
    unsigned magic;
    struct h2_sess *h2sess;
    int state;
    pthread_cond_t *cond;
    int error;
};
#define H2_REQ_MAGIC 0

struct h2_sess {
    struct sess *sess;
    pthread_cond_t *cond;
    unsigned mailcall;
    unsigned error;
    unsigned char *rxf_data;
    size_t rxf_len;
    unsigned rxf_flags;
};

struct sess {
    pthread_mutex_t mtx;
};

#define H2_S_OPEN 0
#define H2_S_CLOS_REM 0
#define H2FF_DATA_END_STREAM 0

typedef enum vfp_status (*vfp_pull_f)(struct vfp_ctx *, struct vfp_entry *, void *, ssize_t *);

void Lck_Lock(pthread_mutex_t *);
void Lck_Unlock(pthread_mutex_t *);
int Lck_CondWait(pthread_cond_t *, pthread_mutex_t *, int);