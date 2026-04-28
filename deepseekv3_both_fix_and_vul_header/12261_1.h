#include <stdint.h>
#include <wchar.h>

typedef unsigned int cmsUInt32Number;
typedef unsigned short cmsUInt16Number;
typedef int cmsBool;

#define cmsERROR_UNKNOWN_EXTENSION 1

struct _cms_typehandler_struct {
    void* ContextID;
};

typedef struct {
    cmsUInt16Number Language;
    cmsUInt16Number Country;
    cmsUInt32Number Len;
    cmsUInt32Number StrW;
} _cmsMLUentry;

typedef struct {
    void* ContextID;
    _cmsMLUentry* Entries;
    cmsUInt32Number UsedEntries;
    cmsUInt32Number AllocatedEntries;
    wchar_t* MemPool;
    cmsUInt32Number PoolSize;
    cmsUInt32Number PoolUsed;
} cmsMLU;

typedef struct {
    cmsUInt32Number Signature;
    cmsUInt32Number Reserved;
} _cmsTagBase;

typedef struct _cms_io_handler cmsIOHANDLER;

cmsMLU* cmsMLUalloc(void* ContextID, cmsUInt32Number n);
void cmsMLUfree(cmsMLU* mlu);
cmsBool _cmsReadUInt32Number(cmsIOHANDLER* io, cmsUInt32Number* n);
cmsBool _cmsReadUInt16Number(cmsIOHANDLER* io, cmsUInt16Number* n);
cmsBool _cmsReadWCharArray(cmsIOHANDLER* io, cmsUInt32Number n, wchar_t* buf);
void* _cmsMalloc(void* ContextID, cmsUInt32Number size);
void cmsSignalError(void* ContextID, cmsUInt32Number ErrorCode, const char *ErrorText);