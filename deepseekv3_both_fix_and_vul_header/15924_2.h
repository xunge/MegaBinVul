#include <stdint.h>
#include <stddef.h>

typedef void* HMODULE;
typedef void* HANDLE;
typedef uint32_t DWORD;
typedef uint32_t ULONG;
typedef int32_t LONG;
typedef int32_t NTSTATUS;
typedef uint8_t UCHAR;
typedef uint8_t BOOLEAN;
typedef int BOOL;

struct _IO_STATUS_BLOCK;
typedef struct _IO_STATUS_BLOCK IO_STATUS_BLOCK, *PIO_STATUS_BLOCK;
struct _OVERLAPPED;
typedef struct _OVERLAPPED OVERLAPPED, *LPOVERLAPPED;
struct _OVERLAPPED_ENTRY;
typedef struct _OVERLAPPED_ENTRY OVERLAPPED_ENTRY, *LPOVERLAPPED_ENTRY;
struct _CRITICAL_SECTION;
typedef struct _CRITICAL_SECTION CRITICAL_SECTION, *PCRITICAL_SECTION;
struct _SRWLOCK;
typedef struct _SRWLOCK SRWLOCK, *PSRWLOCK;
struct _CONDITION_VARIABLE;
typedef struct _CONDITION_VARIABLE CONDITION_VARIABLE, *PCONDITION_VARIABLE;

typedef void (*PIO_APC_ROUTINE)(void*, PIO_STATUS_BLOCK, ULONG);

typedef LONG (*sRtlNtStatusToDosError)(NTSTATUS Status);
typedef NTSTATUS (*sNtQueryInformationFile)(HANDLE, PIO_STATUS_BLOCK, void*, ULONG, int);
typedef NTSTATUS (*sNtDeviceIoControlFile)(HANDLE, HANDLE, PIO_APC_ROUTINE, void*, PIO_STATUS_BLOCK, ULONG, void*, ULONG, void*, ULONG);
typedef NTSTATUS (*sNtSetInformationFile)(HANDLE, PIO_STATUS_BLOCK, void*, ULONG, int);
typedef NTSTATUS (*sNtQuerySystemInformation)(int, void*, ULONG, ULONG*);
typedef BOOL (*sGetQueuedCompletionStatusEx)(HANDLE, LPOVERLAPPED_ENTRY, ULONG, ULONG*, DWORD, BOOL);
typedef BOOL (*sSetFileCompletionNotificationModes)(HANDLE, UCHAR);
typedef BOOLEAN (*sCreateSymbolicLinkW)(const wchar_t*, const wchar_t*, DWORD);
typedef BOOL (*sCancelIoEx)(HANDLE, LPOVERLAPPED);
typedef void (*sInitializeSRWLock)(PSRWLOCK);
typedef void (*sAcquireSRWLockShared)(PSRWLOCK);
typedef void (*sAcquireSRWLockExclusive)(PSRWLOCK);
typedef BOOLEAN (*sTryAcquireSRWLockShared)(PSRWLOCK);
typedef BOOLEAN (*sTryAcquireSRWLockExclusive)(PSRWLOCK);
typedef void (*sReleaseSRWLockShared)(PSRWLOCK);
typedef void (*sReleaseSRWLockExclusive)(PSRWLOCK);
typedef void (*sInitializeConditionVariable)(PCONDITION_VARIABLE);
typedef BOOL (*sSleepConditionVariableCS)(PCONDITION_VARIABLE, PCRITICAL_SECTION, DWORD);
typedef BOOL (*sSleepConditionVariableSRW)(PCONDITION_VARIABLE, PSRWLOCK, DWORD, ULONG);
typedef void (*sWakeAllConditionVariable)(PCONDITION_VARIABLE);
typedef void (*sWakeConditionVariable)(PCONDITION_VARIABLE);

extern HMODULE GetModuleHandleA(const char*);
extern void* GetProcAddress(HMODULE, const char*);
extern DWORD GetLastError(void);
extern void uv_fatal_error(DWORD, const char*);

sRtlNtStatusToDosError pRtlNtStatusToDosError;
sNtQueryInformationFile pNtQueryInformationFile;
sNtDeviceIoControlFile pNtDeviceIoControlFile;
sNtSetInformationFile pNtSetInformationFile;
sNtQuerySystemInformation pNtQuerySystemInformation;
sGetQueuedCompletionStatusEx pGetQueuedCompletionStatusEx;
sSetFileCompletionNotificationModes pSetFileCompletionNotificationModes;
sCreateSymbolicLinkW pCreateSymbolicLinkW;
sCancelIoEx pCancelIoEx;
sInitializeSRWLock pInitializeSRWLock;
sAcquireSRWLockShared pAcquireSRWLockShared;
sAcquireSRWLockExclusive pAcquireSRWLockExclusive;
sTryAcquireSRWLockShared pTryAcquireSRWLockShared;
sTryAcquireSRWLockExclusive pTryAcquireSRWLockExclusive;
sReleaseSRWLockShared pReleaseSRWLockShared;
sReleaseSRWLockExclusive pReleaseSRWLockExclusive;
sInitializeConditionVariable pInitializeConditionVariable;
sSleepConditionVariableCS pSleepConditionVariableCS;
sSleepConditionVariableSRW pSleepConditionVariableSRW;
sWakeAllConditionVariable pWakeAllConditionVariable;
sWakeConditionVariable pWakeConditionVariable;