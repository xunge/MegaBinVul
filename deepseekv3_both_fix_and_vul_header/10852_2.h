#include <wchar.h>

#define MAX_PATH 260

typedef const wchar_t* LPCWSTR;
typedef wchar_t WCHAR;
typedef unsigned long DWORD;

typedef struct _WIN32_FILE_ATTRIBUTE_DATA {
    DWORD dwFileAttributes;
} WIN32_FILE_ATTRIBUTE_DATA;

#define FILE_ATTRIBUTE_DIRECTORY 0x00000010
#define GetFileExInfoStandard 0

static int wcscpy_s(WCHAR* dest, size_t size, const WCHAR* src);
static int _dirnameW(WCHAR *path);
static int _joinW(WCHAR *dest, const WCHAR *dir, const WCHAR *file);
static int GetFileAttributesExW(const WCHAR* lpFileName, int fInfoLevelId, WIN32_FILE_ATTRIBUTE_DATA* lpFileInformation);