#include <string.h>
#include <stdint.h>

#define NTLMSSP_SIGNATURE "NTLMSSP"
#define NtLmNegotiate 1

#define NTLMSSP_NEGOTIATE_56 0x80000000
#define NTLMSSP_REQUEST_TARGET 0x00000004
#define NTLMSSP_NEGOTIATE_128 0x20000000
#define NTLMSSP_NEGOTIATE_UNICODE 0x00000001
#define NTLMSSP_NEGOTIATE_NTLM 0x00000200
#define NTLMSSP_NEGOTIATE_EXTENDED_SEC 0x00080000
#define NTLMSSP_NEGOTIATE_SEAL 0x00000020
#define NTLMSSP_NEGOTIATE_SIGN 0x00000010
#define NTLMSSP_NEGOTIATE_KEY_XCH 0x40000000

typedef uint32_t __u32;

struct cifs_ses {
    struct cifs_server *server;
    struct ntlmssp_auth *ntlmssp;
};

struct cifs_server {
    int sign;
    int session_estab;
};

struct ntlmssp_auth {
    int sesskey_per_smbsess;
};

typedef struct {
    uint16_t Length;
    uint16_t MaximumLength;
    uint32_t BufferOffset;
} SECURITY_BUFFER;

typedef struct {
    char Signature[8];
    __u32 MessageType;
    __u32 NegotiateFlags;
    SECURITY_BUFFER DomainName;
    SECURITY_BUFFER WorkstationName;
} NEGOTIATE_MESSAGE;

static inline __u32 cpu_to_le32(__u32 x) {
    return x;
}