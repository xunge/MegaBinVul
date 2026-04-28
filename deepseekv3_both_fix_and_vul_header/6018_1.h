#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define JSI_OPTION_END 0
#define JSI_OK 0
#define JSI_ERROR 1
#define JSI_OPT_BITSET_ENUM (1<<0)
#define JSI_OPT_PASS2 (1<<1)
#define MAX_ARRAY_LIST 1000
#define OPTS_STRUCT 1
#define OPTS_FIELD 2

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Func Jsi_Func;
typedef struct Jsi_OptionTypedef Jsi_OptionTypedef;
typedef struct Jsi_StructSpec Jsi_StructSpec;
typedef struct Jsi_DString Jsi_DString;
typedef struct Jsi_HashEntry Jsi_HashEntry;
typedef struct Jsi_Type Jsi_Type;

typedef int Jsi_RC;
typedef double Jsi_Number;

struct Jsi_OptionTypedef {
    void *extData;
    Jsi_HashEntry *hPtr;
};

struct Jsi_StructSpec {
    int id;
    const char *name;
    const char *help;
    int flags;
    int bits;
    int arrSize;
    void *extData;
    Jsi_Type *type;
    Jsi_HashEntry *hPtr;
};

struct Jsi_DString {
    const char *str;
};

struct Jsi_Interp {
    int maxArrayList;
};

extern int Jsi_GetDouble(Jsi_Interp *interp, const char *str, Jsi_Number *n);
extern int Jsi_GetBool(Jsi_Interp *interp, const char *str, bool *b);
extern int Jsi_GetInt(Jsi_Interp *interp, const char *str, int *n, int base);
extern const char *Jsi_ValueString(Jsi_Interp *interp, Jsi_Value *v, int *len);
extern Jsi_Value *Jsi_ValueNewArray(Jsi_Interp *interp, Jsi_Value **items, int count);
extern Jsi_Value *Jsi_ValueNewStringDup(Jsi_Interp *interp, const char *str);
extern Jsi_Value *Jsi_ValueNewNumber(Jsi_Interp *interp, Jsi_Number n);
extern Jsi_Value *Jsi_ValueNewBoolean(Jsi_Interp *interp, bool b);
extern Jsi_Value *Jsi_ValueNewObj(Jsi_Interp *interp, void *o);
extern Jsi_Value *Jsi_ValueArrayIndex(Jsi_Interp *interp, Jsi_Value *v, int idx);
extern int Jsi_ValueGetLength(Jsi_Interp *interp, Jsi_Value *v);
extern int Jsi_ValueIsArray(Jsi_Interp *interp, Jsi_Value *v);
extern int Jsi_ValueObjLookup(Jsi_Interp *interp, Jsi_Value *v, const char *key, int flags);
extern void Jsi_ValueInsert(Jsi_Interp *interp, Jsi_Value *v, const char *key, Jsi_Value *val, int flags);
extern void Jsi_ValueArraySet(Jsi_Interp *interp, Jsi_Value *v, Jsi_Value *val, int idx);
extern void Jsi_IncrRefCount(Jsi_Interp *interp, Jsi_Value *v);
extern void Jsi_DecrRefCount(Jsi_Interp *interp, Jsi_Value *v);
extern char *Jsi_Strstr(const char *s1, const char *s2);
extern char *Jsi_Strchr(const char *s, int c);
extern size_t Jsi_Strlen(const char *s);
extern char *jsi_TrimStr(char *s);
extern void Jsi_SplitStr(const char *str, int *argc, char ***argv, const char *sep, Jsi_DString *dStr);
extern const char *Jsi_DSValue(Jsi_DString *dStr);
extern void Jsi_DSFree(Jsi_DString *dStr);
extern int Jsi_LogError(const char *fmt, ...);
extern int Jsi_OptionsProcess(Jsi_Interp *interp, void *opts, void *spec, Jsi_Value *val, int flags);
extern const char *Jsi_KeyAdd(Jsi_Interp *interp, const char *str);
extern int Jsi_StrIsAlnum(const char *str);
extern Jsi_Type *Jsi_TypeLookup(Jsi_Interp *interp, const char *name);
extern void Jsi_HashEntryDelete(Jsi_HashEntry *hPtr);
extern int jsi_csInitType(Jsi_Interp *interp);
extern void *jsi_csStructGet(Jsi_Interp *interp, const char *name);
extern int jsi_csSetupStruct(Jsi_Interp *interp, Jsi_StructSpec *sl, Jsi_StructSpec *recs, Jsi_StructSpec *fields, int argc, Jsi_OptionTypedef **st, int arrCnt);
extern Jsi_StructSpec *jsi_csGetStructSpec(void *extData);
extern Jsi_StructSpec *jsi_csGetFieldSpec(void *extData);

extern Jsi_StructSpec StructOptions[];
extern Jsi_StructSpec StructFieldOptions[];

struct Jsi_Type {
    int flags;
};

enum {
    jsi_CTYP_STRUCT = (1<<0),
    jsi_CTYP_ENUM = (1<<1)
};

#define SIGINIT(ptr, type) memset(ptr, 0, sizeof(*ptr)); ptr->id = type