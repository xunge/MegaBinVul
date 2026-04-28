#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define MAX_COMPOUND 5
#define CIFS_NO_BUFFER 0
#define CIFS_LARGE_BUFFER 1
#define CIFS_SMALL_BUFFER 2
#define CIFS_OP_MASK 0xFF
#define CIFS_NO_SRV_RSP 0x100
#define CIFS_LOG_ERROR 0x200
#define CIFS_NO_RSP_BUF 0x400
#define CIFS_NEG_OP 0x800
#define CIFS_SESS_OP 0x1000
#define EIO 5
#define ENOENT 2
#define EAGAIN 11
#define VFS 1
#define FYI 2
#define SES_NEW 0

struct smb_rqst {
    struct kvec *rq_iov;
    int rq_nvec;
};

struct kvec {
    void *iov_base;
    size_t iov_len;
};

struct mid_q_entry {
    unsigned long mid;
    int mid_state;
    #define MID_REQUEST_SUBMITTED 0
    #define MID_RESPONSE_RECEIVED 1
    #define MID_RESPONSE_READY 2
    int optype;
    void (*callback)(struct mid_q_entry *);
    void *resp_buf;
    int resp_buf_size;
    int large_buf;
    unsigned int mid_flags;
    #define MID_WAIT_CANCELLED 1
    unsigned short command;
};

struct cifs_credits {
    unsigned int value;
    unsigned int instance;
};

struct cifs_server_ops {
    struct mid_q_entry * (*setup_request)(struct cifs_ses *, struct TCP_Server_Info *, struct smb_rqst *);
    int (*check_receive)(struct mid_q_entry *, struct TCP_Server_Info *, int);
};

struct TCP_Server_Info {
    int srv_lock;
    unsigned int tcpStatus;
    #define CifsExiting 1
    unsigned int reconnect_instance;
    int mid_lock;
    unsigned int sequence_number;
    struct cifs_server_ops *ops;
};

struct cifs_ses {
    struct TCP_Server_Info *server;
    unsigned int ses_status;
    int ses_lock;
};

#define HEADER_PREAMBLE_SIZE(x) 4

static inline void spin_lock(int *lock) {}
static inline void spin_unlock(int *lock) {}

static inline int IS_ERR(const void *ptr) { return (uintptr_t)ptr > (uintptr_t)-4096UL; }
static inline int PTR_ERR(const void *ptr) { return (int)(uintptr_t)ptr; }
static inline uint16_t le16_to_cpu(uint16_t x) { return x; }

extern int wait_for_compound_request(struct TCP_Server_Info *, int, int, unsigned int *);
extern void add_credits(struct TCP_Server_Info *, struct cifs_credits *, int);
extern void revert_current_mid(struct TCP_Server_Info *, int);
extern void delete_mid(struct mid_q_entry *);
extern int smb_send_rqst(struct TCP_Server_Info *, int, struct smb_rqst *, int);
extern void cifs_save_when_sent(struct mid_q_entry *);
extern int wait_for_response(struct TCP_Server_Info *, struct mid_q_entry *);
extern void send_cancel(struct TCP_Server_Info *, struct smb_rqst *, struct mid_q_entry *);
extern int cifs_sync_mid_result(struct mid_q_entry *, struct TCP_Server_Info *);
extern void cifs_server_lock(struct TCP_Server_Info *);
extern void cifs_server_unlock(struct TCP_Server_Info *);
extern void smb311_update_preauth_hash(struct cifs_ses *, struct TCP_Server_Info *, struct kvec *, int);
extern void cifs_compound_callback(struct mid_q_entry *);
extern void cifs_compound_last_callback(struct mid_q_entry *);
extern void cifs_cancelled_callback(struct mid_q_entry *);
extern void cifs_dbg(int level, const char *fmt, ...);
extern void cifs_server_dbg(int level, const char *fmt, ...);