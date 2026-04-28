#include <stdlib.h>
#include <stdbool.h>

typedef unsigned long CK_ULONG;
typedef unsigned char CK_BYTE;
typedef bool CK_BBOOL;
typedef unsigned long CK_RV;

#define CKR_OK 0
#define CKR_FUNCTION_FAILED 1
#define CKR_PUBLIC_KEY_INVALID 2
#define FALSE false
#define TRUE true

typedef struct EC_KEY EC_KEY;
typedef struct EC_GROUP EC_GROUP;

unsigned int EC_GROUP_order_bits(const EC_GROUP *group);
const EC_GROUP *EC_KEY_get0_group(const EC_KEY *key);
int EC_KEY_oct2key(EC_KEY *key, const unsigned char *buf, size_t len, void *ignored);
int EC_KEY_check_key(const EC_KEY *key);

CK_RV ec_point_from_public_data(const CK_BYTE *data, CK_ULONG data_len,
                               CK_ULONG privlen, CK_BBOOL allow_raw,
                               CK_BBOOL *allocated, CK_BYTE **ecpoint,
                               CK_ULONG *ecpoint_len);

void TRACE_DEVEL(const char *msg);
void TRACE_ERROR(const char *msg);