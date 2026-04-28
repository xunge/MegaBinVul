#include <ctype.h>
#include <stdlib.h>
#include <stdint.h>

typedef int Jsi_RC;
#define JSI_OK 0

typedef struct Jsi_Tree Jsi_Tree;
typedef struct Jsi_TreeEntry Jsi_TreeEntry;
typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Obj Jsi_Obj;
typedef struct Jsi_Value Jsi_Value;

struct Jsi_TreeEntry {
    struct {
        struct {
            unsigned int dontenum : 1;
            unsigned int isarrlist : 1;
        } bits;
    } f;
};

struct Jsi_Tree {
    struct {
        Jsi_Interp *interp;
    } opts;
};

struct Jsi_Interp {
    uint32_t maxArrayList;
};

struct Jsi_Obj {
    Jsi_Value **arr;
};

int Jsi_ObjArraySizer(Jsi_Interp *interp, Jsi_Obj *obj, int n);
int Jsi_LogError(const char *msg);
void *Jsi_TreeKeyGet(Jsi_TreeEntry *hPtr);
void *Jsi_TreeValueGet(Jsi_TreeEntry *hPtr);