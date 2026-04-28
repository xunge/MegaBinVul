#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef int BOOL;
typedef char CHAR;
typedef unsigned char BYTE;

#define FALSE 0
#define ERROR_ALLOTTED_SPACE_EXCEEDED 0x000005A0
#define USHRT_MAX 65535

typedef struct _ACE_HEADER {
    BYTE AceType;
    BYTE AceFlags;
    WORD AceSize;
} ACE_HEADER;

typedef struct _ACL {
    BYTE AclRevision;
    BYTE Sbz1;
    WORD AclSize;
    WORD AceCount;
    WORD Sbz2;
} ACL, *PACL;

typedef struct _GUID {
    DWORD Data1;
    WORD Data2;
    WORD Data3;
    BYTE Data4[8];
} GUID;

typedef struct _ACCESS_ALLOWED_OBJECT_ACE {
    ACE_HEADER Header;
    DWORD Mask;
    DWORD Flags;
    GUID ObjectType;
    GUID InheritedObjectType;
    DWORD SidStart;
} ACCESS_ALLOWED_OBJECT_ACE;

typedef void *PSID;
typedef void *PyObject;

typedef struct {
    PACL (*GetACL)();
    BOOL (*SetACL)(PACL);
} PyACL;

typedef BOOL (*addobjectacefunc)(PACL, DWORD, DWORD, DWORD, GUID*, GUID*, PSID);

#define Py_None ((PyObject*)0)
#define PyExc_NotImplementedError ((PyObject*)0)
#define PyExc_MemoryError ((PyObject*)0)
#define PyExc_OverflowError ((PyObject*)0)

PyObject* PyErr_Format(PyObject*, const char*, ...);
void Py_INCREF(PyObject*);
int PyWinObject_AsIID(PyObject*, GUID*);
int PyWinObject_AsSID(PyObject*, PSID*, BOOL);
PyObject* PyWin_SetAPIError(const char*, DWORD);
PyObject* PyWin_SetAPIError(const char*);
DWORD GetLastError();
DWORD GetLengthSid(PSID);
BOOL _ReorderACL(PACL);
void ZeroMemory(void*, size_t);