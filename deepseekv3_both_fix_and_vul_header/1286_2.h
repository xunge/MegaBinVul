#include <stddef.h>

typedef unsigned long CK_ULONG;
typedef unsigned char CK_BYTE;
typedef unsigned long CK_RV;
#define CKR_OK 0
#define CKR_FUNCTION_FAILED 1

struct ec_key_st;
typedef struct ec_key_st EC_KEY;

struct ec_point_st;
typedef struct ec_point_st EC_POINT;

#define TRACE_ERROR(msg)

int EC_KEY_oct2priv(EC_KEY *ec_key, const CK_BYTE *data, CK_ULONG data_len);
EC_POINT *EC_POINT_new(const void *group);
const void *EC_KEY_get0_group(const EC_KEY *key);
int EC_POINT_mul(const void *group, EC_POINT *r, const void *n, 
                const void *q, const void *m, void *ctx);
const void *EC_KEY_get0_private_key(const EC_KEY *key);
int EC_KEY_set_public_key(EC_KEY *key, const EC_POINT *pub);
void EC_POINT_free(EC_POINT *point);