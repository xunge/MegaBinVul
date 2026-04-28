#include <stddef.h>

typedef struct Jsi_Interp Jsi_Interp;
typedef struct Jsi_Value Jsi_Value;
typedef struct Jsi_Func Jsi_Func;

typedef enum Jsi_RC {
    JSI_OK
} Jsi_RC;

typedef double Jsi_Number;

enum Jsi_ObjType {
    JSI_OT_NUMBER
};

struct Jsi_Value {
    union {
        Jsi_Number num;
        struct {
            enum Jsi_ObjType ot;
            union {
                Jsi_Number num;
            } d;
        } *obj;
    } d;
};