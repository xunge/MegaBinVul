#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Jsi_DString {
    char *data;
} Jsi_DString;

typedef struct InterpStrEvent {
    struct InterpStrEvent *next;
    void *acfunc;
    void *acdata;
} InterpStrEvent;

typedef struct Jsi_TreeOpts {
    void (*freeHashProc)(void*);
} Jsi_TreeOpts;

typedef struct Jsi_Tree {
    Jsi_TreeOpts opts;
    void *tree;
} Jsi_Tree;

typedef struct Jsi_Obj {
    Jsi_Tree *tree;
} Jsi_Obj;

typedef struct {
    int refCnt;
} Jsi_Value;

typedef struct {
    union {
        struct {
            struct {
                void (*lockHashProc)(void*);
            } opts;
        } *hash;
        struct {
            struct {
                void (*lockTreeProc)(void*);
            } opts;
        } *tree;
    } v;
} Jsi_Map;

typedef struct Jsi_Interp {
    struct {
        void (*initProc)(struct Jsi_Interp*, int);
    } opts;
    void *gsc;
    void *csc;
    void *ps;
    int maxStack;
    void **Stack;
    void **Obj_this;
    void *argv0;
    void *console;
    void *lastSubscriptFail;
    void *nullFuncRet;
    void *codeTbl;
    void *cmdSpecTbl;
    void *funcObjTbl;
    void *funcsTbl;
    void *fileTbl;
    int profileCnt;
    double coverHit;
    double coverAll;
    double startTime;
    double funcSelfTime;
    double cmdSelfTime;
    int funcCallCnt;
    int cmdCallCnt;
    struct {
        int valueAllocCnt;
        int objAllocCnt;
    } *dbPtr;
    struct Jsi_Interp *parent;
    char *name;
    void *lexkeyTbl;
    void *protoTbl;
    int subthread;
    Jsi_Map *strKeyTbl;
    void *thisTbl;
    void *varTbl;
    void *genValueTbl;
    void *genObjTbl;
    void *aliasHash;
    void *GetterValue;
    void *staticFuncsTbl;
    void *breakpointHash;
    struct {
        int numEntries;
    } *preserveTbl;
    char *curDir;
    InterpStrEvent *interpStrEvents;
    void *Mutex;
    void *QMutex;
    Jsi_DString interpEvalQ;
    void *nullFuncArg;
    Jsi_Value *NullValue;
    Jsi_Value *Function_prototype_prototype;
    void *Object_prototype;
    void *regexpTbl;
    void *userdataTbl;
    void *eventTbl;
    void *inopts;
    void *safeWriteDirs;
    void *safeReadDirs;
    void *pkgDirs;
    Jsi_Obj **cleanObjs;
    void *bindTbl;
    int cur_scope;
    void **scopes;
    void *loadTbl;
    void *packageHash;
    void *assocTbl;
    int cleanup;
    int threadCnt;
    int threadShrCnt;
} Jsi_Interp;

typedef struct {
    Jsi_Interp *mainInterp;
    Jsi_Interp *delInterp;
    int threadCnt;
    int threadShrCnt;
} jsiIntData_t;

static jsiIntData_t jsiIntData;

typedef int Jsi_RC;
#define JSI_OK 0

#define SIGASSERT(ptr, type)
#define Jsi_DecrRefCount(interp, obj)
#define Jsi_DecrRefCountIF(interp, obj)
#define Jsi_Free(ptr) free(ptr)
#define Jsi_HashDeleteIF(hash)
#define Jsi_MapDelete(map)
#define Jsi_DSInit(ds) ((ds)->data = NULL)
#define Jsi_DSPrintf(ds, fmt, ...)
#define Jsi_DSValue(ds) ((ds)->data)
#define Jsi_DSFree(ds) free((ds)->data)
#define Jsi_Puts(interp, fd, str, len)
#define Jsi_LogBug(msg)
#define Jsi_MutexDelete(interp, mutex)
#define Jsi_OptionsFree(interp, opts, ptr, flags)
#define _JSI_MEMCLEAR(ptr) memset(ptr, 0, sizeof(*(ptr)))

static void DeleteAllInterps(void) {}
static void jsi_ScopeChainFree(Jsi_Interp *interp, void *gsc) {}
static void jsi_PstateFree(void *ps) {}
static double jsi_GetTimestamp(void) { return 0.0; }
static void jsi_InitFilesys(Jsi_Interp *interp, int flag) {}
static void jsi_InitVfs(Jsi_Interp *interp, int flag) {}
static void jsi_InitCData(Jsi_Interp *interp, int flag) {}
static void Jsi_InitMySql(Jsi_Interp *interp, int flag) {}
static void Jsi_InitZvfs(Jsi_Interp *interp, int flag) {}
static void jsi_ScopeStrsFree(Jsi_Interp *interp, void *scope) {}
static void Jsi_ObjFree(Jsi_Interp *interp, void *obj) {}
static void jsi_DebugDumpValues(Jsi_Interp *interp) {}