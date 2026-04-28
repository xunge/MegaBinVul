#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <stdarg.h>

typedef uint16_t __u16;
typedef uint32_t __u32;
typedef uint64_t __u64;
typedef uint8_t __u8;

#define __user

struct cifsTconInfo {
    struct cifsSesInfo *ses;
    unsigned int num_writes;
};

struct cifsSesInfo {
    unsigned int capabilities;
    struct TCP_Server_Info *server;
};

struct TCP_Server_Info {
    unsigned int maxBuf;
};

struct smb_hdr {
    unsigned int smb_buf_length;
};

struct smb_com_write_req {
    __u8 AndXCommand;
    __u16 Fid;
    __u32 OffsetLow;
    __u32 OffsetHigh;
    __u32 Reserved;
    __u16 WriteMode;
    __u16 Remaining;
    __u16 DataOffset;
    __u8 Data[0];
    __u16 DataLengthLow;
    __u16 DataLengthHigh;
    __u16 ByteCount;
    struct smb_hdr hdr;
    __u16 Count;
    __u16 CountHigh;
};

struct smb_com_writex_req {
    __u16 ByteCount;
};

typedef struct smb_com_write_req WRITE_REQ;
typedef struct smb_com_write_req WRITE_RSP;

#define CAP_LARGE_FILES 0x1
#define CAP_LARGE_WRITE_X 0x2
#define CIFSMaxBufSize 65536
#define MAX_CIFS_HDR_SIZE 256

#define EACCES 13
#define ECONNABORTED 103
#define EIO 5
#define EFAULT 14
#define EINVAL 22
#define EAGAIN 11

#define SMB_COM_WRITE_ANDX 0x2F

#define min_t(type, x, y) ({ type __x = (x); type __y = (y); __x < __y ? __x : __y; })

static inline __u16 cpu_to_le16(__u16 val) { return val; }
static inline __u32 cpu_to_le32(__u32 val) { return val; }
static inline __u16 le16_to_cpu(__u16 val) { return val; }

extern int smb_init(int, int, struct cifsTconInfo *, void **, void **);
extern int SendReceive(int, struct cifsSesInfo *, struct smb_hdr *, struct smb_hdr *, int *, int);
extern void cifs_buf_release(void *);
extern void cifs_stats_inc(unsigned int *);
extern void cFYI(int, const char *, ...);

static inline int copy_from_user(void *to, const void *from, unsigned long n)
{
    memcpy(to, from, n);
    return 0;
}