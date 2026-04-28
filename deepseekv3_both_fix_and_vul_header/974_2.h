#include <stdlib.h>
#include <search.h>

typedef int Jsi_RC;

typedef struct Jsi_Interp {
    int deleting;
} Jsi_Interp;

typedef struct Jsi_Value {
    int vt;
    union {
        struct Jsi_Obj *obj;
    } d;
} Jsi_Value;

typedef struct Jsi_Obj {
    int arrCnt;
    int modifying;
    Jsi_Value **arr;
} Jsi_Obj;

typedef struct Jsi_Func Jsi_Func;

typedef struct SortInfo {
    Jsi_Interp *interp;
    int flags;
    int mode;
    int unique;
    Jsi_Value *compare;
} SortInfo;

enum {
    JSI_VT_OBJECT,
    JSI_VT_STRING
};

enum {
    JSI_OT_OBJECT,
    JSI_OT_FUNCTION
};

enum {
    JSI_SORT_DESCEND,
    JSI_SORT_DICT,
    JSI_SORT_NOCASE
};

#define JSI_OK 0
#define JSI_ERROR 1

extern int Jsi_ObjIsArray(Jsi_Interp *interp, Jsi_Obj *obj);
extern Jsi_Value* Jsi_ValueArrayIndex(Jsi_Interp *interp, Jsi_Value *args, int index);
extern int Jsi_ValueIsObjType(Jsi_Interp *interp, Jsi_Value *v, int type);
extern int Jsi_OptionsProcess(Jsi_Interp *interp, void *opts, SortInfo *si, Jsi_Value *arg, int flags);
extern void Jsi_ObjListifyArray(Jsi_Interp *interp, Jsi_Obj *obj);
extern void Jsi_DecrRefCount(Jsi_Interp *interp, Jsi_Value *v);
extern void Jsi_OptionsFree(Jsi_Interp *interp, void *opts, SortInfo *si, int flags);
extern Jsi_Value* Jsi_ValueMakeObject(Jsi_Interp *interp, Jsi_Value *v, Jsi_Obj *obj);
extern void Jsi_ValueReplace(Jsi_Interp *interp, Jsi_Value **ret, Jsi_Value *v);
extern int Jsi_LogError(const char *format, ...);

static void* jsi_ArraySortOptions;
static SortInfo* curSortInfo;

#ifdef NO_QSORT_R
static int SortSubCmd(const void *a, const void *b) {
    return 0;
}
#else
#ifdef __WIN32
static int SortSubCmd(void *context, const void *a, const void *b) {
    return 0;
}
#else
static int SortSubCmd(const void *a, const void *b, void *context) {
    return 0;
}
#endif
#endif