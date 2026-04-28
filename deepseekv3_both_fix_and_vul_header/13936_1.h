#include <stdint.h>
#include <inttypes.h>
#include <sys/types.h>
#include <stddef.h>

enum vfp_status {
    VFP_OK,
    VFP_END,
    VFP_ERROR
};

struct vfp_ctx {
    int magic;
};

struct vfp_entry {
    void *priv1;
    ssize_t priv2;
    int magic;
};

struct http_conn {
    int magic;
};

#define VFP_CTX_MAGIC 0
#define VFP_ENTRY_MAGIC 0
#define HTTP_CONN_MAGIC 0

#define CHECK_OBJ_NOTNULL(obj, magic) 
#define CAST_OBJ_NOTNULL(var, obj, magic) (var = (typeof(var))(obj))
#define AN(expr) 
#define AZ(expr) 

typedef int vfp_pull_f;
#define __match_proto__(x)

static ssize_t v1f_read(struct vfp_ctx *vc, struct http_conn *htc, char *buf, size_t len);
static int vct_islws(char c);
static int vct_ishex(char c);
static enum vfp_status VFP_Error(struct vfp_ctx *vc, const char *msg);