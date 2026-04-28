#include <stdint.h>
#include <endian.h>
#include <stdbool.h>

typedef uint16_t __le16;
typedef uint32_t __le32;

#define SMB2_PREAUTH_INTEGRITY_CAPABILITIES 1
#define SMB2_ENCRYPTION_CAPABILITIES 2
#define SMB2_COMPRESSION_CAPABILITIES 3
#define SMB2_NETNAME_NEGOTIATE_CONTEXT_ID 5
#define SMB2_POSIX_EXTENSIONS_AVAILABLE 0x100
#define SMB2_SIGNING_CAPABILITIES 8

#define STATUS_INVALID_PARAMETER ((__le32)0xC000000D)
#define STATUS_SUCCESS ((__le32)0x00000000)

struct ksmbd_conn {
    struct preauth_info *preauth_info;
    int cipher_type;
    int compress_algorithm;
    bool posix_ext_supported;
};

struct smb2_negotiate_req {
    __le16 NegotiateContextCount;
    __le32 NegotiateContextOffset;
};

struct smb2_neg_context {
    __le16 ContextType;
    __le16 DataLength;
};

struct smb2_preauth_neg_context {
    __le16 ContextType;
    __le16 DataLength;
};

struct smb2_encryption_neg_context {
    __le16 ContextType;
    __le16 DataLength;
};

struct smb2_compression_capabilities_context {
    __le16 ContextType;
    __le16 DataLength;
};

struct smb2_signing_capabilities {
    __le16 ContextType;
    __le16 DataLength;
};

struct preauth_info {
    int Preauth_HashId;
};

#define SMB 0
#define ksmbd_debug(level, fmt, ...)