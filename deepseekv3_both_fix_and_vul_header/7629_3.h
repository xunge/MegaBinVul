#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <assert.h>

#define TRUE true
#define FALSE false
#define TAG "NTLM"
#define WINPR_ASSERT(expr) assert(expr)
#define WLog_ERR(tag, ...) ((void)0)

typedef uint8_t BYTE;
typedef bool BOOL;
typedef uint16_t WCHAR;
typedef WCHAR* LPWSTR;

typedef struct {
    struct {
        WCHAR* User;
        size_t UserLength;
        WCHAR* Domain;
        size_t DomainLength;
    } identity;
} SSPI_CREDENTIALS;

typedef struct {
    SSPI_CREDENTIALS* credentials;
    const char* SamFile;
} NTLM_CONTEXT;

typedef struct _WINPR_SAM WINPR_SAM;
typedef struct _WINPR_SAM_ENTRY {
    BYTE NtHash[16];
} WINPR_SAM_ENTRY;

WINPR_SAM* SamOpen(const char* file, BOOL writeable);
WINPR_SAM_ENTRY* SamLookupUserW(WINPR_SAM* sam, LPWSTR user, size_t user_len, LPWSTR domain, size_t domain_len);
void SamFreeEntry(WINPR_SAM* sam, WINPR_SAM_ENTRY* entry);
void SamClose(WINPR_SAM* sam);
void NTOWFv2FromHashW(const BYTE* hash, LPWSTR user, size_t user_len, LPWSTR domain, size_t domain_len, BYTE* out_hash);