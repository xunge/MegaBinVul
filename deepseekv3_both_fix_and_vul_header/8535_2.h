#include <stddef.h>

typedef unsigned long SECURITY_STATUS;
typedef unsigned long ULONG_PTR;

#define SEC_ENTRY
#define SEC_E_SECPKG_NOT_FOUND ((SECURITY_STATUS)0x80090305L)
#define SEC_E_UNSUPPORTED_FUNCTION ((SECURITY_STATUS)0x80090302L)

typedef struct _SecHandle {
    ULONG_PTR dwLower;
    ULONG_PTR dwUpper;
} SecHandle, *PSecHandle;

typedef SecHandle CtxtHandle;
typedef CtxtHandle *PCtxtHandle;

typedef SECURITY_STATUS (SEC_ENTRY *DELETE_SECURITY_CONTEXT_FN)(PCtxtHandle);

typedef struct _SecurityFunctionTableA {
    DELETE_SECURITY_CONTEXT_FN DeleteSecurityContext;
} SecurityFunctionTableA;

extern char* sspi_SecureHandleGetUpperPointer(PCtxtHandle phContext);
extern SecurityFunctionTableA* sspi_GetSecurityFunctionTableAByNameA(char* Name);