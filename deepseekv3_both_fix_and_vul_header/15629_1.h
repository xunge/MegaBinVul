#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#define CK_PTR *
#define CK_DECLARE_FUNCTION(returnType, name) returnType name
#define CK_DECLARE_FUNCTION_POINTER(returnType, name) returnType (* name)
#define CK_CALLBACK_FUNCTION(returnType, name) returnType (* name)

typedef unsigned long int CK_ULONG;
typedef long int CK_LONG;
typedef unsigned char CK_BYTE;
typedef CK_BYTE CK_CHAR;
typedef CK_BYTE CK_UTF8CHAR;
typedef unsigned char CK_BBOOL;
typedef unsigned long int CK_FLAGS;
typedef CK_BYTE CK_SESSION_HANDLE;
typedef CK_ULONG CK_RV;
typedef CK_ULONG CK_SLOT_ID;
typedef CK_ULONG CK_OBJECT_HANDLE;

#define CKR_OK 0
#define CKR_SLOT_ID_INVALID 1
#define CKR_KEY_HANDLE_INVALID 2
#define CKR_MECHANISM_INVALID 3
#define CKR_MECHANISM_PARAM_INVALID 4
#define CK_UNAVAILABLE_INFORMATION (~0UL)
#define CK_INVALID_HANDLE 0
#define CKM_RSA_PKCS 0x00000001

#define RET_OSSL_OK 1
#define RET_OSSL_ERR 0
#define ERR_LIB_PROV 0
#define PROV_R_INVALID_KEY 0
#define PROV_R_ILLEGAL_OR_UNSUPPORTED_PADDING_MODE 0

struct p11prov_rsaenc_ctx {
    void *key;
    void *provctx;
};

typedef struct P11PROV_SESSION P11PROV_SESSION;

typedef struct CK_MECHANISM {
    CK_ULONG mechanism;
    void *pParameter;
    CK_ULONG ulParameterLen;
} CK_MECHANISM;

void P11PROV_debug(const char *fmt, ...);
void P11PROV_raise(void *provctx, CK_RV ret, const char *fmt, ...);
void ERR_raise(int lib, int reason);
CK_ULONG p11prov_obj_get_key_size(void *key);
CK_SLOT_ID p11prov_obj_get_slotid(void *key);
CK_OBJECT_HANDLE p11prov_obj_get_handle(void *key);
CK_RV p11prov_rsaenc_set_mechanism(struct p11prov_rsaenc_ctx *ctx, CK_MECHANISM *mech);
CK_RV p11prov_get_session(void *provctx, CK_SLOT_ID *slotid, void *a, void *b, CK_ULONG mechanism, void *c, void *d, bool e, bool f, P11PROV_SESSION **session);
CK_SESSION_HANDLE p11prov_session_handle(P11PROV_SESSION *session);
CK_RV p11prov_DecryptInit(void *provctx, CK_SESSION_HANDLE sess, CK_MECHANISM *mech, CK_OBJECT_HANDLE handle);
CK_RV p11prov_Decrypt(void *provctx, CK_SESSION_HANDLE sess, void *in, size_t inlen, unsigned char *out, CK_ULONG *outlen);
CK_RV side_channel_free_Decrypt(void *provctx, CK_SESSION_HANDLE sess, void *in, size_t inlen, unsigned char *out, CK_ULONG *outlen);
void p11prov_return_session(P11PROV_SESSION *session);
int constant_equal(CK_RV a, CK_RV b);
int constant_select_int(int cond, int a, int b);