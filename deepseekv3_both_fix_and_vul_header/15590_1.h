#include <stdint.h>
#include <stddef.h>

#define SMB2_SESSION_SETUP 0x0001
#define SMB2_TREE_CONNECT 0x0002
#define SMB2_CREATE 0x0005
#define SMB2_QUERY_INFO 0x000E
#define SMB2_SET_INFO 0x000F
#define SMB2_READ 0x0008
#define SMB2_WRITE 0x0009
#define SMB2_QUERY_DIRECTORY 0x000A
#define SMB2_LOCK 0x000B
#define SMB2_IOCTL 0x000C

#define MAX_STREAM_PROT_LEN 0x00FFFFFF
#define EINVAL 22

typedef uint64_t u64;

struct smb2_hdr {
    uint16_t Command;
};

struct smb2_sess_setup_req {
    uint16_t SecurityBufferOffset;
    uint16_t SecurityBufferLength;
};

struct smb2_tree_connect_req {
    uint16_t PathOffset;
    uint16_t PathLength;
};

struct smb2_create_req {
    uint16_t NameOffset;
    uint16_t NameLength;
    uint32_t CreateContextsOffset;
    uint32_t CreateContextsLength;
};

struct smb2_query_info_req {
    uint16_t InputBufferOffset;
    uint32_t InputBufferLength;
};

struct smb2_set_info_req {
    uint16_t BufferOffset;
    uint32_t BufferLength;
};

struct smb2_read_req {
    uint16_t ReadChannelInfoOffset;
    uint16_t ReadChannelInfoLength;
};

struct smb2_write_req {
    uint16_t DataOffset;
    uint32_t Length;
    uint16_t WriteChannelInfoOffset;
    uint16_t WriteChannelInfoLength;
    uint8_t Buffer[0];
};

struct smb2_query_directory_req {
    uint16_t FileNameOffset;
    uint16_t FileNameLength;
};

struct smb2_lock_req {
    uint16_t LockCount;
    uint8_t locks[0];
};

struct smb2_lock_element {
    uint64_t Offset;
    uint64_t Length;
    uint32_t Flags;
    uint32_t Reserved;
};

struct smb2_ioctl_req {
    uint32_t InputOffset;
    uint32_t InputCount;
};

static inline uint16_t le16_to_cpu(uint16_t x) { return x; }
static inline uint32_t le32_to_cpu(uint32_t x) { return x; }
static inline uint64_t le64_to_cpu(uint64_t x) { return x; }

#define max_t(type, x, y) ((x) > (y) ? (x) : (y))

#define ksmbd_debug(category, fmt, ...)