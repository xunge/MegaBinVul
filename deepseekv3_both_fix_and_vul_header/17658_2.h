#include <stdint.h>
#include <string.h>
#include <stddef.h>

#define FALSE 0
#define TRUE 1

typedef int SECURITY_STATUS;
typedef unsigned char BYTE;
typedef BYTE* PBYTE;

#define SEC_E_INTERNAL_ERROR ((SECURITY_STATUS)0x80090304L)
#define SEC_E_INVALID_TOKEN ((SECURITY_STATUS)0x80090308L)
#define SEC_I_CONTINUE_NEEDED ((SECURITY_STATUS)0x00090312L)

#define MESSAGE_TYPE_CHALLENGE 2
#define NTLMSSP_NEGOTIATE_VERSION 0x02000000
#define NTLMSSP_NEGOTIATE_TARGET_INFO 0x00800000
#define MsvAvTimestamp 7
#define NTLM_STATE_AUTHENTICATE 3

typedef struct _SecBuffer {
    unsigned long cbBuffer;
    void* pvBuffer;
} SecBuffer, *PSecBuffer;

typedef struct _NTLM_MESSAGE_HEADER {
    uint32_t MessageType;
} NTLM_MESSAGE_HEADER;

typedef struct _NTLM_MESSAGE_FIELDS {
    unsigned short Len;
    unsigned short MaxLen;
    unsigned long BufferOffset;
    PBYTE Buffer;
} NTLM_MESSAGE_FIELDS;

typedef struct _NTLM_AV_PAIR {
    unsigned short AvId;
    unsigned short AvLen;
} NTLM_AV_PAIR;

typedef struct _NTLM_CHALLENGE_MESSAGE {
    uint32_t MessageType;
    NTLM_MESSAGE_FIELDS TargetName;
    uint32_t NegotiateFlags;
    uint8_t ServerChallenge[8];
    uint8_t Reserved[8];
    NTLM_MESSAGE_FIELDS TargetInfo;
    struct {
        uint8_t Major;
        uint8_t Minor;
        uint16_t Build;
        uint8_t Reserved[3];
        uint8_t NTLMRevision;
    } Version;
} NTLM_CHALLENGE_MESSAGE;

typedef struct _NTLM_CONTEXT {
    NTLM_CHALLENGE_MESSAGE CHALLENGE_MESSAGE;
    uint32_t NegotiateFlags;
    uint8_t ServerChallenge[8];
    uint8_t ClientChallenge[8];
    uint8_t ChallengeTimestamp[8];
    uint8_t SessionBaseKey[16];
    uint8_t KeyExchangeKey[16];
    uint8_t RandomSessionKey[16];
    uint8_t ExportedSessionKey[16];
    uint8_t ClientSigningKey[16];
    uint8_t ClientSealingKey[16];
    uint8_t ServerSigningKey[16];
    uint8_t ServerSealingKey[16];
    uint8_t Timestamp[8];
    SecBuffer ChallengeMessage;
    SecBuffer ChallengeTargetInfo;
    SecBuffer AuthenticateTargetInfo;
    int state;
    int NTLMv2;
    int UseMIC;
} NTLM_CONTEXT;

typedef struct _wStream {
    BYTE* buffer;
    BYTE* pointer;
    size_t length;
} wStream;

static inline void ZeroMemory(void* ptr, size_t size) {
    memset(ptr, 0, size);
}

static inline void CopyMemory(void* dest, const void* src, size_t size) {
    memcpy(dest, src, size);
}

wStream* Stream_New(BYTE* buffer, size_t size);
BYTE* Stream_Pointer(wStream* s);
void Stream_Free(wStream* s, int bFreeBuffer);
size_t Stream_GetRemainingLength(wStream* s);
void Stream_Read(wStream* s, void* dst, size_t size);
void Stream_Read_UINT32(wStream* s, uint32_t* value);

int ntlm_read_message_header(wStream* s, NTLM_MESSAGE_HEADER* header);
int ntlm_read_message_fields(wStream* s, NTLM_MESSAGE_FIELDS* fields);
int ntlm_read_message_fields_buffer(wStream* s, NTLM_MESSAGE_FIELDS* fields);
int ntlm_read_version_info(wStream* s, void* version);
void ntlm_free_message_fields_buffer(NTLM_MESSAGE_FIELDS* fields);

NTLM_AV_PAIR* ntlm_av_pair_get(NTLM_AV_PAIR* pairs, size_t count, unsigned short AvId, size_t* pcbAvLen);
PBYTE ntlm_av_pair_get_value_pointer(NTLM_AV_PAIR* pair);

void ntlm_generate_client_challenge(NTLM_CONTEXT* context);
int ntlm_construct_authenticate_target_info(NTLM_CONTEXT* context);
void ntlm_generate_timestamp(NTLM_CONTEXT* context);
int ntlm_compute_lm_v2_response(NTLM_CONTEXT* context);
int ntlm_compute_ntlm_v2_response(NTLM_CONTEXT* context);
void ntlm_generate_key_exchange_key(NTLM_CONTEXT* context);
void ntlm_generate_random_session_key(NTLM_CONTEXT* context);
void ntlm_generate_exported_session_key(NTLM_CONTEXT* context);
void ntlm_encrypt_random_session_key(NTLM_CONTEXT* context);
void ntlm_generate_client_signing_key(NTLM_CONTEXT* context);
void ntlm_generate_server_signing_key(NTLM_CONTEXT* context);
void ntlm_generate_client_sealing_key(NTLM_CONTEXT* context);
void ntlm_generate_server_sealing_key(NTLM_CONTEXT* context);
void ntlm_init_rc4_seal_states(NTLM_CONTEXT* context);

int sspi_SecBufferAlloc(SecBuffer* buffer, size_t size);
void sspi_SecBufferFree(SecBuffer* buffer);