#include <stddef.h>
#include <stdint.h>
#include <errno.h>
#include <stdbool.h>

#define SMB2_CREATE_SD_BUFFER 0
#define SMB 0

struct ksmbd_work {
    void *conn;
    void *tcon;
};

struct smb2_create_req {
    uint32_t CreateContextsOffset;
};

struct path;

struct create_context {
    uint16_t DataOffset;
    uint32_t DataLength;
};

struct create_sd_buf_req {
    struct create_context ccontext;
    void *ntsd;
};

#define IS_ERR(x) 0
#define PTR_ERR(x) 0
#define le16_to_cpu(x) (x)
#define le32_to_cpu(x) (x)

int set_info_sec(void *conn, void *tcon, const struct path *path, void *ntsd, uint32_t length, bool flag);
void ksmbd_debug(int type, const char *fmt);
struct create_context *smb2_find_context_vals(struct smb2_create_req *req, int type, ...);