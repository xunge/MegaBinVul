#include <stdint.h>
#include <stddef.h>

typedef unsigned char byte;
typedef uint32_t word32;

#define BAD_FUNC_ARG -1
#define ASN_PARSE_E -2
#define BUFFER_E -3
#define ASN_CRIT_EXT_E -4
#define ASN_NAME_INVALID_E -5

#define ASN_EXTENSIONS 0xA3
#define ASN_BOOLEAN 0x01

#define BASIC_CA_OID 0
#define CRL_DIST_OID 1
#define AUTH_INFO_OID 2
#define ALT_NAMES_OID 3
#define AUTH_KEY_OID 4
#define SUBJ_KEY_OID 5
#define CERT_POLICY_OID 6
#define KEY_USAGE_OID 7
#define EXT_KEY_USAGE_OID 8
#define NAME_CONS_OID 9
#define INHIBIT_ANY_OID 10

#define WOLFSSL_ENTER(x)
#define WOLFSSL_MSG(x)
#define VERIFY_AND_SET_OID(x) (x = 1)

enum {
    oidCertExtType = 0
};

typedef struct DecodedCert {
    byte* extensions;
    int extensionsSz;
    int extBasicConstSet;
    int extCRLdistSet;
    int extAuthInfoSet;
    int extSubjAltNameSet;
    int extAuthKeyIdSet;
    int extSubjKeyIdSet;
    int extCertPolicySet;
    int extKeyUsageSet;
    int extExtKeyUsageSet;
    int extNameConstraintSet;
    int inhibitAnyOidSet;
    byte extBasicConstCrit;
    byte extCRLdistCrit;
    byte extAuthInfoCrit;
    byte extSubjAltNameCrit;
    byte extAuthKeyIdCrit;
    byte extSubjKeyIdCrit;
    byte extCertPolicyCrit;
    byte extKeyUsageCrit;
    byte extExtKeyUsageCrit;
    byte extNameConstraintCrit;
    int isCA;
} DecodedCert;

int GetLength(const byte* input, word32* idx, int* length, int sz);
int GetSequence(const byte* input, word32* idx, int* length, int sz);
int GetObjectId(const byte* input, word32* idx, word32* oid, int type, int sz);
int GetBoolean(const byte* input, word32* idx, int sz);
int GetOctetString(const byte* input, word32* idx, int* length, int sz);
int DecodeBasicCaConstraint(const byte* input, int length, DecodedCert* cert);
int DecodeCrlDist(const byte* input, int length, DecodedCert* cert);
int DecodeAuthInfo(const byte* input, int length, DecodedCert* cert);
int DecodeAltNames(const byte* input, int length, DecodedCert* cert);
int DecodeAuthKeyId(const byte* input, int length, DecodedCert* cert);
int DecodeSubjKeyId(const byte* input, int length, DecodedCert* cert);
int DecodeCertPolicy(const byte* input, int length, DecodedCert* cert);
int DecodeKeyUsage(const byte* input, int length, DecodedCert* cert);
int DecodeExtKeyUsage(const byte* input, int length, DecodedCert* cert);
int DecodeNameConstraints(const byte* input, int length, DecodedCert* cert);