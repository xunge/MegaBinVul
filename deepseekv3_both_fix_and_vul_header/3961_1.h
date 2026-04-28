#include <stddef.h>

#define NSISCALL
#define DWORD unsigned long
#define LPCTSTR const char*
#define BOOL int
#define FALSE 0
#define ERROR_SUCCESS 0
#define ERROR_ALREADY_EXISTS 183
#define OWNER_SECURITY_INFORMATION 0x00000001
#define GROUP_SECURITY_INFORMATION 0x00000002
#define DACL_SECURITY_INFORMATION 0x00000004
#define PROTECTED_DACL_SECURITY_INFORMATION 0x80000000
#define SE_DACL_PRESENT 0x00000004

typedef void* PSID;
typedef void* PACL;
typedef unsigned long SECURITY_INFORMATION;

typedef struct {
    unsigned char Revision;
    unsigned char Sbz1;
    unsigned short Control;
    PSID Owner;
    PSID Group;
    PACL Sacl;
    PACL Dacl;
} SECURITY_DESCRIPTOR;

typedef struct {
    unsigned long nLength;
    void* lpSecurityDescriptor;
    BOOL bInheritHandle;
} SECURITY_ATTRIBUTES;

unsigned long GetLastError();
BOOL CreateDirectory(LPCTSTR, const SECURITY_ATTRIBUTES*);
BOOL SetFileSecurity(LPCTSTR, SECURITY_INFORMATION, const SECURITY_DESCRIPTOR*);
PSID GetAdminGrpSid();
PACL GetAdminGrpAcl();