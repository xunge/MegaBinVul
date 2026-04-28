#include <stdlib.h>
#include <string.h>

#define LTC_PKCS_1_V1_5 1
#define LTC_PKCS_1_PSS 2
#define CRYPT_PK_INVALID_PADDING 1
#define CRYPT_OK 0
#define CRYPT_INVALID_PACKET 2
#define CRYPT_MEM 3
#define CRYPT_INVALID_ARG 4
#define PK_PUBLIC 0
#define LTC_PKCS_1_EMSA 0

#define LTC_ASN1_OBJECT_IDENTIFIER 1
#define LTC_ASN1_NULL 2
#define LTC_ASN1_SEQUENCE 3
#define LTC_ASN1_OCTET_STRING 4

#define LTC_ARGCHK(cond) do { if (!(cond)) return CRYPT_INVALID_ARG; } while(0)
#define XMALLOC(size) malloc(size)
#define XFREE(ptr) free(ptr)
#define XMEMCMP memcmp

typedef struct {
    unsigned long *N;
} rsa_key;

typedef struct {
    int type;
    void *data;
    unsigned long size;
} ltc_asn1_list;

typedef struct {
    unsigned long *OID;
    size_t OIDlen;
} hash_descriptor_t;

extern hash_descriptor_t hash_descriptor[];

struct {
    int (*rsa_me)(const unsigned char *in, unsigned long inlen, unsigned char *out, unsigned long *outlen, int which, rsa_key *key);
} ltc_mp;

#define LTC_SET_ASN1(list, index, Type, Data, Size) \
    do { \
        (list)[index].type = (Type); \
        (list)[index].data = (void*)(Data); \
        (list)[index].size = (Size); \
    } while (0)

int hash_is_valid(int hash_idx);
int mp_count_bits(unsigned long *a);
unsigned long mp_unsigned_bin_size(unsigned long *a);
int pkcs_1_pss_decode(const unsigned char *hash, unsigned long hashlen, const unsigned char *msghash, unsigned long msghashlen, unsigned long saltlen, int hash_idx, unsigned long modulus_bitlen, int *stat);
int pkcs_1_v1_5_decode(const unsigned char *msg, unsigned long msglen, int block_type, unsigned long modulus_bitlen, unsigned char *out, unsigned long *outlen, int *is_valid);
int der_decode_sequence(const unsigned char *in, unsigned long inlen, ltc_asn1_list *list, unsigned long outlen);
void zeromem(void *dst, size_t len);