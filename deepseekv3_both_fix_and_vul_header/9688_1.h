#include <stdint.h>
#include <sys/uio.h>
#include <stddef.h>

typedef uint64_t __u64;
typedef uint8_t __u8;
typedef uint16_t __le16;
typedef uint32_t __le32;

#define EACCES 13
#define EIO 5
#define ECONNABORTED 103
#define EAGAIN 11

#define CAP_LARGE_FILES (1 << 0)
#define SMB_COM_WRITE_ANDX 0x2F
#define CIFS_SMALL_BUFFER 0
#define CIFS_LARGE_BUFFER 1

struct cifsTconInfo {
    struct cifsSesInfo *ses;
    unsigned int num_writes;
};

struct cifsSesInfo {
    unsigned long capabilities;
    struct TCP_Server_Info *server;
};

struct TCP_Server_Info {
    // dummy definition
};

struct kvec {
    void *iov_base;
    size_t iov_len;
};

struct smb_hdr {
    unsigned int smb_buf_length;
};

struct smb_com_write_req {
    struct smb_hdr hdr;
    __u8 AndXCommand;
    __u8 Reserved;
    __le16 AndXOffset;
    __le16 Fid;
    __le32 OffsetLow;
    __le32 OffsetHigh;
    __le32 Reserved2;
    __le16 WriteMode;
    __le16 Remaining;
    __le16 DataOffset;
    __le16 DataLengthLow;
    __le16 DataLengthHigh;
    __le16 ByteCount;
    __u8 Data[1];
};

struct smb_com_writex_req {
    struct smb_hdr hdr;
    __u8 AndXCommand;
    __u8 Reserved;
    __le16 AndXOffset;
    __le16 Fid;
    __le32 OffsetLow;
    __le32 Reserved2;
    __le16 WriteMode;
    __le16 Remaining;
    __le16 DataOffset;
    __le16 DataLengthLow;
    __le16 DataLengthHigh;
    __le16 ByteCount;
    __u8 Data[1];
};

struct smb_com_write_rsp {
    struct smb_hdr hdr;
    __u8 AndXCommand;
    __u8 Reserved;
    __le16 AndXOffset;
    __le16 Count;
    __le16 CountHigh;
    __le16 Reserved2;
    __le16 ByteCount;
};

typedef struct smb_com_write_req WRITE_REQ;
typedef struct smb_com_write_rsp WRITE_RSP;

static inline __le16 cpu_to_le16(uint16_t x) { return x; }
static inline __le32 cpu_to_le32(uint32_t x) { return x; }
static inline uint16_t le16_to_cpu(__le16 x) { return x; }

extern int small_smb_init(int, int, struct cifsTconInfo *, void **);
extern int SendReceive2(int, struct cifsSesInfo *, struct kvec *, int, int *, int);
extern void cifs_stats_inc(unsigned int *);
extern void cifs_small_buf_release(void *);
extern void cifs_buf_release(void *);
#define cFYI(level, args)