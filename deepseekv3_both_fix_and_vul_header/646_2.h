#include <stdbool.h>
#include <string.h>
#include <stdint.h>

struct cifs_ses {
    unsigned int Suid;
};

struct cifs_tcon {
    struct cifs_ses *ses;
    unsigned int tid;
};

struct cifs_io_parms {
    struct cifs_tcon *tcon;
    unsigned int offset;
    unsigned int length;
};

struct kvec {
    void *iov_base;
    size_t iov_len;
};

struct smb_rqst {
    struct kvec *rq_iov;
    unsigned int rq_nvec;
};

struct smb2_read_plain_req {
    unsigned int PersistentFileId;
};

struct smb2_read_rsp {
    uint32_t DataLength;
    uint32_t DataOffset;
};

#define CIFS_LOG_ERROR 0
#define CIFS_TRANSFORM_REQ 0
#define CIFS_MAX_MSGSIZE 65536
#define CIFS_NO_BUFFER 0
#define CIFS_SMALL_BUFFER 1
#define CIFS_LARGE_BUFFER 2
#define SMB2_READ_HE 0
#define VFS 0
#define FYI 0

#define EACCES 13
#define ENODATA 61
#define EIO 5

static inline uint32_t le32_to_cpu(uint32_t x) {
    return x;
}

int smb2_new_read_req(void **req, unsigned int *total_len, struct cifs_io_parms *io_parms, void *arg, int arg1, int arg2);
bool smb3_encryption_required(struct cifs_tcon *tcon);
int cifs_send_recv(unsigned int xid, struct cifs_ses *ses, struct smb_rqst *rqst, int *resp_buftype, int flags, struct kvec *rsp_iov);
void cifs_small_buf_release(void *req);
void cifs_stats_fail_inc(struct cifs_tcon *tcon, int type);
void cifs_dbg(int level, const char *fmt, ...);
void trace_smb3_read_err(unsigned int xid, unsigned int fid, unsigned int tid, unsigned int suid, unsigned long offset, unsigned int length, int rc);
void trace_smb3_read_done(unsigned int xid, unsigned int fid, unsigned int tid, unsigned int suid, unsigned long offset, unsigned int length);
void free_rsp_buf(int type, void *buf);