#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef unsigned long DWORD;
typedef int BOOL;
typedef void *PSID;
typedef void PyObject;

#define FALSE 0
#define TRUE 1

typedef struct _ACL {
    unsigned char AclRevision;
    unsigned char Sbz1;
    unsigned short AclSize;
    unsigned short AceCount;
    unsigned short Sbz2;
} ACL, *PACL;

typedef struct _ACCESS_ALLOWED_ACE {
    unsigned char AceType;
    unsigned char AceFlags;
    unsigned short AceSize;
    DWORD Mask;
    DWORD SidStart;
} ACCESS_ALLOWED_ACE;

typedef struct {
    PACL (*GetACL)(void);
    BOOL (*SetACL)(PACL);
} PyACL;

typedef BOOL (*addaceexfunc)(PACL, DWORD, DWORD, DWORD, PSID);
typedef char CHAR;

#define ERROR_ALLOTTED_SPACE_EXCEEDED 0

DWORD GetLastError(void);
size_t GetLengthSid(PSID);
BOOL _ReorderACL(PACL);
void ZeroMemory(void*, size_t);

PyObject* PyErr_Format(PyObject*, const char*, ...);
PyObject* PyWin_SetAPIError(const char*, DWORD);
PyObject* PyWin_SetAPIError(const char*);
int PyWinObject_AsSID(PyObject*, PSID*, BOOL);
void Py_INCREF(PyObject*);

#define PyExc_NotImplementedError ((PyObject*)1)
#define PyExc_OverflowError ((PyObject*)2)
#define PyExc_MemoryError ((PyObject*)3)
#define Py_None ((PyObject*)4)