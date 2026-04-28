#include <stddef.h>
#include <string.h>

typedef unsigned char byte;
typedef unsigned short word16;
typedef unsigned int word32;

#define WOLFSSL_MAX_PATH_LEN 0
#define BAD_FUNC_ARG -1
#define ASN_BEFORE_DATE_E -2
#define ASN_AFTER_DATE_E -3
#define ASN_PARSE_E -4
#define ASN_VERSION_E -5
#define ASN_SIG_OID_E -6
#define ASN_PATHLEN_INV_E -7
#define ASN_NAME_INVALID_E -8
#define ASN_NO_SIGNER_E -9
#define ASN_CRIT_EXT_E -10
#define MEMORY_E -11
#define WC_PENDING_E -12

#define NO_VERIFY 0
#define VERIFY 1
#define VERIFY_OCSP 2
#define VERIFY_SKIP_DATE 3
#define VERIFY_NAME 4

#define CERTREQ_TYPE 0
#define CA_TYPE 1
#define TRUSTED_PEER_TYPE 2

#define SIG_STATE_BEGIN 0

#define ASN_CONTEXT_SPECIFIC 0x80
#define ASN_CONSTRUCTED 0x20
#define ASN_PRINTABLE_STRING 0x13
#define ASN_UTF8STRING 0x0C
#define ASN_IA5_STRING 0x16

#define CHALLENGE_PASSWORD_OID 0
#define SERIAL_NUMBER_OID 1
#define EXTENSION_REQUEST_OID 2

#define KEYUSE_KEY_CERT_SIGN 0x04

#define RSAk 0
#define TSIP_TLS_ENCPUBKEY_SZ_BY_CERTVRFY 256
#define EXTERNAL_SERIAL_SIZE 20
#define KEYID_SIZE 20

#define oidSigType 0
#define oidCsrAttrType 0

typedef struct DecodedCert DecodedCert;

#define WOLFSSL_MSG(msg)
#define XMEMCPY(dst, src, len) memcpy(dst, src, len)
#define XMEMCMP(a, b, len) memcmp(a, b, len)
#define XMALLOC(size, heap, type) malloc(size)

enum {
    DYNAMIC_TYPE_RSA
};

struct DecodedCert {
    int isCSR;
    int badDate;
    int criticalExt;
    int version;
    int isCA;
    int pathLengthSet;
    int extKeyUsageSet;
    int extSubjKeyIdSet;
    int extAuthKeyIdSet;
    int ocspNoCheckSet;
    int selfSigned;
    int maxPathLen;
    int pathLength;
    word32 extKeyUsage;
    word32 signatureOID;
    byte* source;
    word32 srcIdx;
    word32 maxIdx;
    word32 sigIndex;
    word32 certBegin;
    word32 extensionsIdx;
    byte* extensions;
    word32 extensionsSz;
    byte* publicKey;
    word32 pubKeySize;
    int keyOID;
    byte extSubjKeyId[KEYID_SIZE];
    byte extAuthKeyId[KEYID_SIZE];
    byte issuerHash[KEYID_SIZE];
    byte issuerKeyHash[KEYID_SIZE];
    byte subjectKeyHash[KEYID_SIZE];
    byte subjectNameHash[KEYID_SIZE];
    byte serial[EXTERNAL_SERIAL_SIZE];
    word32 serialSz;
    char* cPwd;
    word32 cPwdLen;
    char* sNum;
    word32 sNumLen;
    byte* signature;
    word32 sigLength;
    DecodedCert* ca;
    void* heap;
    byte* tsip_encRsaKeyIdx;
    int cm_idx;
    struct {
        int state;
        word32 pubkey_n_start;
        word32 pubkey_n_len;
        word32 pubkey_e_start;
        word32 pubkey_e_len;
        word32 certBegin;
    } sigCtx;
};

int DecodeToKey(DecodedCert* cert, int verify);
int GetASNHeader_ex(byte* source, int tag, word32* idx, int* len, word32 maxIdx, int check);
int GetSequence(byte* source, word32* idx, int* len, word32 maxIdx);
int GetObjectId(byte* source, word32* idx, word32* oid, int oidType, word32 maxIdx);
int GetSet(byte* source, word32* idx, int* len, word32 maxIdx);
int GetHeader(byte* source, byte* tag, word32* idx, int* len, word32 maxIdx, int check);
int DecodeCertExtensions(DecodedCert* cert);
int GetAlgoId(byte* source, word32* idx, word32* oid, int oidType, word32 maxIdx);
int GetSignature(DecodedCert* cert);
int CalcHashId(byte* publicKey, word32 pubKeySize, byte* hash);
DecodedCert* GetCA(void* cm, byte* hash);
DecodedCert* GetCAByName(void* cm, byte* hash);
DecodedCert* GetCABySubjectAndPubKey(DecodedCert* cert, void* cm);
int ConfirmSignature(void* ctx, byte* cert, word32 certSz, byte* pubKey, word32 pubKeySz, int keyOID, byte* sig, word32 sigSz, word32 sigOID, byte* tsipKey);
int ConfirmNameConstraints(DecodedCert* ca, DecodedCert* cert);
int RsaPublicKeyDecodeRawIndex(byte* input, word32* inOutIdx, word32 inSz, word32* nStart, word32* nLen, word32* eStart, word32* eLen);
int tsip_checkCA(int cm_idx);