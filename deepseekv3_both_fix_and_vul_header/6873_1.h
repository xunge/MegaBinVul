#include <stdint.h>
#include <stddef.h>

struct ksmbd_work {
    void *response_buf;
    void *request_buf;
    struct ksmbd_session *sess;
    struct ksmbd_tree_connect *tcon;
};

struct ksmbd_session;
struct ksmbd_tree_connect;

struct smb2_tree_disconnect_rsp {
    uint16_t StructureSize;
    struct {
        struct {
            uint32_t Status;
        } hdr;
    };
};

struct smb2_tree_disconnect_req {
    struct {
        struct {
            struct {
                uint32_t TreeId;
            } SyncId;
        } Id;
    } hdr;
};

#define SMB 0
#define STATUS_NETWORK_NAME_DELETED 0

static inline uint16_t cpu_to_le16(uint16_t x) { return x; }

void inc_rfc1001_len(void *buf, int len);
void ksmbd_debug(int type, const char *fmt, ...);
void smb2_set_err_rsp(struct ksmbd_work *work);
void ksmbd_close_tree_conn_fds(struct ksmbd_work *work);
void ksmbd_tree_conn_disconnect(struct ksmbd_session *sess, struct ksmbd_tree_connect *tcon);
void *smb2_get_msg(void *buf);