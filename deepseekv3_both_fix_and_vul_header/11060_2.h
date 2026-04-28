#include <stdint.h>
#include <stdlib.h>

typedef int32_t GF_Err;
typedef uint32_t u32;
typedef uint8_t Bool;

typedef struct GF_BitStream GF_BitStream;
typedef struct GF_IPMPX_Data GF_IPMPX_Data;
typedef struct GF_IPMPX_ByteArray GF_IPMPX_ByteArray;

typedef struct GF_IPMPX_Authentication {
    // Placeholder fields
    u32 dummy;
} GF_IPMPX_Authentication;

typedef struct GF_IPMPX_MutualAuthentication {
    Bool failedNegotiation;
    void *candidateAlgorithms;
    void *agreedAlgorithms;
    GF_IPMPX_ByteArray *AuthenticationData;
    u32 certType;
    void *certificates;
    GF_IPMPX_Authentication *publicKey;
    GF_IPMPX_ByteArray *opaque;
    void *trustData;
    GF_IPMPX_ByteArray *authCodes;
} GF_IPMPX_MutualAuthentication;

extern GF_Err GF_IPMPX_AUTH_Parse(GF_BitStream *bs, GF_IPMPX_Authentication **auth);
extern GF_IPMPX_ByteArray *GF_IPMPX_GetByteArray(GF_BitStream *bs);
extern GF_Err gf_ipmpx_data_parse(GF_BitStream *bs, GF_IPMPX_Data **data);
extern int gf_bs_read_int(GF_BitStream *bs, int numBits);
extern void gf_list_add(void *list, void *item);

#define GF_OK 0