#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef unsigned long DWORD;
typedef unsigned short USHORT;
typedef int BOOL;
typedef char CHAR;
#define FALSE 0
#define TRUE 1

typedef struct _ACL {
    unsigned char  AclRevision;
    unsigned char  Sbz1;
    USHORT         AclSize;
    USHORT         AceCount;
    USHORT         Sbz2;
} ACL, *PACL;

typedef struct _ACCESS_ALLOWED_ACE {
    unsigned char  AceType;
    unsigned char  AceFlags;
    USHORT         AceSize;
    DWORD          Mask;
    DWORD          SidStart;
} ACCESS_ALLOWED_ACE;

typedef void *PSID;
typedef void PyObject;

DWORD GetLastError();
void ZeroMemory(void* dest, size_t size);
DWORD GetLengthSid(PSID psid);
BOOL _ReorderACL(PACL pacl);

typedef BOOL (*addacefunc)(PACL, DWORD, DWORD, PSID);
typedef struct {
    PACL (*GetACL)(void);
    BOOL (*SetACL)(PACL);
} PyACL;

#define ERROR_ALLOTTED_SPACE_EXCEEDED 0
#define PyExc_NotImplementedError NULL
#define PyExc_OverflowError NULL
#define PyExc_MemoryError NULL
#define Py_None NULL

PyObject* PyErr_Format(PyObject*, const char*, ...);
int PyWinObject_AsSID(PyObject*, PSID*, BOOL);
PyObject* PyWin_SetAPIError(const char*, DWORD);
PyObject* PyWin_SetAPIError(const char*);  // 添加重载版本
void Py_INCREF(PyObject*);