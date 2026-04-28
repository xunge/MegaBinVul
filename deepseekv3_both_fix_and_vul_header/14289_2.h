#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

struct ksmbd_work {
    void *request_buf;
    void *response_buf;
    struct ksmbd_conn *conn;
    struct ksmbd_session *sess;
};

struct smb2_sess_setup_req {
    uint64_t PreviousSessionId;
    uint16_t SecurityBufferLength;
    uint16_t SecurityMode;
    uint32_t Flags;
};

struct smb2_sess_setup_rsp {
    struct {
        char ProtocolId[4];
    } hdr;
    uint16_t SecurityBufferOffset;
    uint16_t SecurityBufferLength;
    uint16_t SessionFlags;
};

struct ksmbd_conn {
    bool use_spnego;
    bool sign;
    bool binding;
    unsigned int dialect;
    struct {
        uint32_t capabilities;
    } *vals;
    struct {
        int (*generate_encryptionkey)(struct ksmbd_session *);
        int (*generate_signingkey)(struct ksmbd_session *, struct ksmbd_conn *);
    } *ops;
};

struct ksmbd_session {
    uint64_t id;
    int state;
    struct ksmbd_user *user;
    bool sign;
    bool enc;
    struct list_head ksmbd_chann_list;
};

struct channel {
    struct ksmbd_conn *conn;
    struct list_head chann_list;
};

struct ksmbd_user {
    uint64_t id;
};

struct authenticate_message {
    char data[1];
};

#define SMB2_SESSION_FLAG_IS_GUEST_LE 0
#define SMB2_SESSION_FLAG_ENCRYPT_DATA_LE 0
#define SMB2_NEGOTIATE_SIGNING_REQUIRED 0
#define SMB2_SESSION_REQ_FLAG_BINDING 0
#define SMB30_PROT_ID 0
#define SMB20_PROT_ID 0
#define SMB2_SESSION_VALID 0
#define GFP_KERNEL 0
#define ENOMEM 0
#define EPERM 0
#define EINVAL 0
#define ENOENT 0
#define KSMBD_USER_FLAG_BAD_PASSWORD 0
#define SMB2_GLOBAL_CAP_ENCRYPTION 0

#define le16_to_cpu(x) (x)
#define le64_to_cpu(x) (x)
#define cpu_to_le16(x) (x)

enum {
    SMB,
};

struct server_conf {
    bool enforced_signing;
};

extern struct server_conf server_conf;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint64_t u64;

static inline void INIT_LIST_HEAD(struct list_head *list) {
    list->next = list;
    list->prev = list;
}

static inline void list_add(struct list_head *new, struct list_head *head) {
    new->next = head->next;
    new->prev = head;
    head->next->prev = new;
    head->next = new;
}

static inline void ksmbd_debug(int type, const char *fmt, ...) {}
static inline int build_spnego_ntlmssp_auth_blob(unsigned char **blob, u16 *len, int flag) { return 0; }
static inline void kfree(void *ptr) {}
static inline void inc_rfc1001_len(void *rsp, int len) {}
static inline struct ksmbd_user *session_user(struct ksmbd_conn *conn, struct smb2_sess_setup_req *req) { return NULL; }
static inline void destroy_previous_session(struct ksmbd_user *user, u64 prev_id) {}
static inline int ksmbd_anonymous_user(struct ksmbd_user *user) { return 0; }
static inline int ksmbd_compare_user(struct ksmbd_user *u1, struct ksmbd_user *u2) { return 0; }
static inline void ksmbd_free_user(struct ksmbd_user *user) {}
static inline int user_guest(struct ksmbd_user *user) { return 0; }
static inline struct authenticate_message *user_authblob(struct ksmbd_conn *conn, struct smb2_sess_setup_req *req) { return NULL; }
static inline int ksmbd_decode_ntlmssp_auth_blob(struct authenticate_message *authblob, int sz, struct ksmbd_conn *conn, struct ksmbd_session *sess) { return 0; }
static inline void set_user_flag(struct ksmbd_user *user, int flag) {}
static inline struct channel *lookup_chann_list(struct ksmbd_session *sess, struct ksmbd_conn *conn) { return NULL; }
static inline void *kmalloc(size_t size, int flags) { return NULL; }
static inline int ksmbd_conn_lookup_dialect(struct ksmbd_conn *conn) { return 0; }
static inline void pr_err(const char *fmt, ...) {}