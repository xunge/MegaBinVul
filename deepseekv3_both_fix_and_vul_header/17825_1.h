#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define BB_DATA_BLOB 0
#define TAG "license"
#define WITH_DEBUG_LICENSE 1
#define LICENSE_STATE_COMPLETED 0
#define WLOG_DEBUG 0

typedef uint32_t UINT32;
typedef uint16_t UINT16;
typedef uint8_t BYTE;
typedef int BOOL;

typedef struct {
    BYTE* data;
    UINT32 length;
} LICENSE_BLOB;

typedef struct {
    BYTE* MacSaltKey;
    int state;
    struct {
        struct {
            int OldLicenseBehaviour;
            char* ClientHostname;
            void* settings;
        }* settings;
    }* rdp;
} rdpLicense;

typedef struct wStream wStream;

extern void DEBUG_LICENSE(const char* fmt, ...);
extern LICENSE_BLOB* license_new_binary_blob(int type);
extern BOOL license_read_encrypted_blob(rdpLicense* license, wStream* s, LICENSE_BLOB* blob);
extern BOOL security_mac_data(const BYTE* key, const BYTE* data, UINT32 length, BYTE* output);
extern void WLog_ERR(const char* tag, const char* fmt, ...);
extern void WLog_DBG(const char* tag, const char* fmt, ...);
extern void winpr_HexDump(const char* tag, int level, const BYTE* data, size_t length);
extern BOOL Stream_SafeSeek(wStream* s, size_t offset);
extern wStream* Stream_New(const BYTE* data, size_t size);
extern void Stream_Free(wStream* s, BOOL bFreeBuffer);
extern void Stream_Read_UINT16(wStream* s, UINT16* val);
extern void Stream_Read_UINT32(wStream* s, UINT32* val);
extern size_t Stream_GetRemainingLength(wStream* s);
extern BYTE* Stream_Pointer(wStream* s);
extern void Stream_Seek(wStream* s, size_t offset);
extern void license_free_binary_blob(LICENSE_BLOB* blob);
extern BOOL saveCal(void* settings, const BYTE* data, UINT32 length, const char* hostname);