#include <stdint.h>
#include <string.h>
#include <stddef.h>

struct kvec {
    void *iov_base;
    size_t iov_len;
};

struct smb_rqst {
    struct kvec *rq_iov;
    int rq_nvec;
};

struct smb2_write_req {
    struct {
        uint32_t ProcessId;
    } sync_hdr;
    uint64_t PersistentFileId;
    uint64_t VolatileFileId;
    uint16_t WriteChannelInfoOffset;
    uint16_t WriteChannelInfoLength;
    uint32_t Channel;
    uint32_t Length;
    uint64_t Offset;
    uint16_t DataOffset;
    uint32_t RemainingBytes;
    char Buffer[1];
};

struct smb2_write_rsp {
    uint32_t DataLength;
};

struct cifs_ses {
    void *server;
    uint64_t Suid;
};

struct cifs_tcon {
    struct cifs_ses *ses;
    uint32_t tid;
};

struct cifs_io_parms {
    struct cifs_tcon *tcon;
    uint32_t pid;
    uint64_t persistent_fid;
    uint64_t volatile_fid;
    uint32_t length;
    uint64_t offset;
};

#define CIFS_TRANSFORM_REQ 0x01
#define SMB2_WRITE 0x09
#define SMB2_WRITE_HE 0x01
#define ECONNABORTED 103
#define VFS 1

uint32_t cpu_to_le32(uint32_t x);
uint64_t cpu_to_le64(uint64_t x);
uint16_t cpu_to_le16(uint16_t x);
uint32_t le32_to_cpu(uint32_t x);

int smb2_plain_req_init(int cmd, struct cifs_tcon *tcon, void **req, unsigned int *total_len);
int smb3_encryption_required(struct cifs_tcon *tcon);
int cifs_send_recv(unsigned int xid, struct cifs_ses *ses, struct smb_rqst *rqst, int *resp_buftype, int flags, struct kvec *rsp_iov);
void cifs_small_buf_release(void *buf);
void cifs_stats_fail_inc(struct cifs_tcon *tcon, int cmd);
void cifs_dbg(int level, const char *fmt, ...);
void trace_smb3_write_enter(unsigned int xid, uint64_t fid, uint32_t tid, uint64_t suid, uint64_t offset, uint32_t length);
void trace_smb3_write_err(unsigned int xid, uint64_t fid, uint32_t tid, uint64_t suid, uint64_t offset, uint32_t length, int rc);
void trace_smb3_write_done(unsigned int xid, uint64_t fid, uint32_t tid, uint64_t suid, uint64_t offset, uint32_t nbytes);
void free_rsp_buf(int type, void *buf);