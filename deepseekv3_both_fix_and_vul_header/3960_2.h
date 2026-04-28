#include <stddef.h>

typedef unsigned int UINT32;
typedef unsigned long long UINT64;
typedef unsigned long DWORD;
typedef int BOOL;
typedef void* HANDLE;
typedef void* HWND;
typedef void* HINSTANCE;
typedef long HRESULT;
typedef unsigned short WORD;
typedef unsigned char BYTE;
typedef char TCHAR;
typedef void* FARPROC;
typedef unsigned int UINT;

#define _T(x) x
#define WINAPI
#define MAKELONG(a, b) ((a) | ((b) << 16))
#define MAKEWORD(a, b) ((a) | ((b) << 8))
#define CMP4CHAR(p, s) (*(UINT32*)(p) == *(UINT32*)(s))
#define SET2CHAR(p, s) (*(WORD*)(p) = *(WORD*)(s))
#define NSIS_MAX_STRLEN 1024
#define NSIS_OSINFO_PROD_WOW64FLAG 0x80000000
#define SEM_NOOPENFILEERRORBOX 0x8000
#define SEM_FAILCRITICALERRORS 0x0001
#define VER_PLATFORM_WIN32_NT 2
#define FH_FLAGS_NO_CRC 1
#define CB_ONREBOOTFAILED 0
#define HINST_APPLICATION ((HINSTANCE)0x400000)
#define SHTDN_REASON_FLAG_PLANNED 0x80000000
#define SHTDN_REASON_MAJOR_APPLICATION 0x00040000
#define SHTDN_REASON_MINOR_INSTALLATION 0x00000002
#define SHUTDOWN_RESTART 0x00000002
#define SHUTDOWN_FORCE_OTHERS 0x00000001
#define SHUTDOWN_GRACE_OVERRIDE 0x00000020
#define EWX_REBOOT 0x00000002
#define TOKEN_ADJUST_PRIVILEGES 0x00000020
#define TOKEN_QUERY 0x00000008
#define SE_PRIVILEGE_ENABLED 0x00000002
#define MB_OK 0x00000000
#define MB_ICONSTOP 0x00000010
#define IDOK 1
#define LOAD_LIBRARY_SEARCH_SYSTEM32 0x00000800
#define LOAD_LIBRARY_SEARCH_USER_DIRS 0x00000400
#define MGA_SetDefaultDllDirectories 0
#define MGA_SHGetFolderPath 1
#define MGA_GetFileVersionInfo 2
#define MGA_IsOS 3
#define MGA_InitiateShutdown 4

typedef struct {
  DWORD dwOSVersionInfoSize;
  DWORD dwMajorVersion;
  DWORD dwMinorVersion;
  DWORD dwBuildNumber;
  DWORD dwPlatformId;
  TCHAR szCSDVersion[128];
  WORD wServicePackMajor;
  WORD wServicePackMinor;
  WORD wSuiteMask;
  BYTE wProductType;
  BYTE wReserved;
} OSVERSIONINFOEX, *POSVERSIONINFOEX, *LPOSVERSIONINFOEX, OSVERSIONINFO, *POSVERSIONINFO, *LPOSVERSIONINFO;

typedef struct {
  UINT32 WVBuild;
  UINT32 WVProd;
} OSINFO;

typedef struct {
  BOOL silent;
  BOOL reboot_called;
  int errlvl;
} EXECFLAGS;

typedef struct {
  TCHAR str_uninstchild[NSIS_MAX_STRLEN];
  TCHAR str_uninstcmd[NSIS_MAX_STRLEN];
} HEADER;

typedef struct {
  TCHAR dummy;
} SHFILEINFO;

extern OSINFO g_osinfo;
extern EXECFLAGS g_exec_flags;
extern HEADER* g_header;
extern TCHAR state_command_line[NSIS_MAX_STRLEN];
extern TCHAR state_temp_dir[NSIS_MAX_STRLEN];
extern TCHAR state_language[NSIS_MAX_STRLEN];
extern TCHAR state_install_directory[NSIS_MAX_STRLEN];
extern TCHAR state_output_directory[NSIS_MAX_STRLEN];
extern TCHAR state_exe_directory[NSIS_MAX_STRLEN];
extern TCHAR state_exe_path[NSIS_MAX_STRLEN];
extern TCHAR g_caption[NSIS_MAX_STRLEN];
extern TCHAR g_usrvars[26][NSIS_MAX_STRLEN];
extern HRESULT g_hres;
extern HINSTANCE g_hInstance;
extern FARPROC (WINAPI *g_SHGetFolderPath)(HWND, int, HANDLE, DWORD, TCHAR*);

#define _LANG_ERRORWRITINGTEMP NULL
#define _LANG_GENERIC_ERROR NULL
#define _LANG_UNINSTINITERROR NULL

FARPROC myGetProcAddress(int);
void mystrcpy(TCHAR*, const TCHAR*);
void mystrcat(TCHAR*, const TCHAR*);
TCHAR* findchar(TCHAR*, TCHAR);
TCHAR* CharNext(TCHAR*);
BOOL ValidateTempDir();
const TCHAR* loadHeaders(int);
BOOL UserIsAdminGrpMember();
void CreateRestrictedDirectory(TCHAR*);
void CreateNormalDirectory(TCHAR*);
void GetNSISString(TCHAR*, TCHAR*);
HANDLE myCreateProcess(TCHAR*);
void CleanUp();
int ui_doinstall();
void ExecuteCallbackFunction(int);
BOOL IsWinVista();
void MoveFileOnReboot(TCHAR*, TCHAR*);
BOOL is_valid_instpath(TCHAR*);
int my_MessageBox(const TCHAR*, UINT);
void LoadSystemLibrary(const char*);
void SetErrorMode(UINT);
BOOL GetVersionEx(LPOSVERSIONINFO);
void GetTempPath(DWORD, TCHAR*);
void GetWindowsDirectory(TCHAR*, UINT);
BOOL SetEnvironmentVariable(const TCHAR*, const TCHAR*);
BOOL DeleteFile(const TCHAR*);
BOOL CopyFile(const TCHAR*, const TCHAR*, BOOL);
void CloseHandle(HANDLE);
void ExitProcess(UINT);
void InitCommonControls();
HRESULT OleInitialize(void*);
void OleUninitialize();
BOOL SHGetFileInfo(const TCHAR*, DWORD, SHFILEINFO*, UINT, UINT);
const TCHAR* GetCommandLine();
BOOL lstrcmpi(const TCHAR*, const TCHAR*);
void SetCurrentDirectory(const TCHAR*);