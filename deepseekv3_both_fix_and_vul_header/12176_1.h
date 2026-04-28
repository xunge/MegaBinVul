#include <stddef.h>
#include <string.h>

struct smb_hdr {
    unsigned int smb_buf_length;
    unsigned char Command;
};

struct cifs_tcon {
    struct cifs_ses *ses;
};

struct cifs_ses {
    struct TCP_Server_Info *server;
};

struct TCP_Server_Info {
    int srv_lock;
    int mid_lock;
    unsigned int tcpStatus;
    unsigned int sequence_number;
    int response_q;
};

struct mid_q_entry {
    unsigned int mid_state;
    unsigned int sequence_number;
    void (*callback)(struct mid_q_entry *mid);
    unsigned char *resp_buf;
};

struct kvec {
    void *iov_base;
    size_t iov_len;
};

struct smb_rqst {
    struct kvec *rq_iov;
    int rq_nvec;
};

#define CifsExiting 0
#define CifsGood 1
#define CifsNew 2
#define MID_REQUEST_SUBMITTED 0
#define MID_RESPONSE_RECEIVED 1
#define MID_RESPONSE_READY 2
#define CIFS_BLOCKING_OP 0
#define CIFSMaxBufSize 0
#define MAX_CIFS_HDR_SIZE 0
#define SMB_COM_TRANSACTION2 0
#define VFS 0
#define EIO 5
#define ENOENT 2
#define ERESTARTSYS 512
#define ENOLCK 37
#define EACCES 13

static inline unsigned int be32_to_cpu(unsigned int x) { return x; }
static inline void spin_lock(int *lock) { (void)lock; }
static inline void spin_unlock(int *lock) { (void)lock; }

void cifs_dbg(int level, const char *fmt, ...);
void cifs_tcon_dbg(int level, const char *fmt, ...);
int wait_for_free_request(struct TCP_Server_Info *server, int flags, unsigned int *instance);
void cifs_server_lock(struct TCP_Server_Info *server);
void cifs_server_unlock(struct TCP_Server_Info *server);
int allocate_mid(struct cifs_ses *ses, struct smb_hdr *in_buf, struct mid_q_entry **midQ);
int cifs_sign_smb(struct smb_hdr *in_buf, struct TCP_Server_Info *server, unsigned int *sequence_number);
void delete_mid(struct mid_q_entry *midQ);
int smb_send(struct TCP_Server_Info *server, struct smb_hdr *in_buf, unsigned int len);
void cifs_save_when_sent(struct mid_q_entry *midQ);
int send_cancel(struct TCP_Server_Info *server, struct smb_rqst *rqst, struct mid_q_entry *midQ);
int send_lock_cancel(unsigned int xid, struct cifs_tcon *tcon, struct smb_hdr *in_buf, struct smb_hdr *out_buf);
int wait_for_response(struct TCP_Server_Info *server, struct mid_q_entry *midQ);
void release_mid(struct mid_q_entry *mid);
int cifs_sync_mid_result(struct mid_q_entry *midQ, struct TCP_Server_Info *server);
int get_rfc1002_length(unsigned char *buf);
int cifs_check_receive(struct mid_q_entry *midQ, struct TCP_Server_Info *server, int flags);