#include <stddef.h>
#include <string.h>
#include <ctype.h>

#define FACILITY_CERT 0x1000
#define FAC(fac) ((fac) << 16)
#define ARRAYSIZE(arr) (sizeof(arr)/sizeof((arr)[0]))

typedef void* HWND;
typedef long LONG;
typedef unsigned long DWORD;
typedef unsigned int UINT;
typedef unsigned short WORD;

typedef struct {
    DWORD cbStruct;
    wchar_t* pcwszFilePath;
} WINTRUST_FILE_INFO;

typedef struct {
    DWORD cbStruct;
    DWORD dwUIChoice;
    DWORD fdwRevocationChecks;
    DWORD dwProvFlags;
    DWORD dwUnionChoice;
    void* pFile;
} WINTRUST_DATA;

typedef struct {
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
} GUID;

#define WTD_UI_NONE 2
#define WTD_UI_ALL 1
#define WTD_REVOKE_WHOLECHAIN 1
#define WTD_REVOCATION_CHECK_CHAIN 1
#define WTD_CHOICE_FILE 1

#define TRUST_E_NOSIGNATURE 0x800B0100
#define TRUST_E_EXPLICIT_DISTRUST 0x800B0111
#define ERROR_SEVERITY_ERROR 0xC0000000
#define ERROR_NOT_ENOUGH_MEMORY 8
#define ERROR_SUCCESS 0

#define MB_OK 0x00000000
#define MB_YESNO 0x00000004
#define MB_ICONERROR 0x00000010
#define MB_ICONWARNING 0x00000030
#define MB_IS_RTL 0x00100000
#define IDYES 6

#define MSG_240 240
#define MSG_283 283
#define MSG_284 284
#define MSG_285 285

static const char* cert_name[] = {""};

extern char* GetSignatureName(const char* path);
extern wchar_t* utf8_to_wchar(const char* utf8);
extern void safe_free(void* ptr);
extern void uprintf(const char* fmt, ...);
extern int MessageBoxExU(HWND hWnd, const char* text, const char* caption, UINT type, WORD langid);
extern const char* lmprintf(int msgid, ...);
extern const char* WinPKIErrorString(void);
extern LONG WinVerifyTrust(void* hwnd, GUID* pgActionID, WINTRUST_DATA* pWintrustData);

extern WORD selected_langid;