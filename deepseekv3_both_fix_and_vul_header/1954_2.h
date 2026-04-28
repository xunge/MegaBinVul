#include <stdint.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>

#define PATH_MAX 4096
#define MAX_CIFS_HDR_SIZE 256
#define CIFSMaxBufSize 65536
#define SMBFLG2_UNICODE 0x8000
#define TRANS2_FIND_NEXT 0x0001
#define CIFS_SEARCH_CLOSE_AT_END 0x0001
#define CIFS_SEARCH_RETURN_RESUME 0x0002
#define SMB_COM_TRANSACTION2 0x32
#define ENOENT 2
#define EINVAL 22
#define EBADF 9
#define EAGAIN 11

typedef uint8_t __u8;
typedef uint16_t __u16;
typedef uint32_t __u32;

struct cifs_tcon {
    struct {
        struct {
            int maxBuf;
        } *server;
    } *ses;
    int num_fnext;
};

struct cifs_search_info {
    bool endOfSearch;
    int info_level;
    uint32_t resume_key;
    int resume_name_len;
    char *presume_name;
    bool unicode;
    bool smallBuf;
    void *ntwrk_buf_start;
    char *srch_entries_start;
    char *last_entry;
    int entries_in_buffer;
    int index_of_last_entry;
};

struct smb_com_transaction2_fnext_req {
    __u16 SearchHandle;
};

struct smb_hdr {
    __u16 Flags2;
    char Protocol[4];
};

struct smb_t2_rsp {
    struct smb_hdr hdr;
    struct {
        __u16 ParameterOffset;
        __u16 DataOffset;
    } t2;
};

typedef struct {
    __u16 SearchCount;
    __u16 EndofSearch;
    __u16 LastNameOffset;
} T2_FNEXT_RSP_PARMS;

typedef struct {
    __u16 TotalDataCount;
    __u16 MaxParameterCount;
    __u16 MaxDataCount;
    __u8 MaxSetupCount;
    __u8 Reserved;
    __u8 Flags;
    __u32 Timeout;
    __u16 Reserved2;
    __u16 ParameterOffset;
    __u16 DataCount;
    __u16 DataOffset;
    __u8 SetupCount;
    __u8 Reserved3;
    __u16 SubCommand;
    __u16 SearchHandle;
    __u16 SearchCount;
    __u16 InformationLevel;
    __u32 ResumeKey;
    __u16 SearchFlags;
    char ResumeFileName[PATH_MAX];
    __u16 ByteCount;
    __u16 TotalParameterCount;
    __u16 ParameterCount;
} TRANSACTION2_FNEXT_REQ;

typedef struct {
    struct smb_hdr hdr;
    struct {
        __u16 ParameterOffset;
        __u16 DataOffset;
    } t2;
} TRANSACTION2_FNEXT_RSP;

typedef struct {
    char dummy[1];
} FILE_UNIX_INFO;

static inline __u16 cpu_to_le16(__u16 val) { return val; }
static inline __u16 le16_to_cpu(__u16 val) { return val; }

void cFYI(int level, const char *fmt, ...);
void cERROR(int level, const char *fmt, ...);
int smb_init(int command, int wct, struct cifs_tcon *tcon, void **request_buf, void **response_buf);
int SendReceive(int xid, void *ses, struct smb_hdr *in_buf, struct smb_hdr *out_buf, int *bytes_returned, int timeout);
void cifs_stats_inc(void *counter);
void cifs_buf_release(void *buf);
void cifs_small_buf_release(void *buf);
int validate_t2(struct smb_t2_rsp *rsp);
void inc_rfc1001_len(void *buf, int count);