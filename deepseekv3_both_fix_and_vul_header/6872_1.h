#include <stdint.h>
#include <stddef.h>

#define STATUS_MORE_PROCESSING_REQUIRED 0xC0000016
#define SMB2_ERROR_STRUCTURE_SIZE2_LE 9
#define __SMB2_HEADER_STRUCTURE_SIZE 64
#define MAX_STREAM_PROT_LEN 0xFFFFFF
#define SMB2_SESSION_SETUP 1
#define SMB2_TREE_CONNECT 2
#define SMB2_CREATE 3
#define SMB2_QUERY_INFO 4
#define SMB2_SET_INFO 5
#define SMB2_READ 6
#define SMB2_WRITE 7
#define SMB2_QUERY_DIRECTORY 8
#define SMB2_LOCK 9
#define SMB2_IOCTL 10

typedef uint64_t u64;

struct smb2_hdr {
    uint32_t Status;
    uint16_t Command;
};

struct smb2_err_rsp {
    uint16_t StructureSize;
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
    uint32_t CreateContextsLength;
    uint32_t CreateContextsOffset;
    uint16_t NameOffset;
    uint16_t NameLength;
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
    uint8_t Buffer[1];
};

struct smb2_query_directory_req {
    uint16_t FileNameOffset;
    uint16_t FileNameLength;
};

struct smb2_lock_req {
    uint16_t LockCount;
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

#define ksmbd_debug(type, fmt, ...)
#define EINVAL 22

static inline uint16_t le16_to_cpu(uint16_t x) { return x; }
static inline uint32_t le32_to_cpu(uint32_t x) { return x; }
#define max_t(type, x, y) ((x) > (y) ? (x) : (y))