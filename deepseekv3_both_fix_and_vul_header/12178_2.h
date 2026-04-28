#include <stddef.h>
#include <stdint.h>
#include <string.h>

#define VFS 0
#define EIO 5
#define ENOENT 2
#define CifsExiting 0
#define CIFSMaxBufSize 65536
#define MAX_CIFS_HDR_SIZE 128
#define MID_REQUEST_SUBMITTED 1
#define MID_RESPONSE_RECEIVED 2
#define MID_RESPONSE_READY 3

struct smb_hdr {
    uint32_t smb_buf_length;
};

struct cifs_ses {
    struct TCP_Server_Info *server;
};

struct TCP_Server_Info {
    int srv_lock;
    int mid_lock;
    int tcpStatus;
    unsigned int sequence_number;
};

struct mid_q_entry {
    int mid_state;
    unsigned int sequence_number;
    void *resp_buf;
    void (*callback)(struct mid_q_entry *mid);
};

struct kvec {
    void *iov_base;
    size_t iov_len;
};

struct smb_rqst {
    struct kvec *rq_iov;
    int rq_nvec;
};

struct cifs_credits {
    int value;
    int instance;
};

static inline void spin_lock(int *lock) { *lock = 1; }
static inline void spin_unlock(int *lock) { *lock = 0; }

static inline uint32_t be32_to_cpu(uint32_t x) { return x; }

void cifs_dbg(int level, const char *fmt, ...);
void cifs_server_dbg(int level, const char *fmt, ...);
int wait_for_free_request(struct TCP_Server_Info *server, int flags, int *instance);
void add_credits(struct TCP_Server_Info *server, struct cifs_credits *credits, int flags);
void cifs_server_lock(struct TCP_Server_Info *server);
int allocate_mid(struct cifs_ses *ses, struct smb_hdr *in_buf, struct mid_q_entry **midQ);
int cifs_sign_smb(struct smb_hdr *in_buf, struct TCP_Server_Info *server, unsigned int *sequence_number);
void cifs_server_unlock(struct TCP_Server_Info *server);
int smb_send(struct TCP_Server_Info *server, struct smb_hdr *in_buf, unsigned int len);
void cifs_save_when_sent(struct mid_q_entry *midQ);
int wait_for_response(struct TCP_Server_Info *server, struct mid_q_entry *midQ);
void send_cancel(struct TCP_Server_Info *server, struct smb_rqst *rqst, struct mid_q_entry *midQ);
int cifs_sync_mid_result(struct mid_q_entry *midQ, struct TCP_Server_Info *server);
int get_rfc1002_length(void *buf);
int cifs_check_receive(struct mid_q_entry *midQ, struct TCP_Server_Info *server, int flags);
void delete_mid(struct mid_q_entry *midQ);
void release_mid(struct mid_q_entry *midQ);