#include <stdbool.h>

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Obj Jsi_Obj;

struct Jsi_Value {
    int vt;
    union {
        Jsi_Obj* obj;
    } d;
};

struct Jsi_Obj {
    int ot;
};

#define JSI_VT_NUMBER 1
#define JSI_VT_OBJECT 2
#define JSI_OT_NUMBER 1