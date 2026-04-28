#include <sys/uio.h>
#include <errno.h>
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>

struct vrend_transfer_info {
    void *box;
    int ctx_id;
    int handle;
    struct iovec *iovec;
    int iovec_cnt;
    bool context0;
};

struct vrend_resource {
    struct iovec *iov;
    int num_iovs;
    void *gbm_bo;
    int id;
};

struct vrend_context;

#define VIRGL_ERROR_CTX_ILLEGAL_RESOURCE 0
#define VIRGL_ERROR_CTX_TRANSFER_IOV_BOUNDS 0
#define VIRGL_TRANSFER_TO_HOST 0
#define VIRGL_TRANSFER_FROM_HOST 1

void report_context_error(struct vrend_context *ctx, int error, int handle);
struct vrend_context *vrend_lookup_renderer_ctx(int ctx_id);
struct vrend_resource *vrend_resource_lookup(int handle, int unused);
struct vrend_resource *vrend_renderer_ctx_res_lookup(struct vrend_context *ctx, int handle);
int vrend_renderer_transfer_write_iov(struct vrend_context *ctx, struct vrend_resource *res, struct iovec *iov, int num_iovs, const struct vrend_transfer_info *info);
int vrend_renderer_transfer_send_iov(struct vrend_resource *res, struct iovec *iov, int num_iovs, const struct vrend_transfer_info *info);
void vrend_renderer_force_ctx_0(void);
bool check_transfer_bounds(struct vrend_resource *res, const struct vrend_transfer_info *info);
bool check_iov_bounds(struct vrend_resource *res, const struct vrend_transfer_info *info, struct iovec *iov, int num_iovs);