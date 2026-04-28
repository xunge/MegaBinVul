#include <stddef.h>
#include <string.h>

typedef unsigned char byte;
typedef unsigned int word32;

#define WOLFSSL_ENTER(x)
#define WOLFSSL_MSG(x)
#define ASN_PARSE_E -1
#define ASN_INPUT_E -1
#define ASN_OCSP_CONFIRM_E -1
#define NO_VERIFY 0
#define VERIFY_OCSP 1
#define VERIFY_OCSP_CERT 1
#define CERT_TYPE 0
#define OCSP_DIGEST_SIZE 32
#define EXTKEYUSE_OCSP_SIGN 0
#define OPENSSL_EXTRA
#define OCSP_BAD_ISSUER -1
#define BAD_OCSP_RESPONDER -1
#define NO_SKID
#define INVALID_DEVID 0

#define XMEMCMP memcmp

typedef struct {
    byte* sig;
    word32 sigSz;
    int sigOID;
    byte* response;
    word32 responseSz;
    byte* cert;
    word32 certSz;
    int verifyError;
    struct {
        byte issuerHash[OCSP_DIGEST_SIZE];
        byte issuerKeyHash[OCSP_DIGEST_SIZE];
    }* single;
} OcspResponse;

typedef struct {
    byte* publicKey;
    word32 pubKeySize;
    int keyOID;
} Signer;

typedef struct {
    byte subjectHash[OCSP_DIGEST_SIZE];
    int extExtKeyUsage;
    byte* cert;
    word32 certSz;
    struct {
        byte* publicKey;
        word32 pubKeySize;
        int keyOID;
    } sigCtx;
    byte* publicKey;
    word32 pubKeySize;
    int keyOID;
} DecodedCert;

typedef struct {
    void* heap;
    int devId;
} SignatureCtx;

extern int GetSequence(byte* source, word32* idx, int* length, word32 size);
extern int DecodeResponseData(byte* source, word32* idx, OcspResponse* resp, word32 size);
extern int GetAlgoId(byte* source, word32* idx, int* sigOID, int* oidSigType, word32 size);
extern int CheckBitString(byte* source, word32* idx, int* sigLength, word32 size, int flag, void* unused);
extern int DecodeCerts(byte* source, word32* idx, OcspResponse* resp, word32 size);
extern void InitDecodedCert(DecodedCert* cert, byte* der, word32 derSz, void* heap);
extern int ParseCertRelative(DecodedCert* cert, int type, int verify, void* cm);
extern void FreeDecodedCert(DecodedCert* cert);
extern Signer* GetCA(void* cm, byte* hash);
extern void InitSignatureCtx(SignatureCtx* ctx, void* heap, int devId);
extern int ConfirmSignature(SignatureCtx* ctx, byte* response, word32 responseSz, byte* publicKey, word32 pubKeySize, int keyOID, byte* sig, word32 sigSz, int sigOID, void* unused);
extern int* oidSigType;