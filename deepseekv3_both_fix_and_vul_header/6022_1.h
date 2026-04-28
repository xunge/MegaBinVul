#include <ctype.h>
#include <stdlib.h>

typedef struct Jsi_Tree Jsi_Tree;
typedef struct Jsi_TreeEntry Jsi_TreeEntry;
typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Obj Jsi_Obj;
typedef struct Jsi_Value Jsi_Value;

typedef enum Jsi_RC {
    JSI_OK,
    JSI_ERROR
} Jsi_RC;

struct Jsi_Tree {
    struct {
        Jsi_Interp *interp;
    } opts;
};

struct Jsi_TreeEntry {
    union {
        struct {
            unsigned int dontenum : 1;
            unsigned int isarrlist : 1;
        } bits;
    } f;
};

struct Jsi_Interp {
    int maxArrayList;
};

struct Jsi_Obj {
    Jsi_Value **arr;
};

Jsi_RC Jsi_LogError(const char *msg);
int Jsi_ObjArraySizer(Jsi_Interp *interp, Jsi_Obj *obj, int n);
void *Jsi_TreeKeyGet(Jsi_TreeEntry *hPtr);
void *Jsi_TreeValueGet(Jsi_TreeEntry *hPtr);