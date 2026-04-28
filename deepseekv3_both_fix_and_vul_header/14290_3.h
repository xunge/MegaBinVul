#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef uint64_t u64;

struct list_head {
    struct list_head *next, *prev;
};

struct smb2_hdr {
    uint8_t ProtocolId[4];
    uint32_t smb2_buf_length;
};

struct ksmbd_work {
    void *request_buf;
    void *response_buf;
    struct ksmbd_conn *conn;
    struct ksmbd_session *sess;
    size_t response_sz;
};

struct smb2_sess_setup_req {
    struct smb2_hdr hdr;
    uint16_t SecurityBufferOffset;
    uint16_t SecurityBufferLength;
    uint64_t PreviousSessionId;
    uint16_t SecurityMode;
};

struct smb2_sess_setup_rsp {
    struct smb2_hdr hdr;
    uint16_t SecurityBufferOffset;
    uint16_t SecurityBufferLength;
    uint32_t SessionFlags;
};

struct ksmbd_conn {
    bool sign;
    struct {
        uint32_t capabilities;
    } *vals;
    struct {
        int (*generate_encryptionkey)(struct ksmbd_session *);
        int (*generate_signingkey)(struct ksmbd_session *, struct ksmbd_conn *);
    } *ops;
    unsigned int dialect;
};

struct ksmbd_session {
    uint64_t id;
    void *user;
    int state;
    bool sign;
    bool enc;
    struct list_head ksmbd_chann_list;
};

struct channel {
    struct ksmbd_conn *conn;
    struct list_head chann_list;
};

#define INIT_LIST_HEAD(ptr) do { \
    (ptr)->next = (ptr); (ptr)->prev = (ptr); \
} while (0)

static inline void list_add(struct list_head *new, struct list_head *head)
{
    new->next = head->next;
    new->prev = head;
    head->next->prev = new;
    head->next = new;
}

#define SMB2_SESSION_VALID 0
#define SMB2_NEGOTIATE_SIGNING_REQUIRED 0
#define SMB2_GLOBAL_CAP_ENCRYPTION 0
#define SMB2_SESSION_FLAG_ENCRYPT_DATA_LE 0
#define SMB30_PROT_ID 0
#define SMB20_PROT_ID 0
#define SMB 0
#define GFP_KERNEL 0
#define ENOMEM 0
#define EINVAL 0
#define ENOENT 0

static inline uint16_t le16_to_cpu(uint16_t val) { return val; }
static inline uint64_t le64_to_cpu(uint64_t val) { return val; }
static inline uint16_t cpu_to_le16(uint16_t val) { return val; }

struct server_conf {
    bool enforced_signing;
};

extern struct server_conf server_conf;

void destroy_previous_session(void *user, uint64_t prev_sess_id);
void ksmbd_free_user(void *user);
int ksmbd_krb5_authenticate(struct ksmbd_session *sess, char *in_blob, int in_len, char *out_blob, int *out_len);
void ksmbd_debug(int type, const char *fmt, ...);
void inc_rfc1001_len(struct smb2_sess_setup_rsp *rsp, int len);
struct channel *lookup_chann_list(struct ksmbd_session *sess, struct ksmbd_conn *conn);
void *kmalloc(size_t size, int flags);
int ksmbd_conn_lookup_dialect(struct ksmbd_conn *conn);
void pr_err(const char *fmt, ...);