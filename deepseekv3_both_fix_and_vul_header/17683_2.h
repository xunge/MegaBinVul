#include <stdint.h>
#include <string.h>

typedef unsigned char BYTE;
typedef int SECURITY_STATUS;
typedef int BOOL;

#define SEC_E_INTERNAL_ERROR 1
#define SEC_E_INVALID_TOKEN 2
#define SEC_I_CONTINUE_NEEDED 3
#define FALSE 0
#define MESSAGE_TYPE_NEGOTIATE 1
#define NTLMSSP_REQUEST_TARGET 0x00000004
#define NTLMSSP_NEGOTIATE_NTLM 0x00000200
#define NTLMSSP_NEGOTIATE_UNICODE 0x00000001
#define NTLMSSP_NEGOTIATE_DOMAIN_SUPPLIED 0x00001000
#define NTLMSSP_NEGOTIATE_WORKSTATION_SUPPLIED 0x00002000
#define NTLMSSP_NEGOTIATE_VERSION 0x02000000
#define NTLM_STATE_CHALLENGE 1

typedef struct {
    void* pvBuffer;
    unsigned long cbBuffer;
    unsigned long BufferType;
} SecBuffer, *PSecBuffer;

typedef struct {
    uint32_t MessageType;
    uint32_t NegotiateFlags;
    struct {
        uint16_t Length;
        uint16_t MaxLength;
        uint32_t BufferOffset;
    } DomainName;
    struct {
        uint16_t Length;
        uint16_t MaxLength;
        uint32_t BufferOffset;
    } Workstation;
    struct {
        uint8_t MajorVersion;
        uint8_t MinorVersion;
        uint16_t BuildNumber;
        uint8_t Reserved[3];
        uint8_t NTLMRevision;
    } Version;
} NTLM_NEGOTIATE_MESSAGE, NTLM_MESSAGE_HEADER;

typedef struct {
    NTLM_NEGOTIATE_MESSAGE NEGOTIATE_MESSAGE;
    SecBuffer NegotiateMessage;
    uint32_t NegotiateFlags;
    int state;
} NTLM_CONTEXT;

typedef struct {
    BYTE* buffer;
    size_t position;
    size_t length;
} wStream;

wStream* Stream_New(BYTE* data, size_t size);
void Stream_Free(wStream* s, BOOL freeBuffer);
int Stream_Read_UINT32(wStream* s, uint32_t* value);
size_t Stream_GetPosition(wStream* s);
int ntlm_read_message_header(wStream* s, NTLM_MESSAGE_HEADER* header);
int ntlm_read_message_fields(wStream* s, void* fields);
int ntlm_read_version_info(wStream* s, void* version);
BOOL sspi_SecBufferAlloc(PSecBuffer buffer, size_t size);
void* CopyMemory(void* dest, const void* src, size_t count);
void ZeroMemory(void* ptr, size_t size);