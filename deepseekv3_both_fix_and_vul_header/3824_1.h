#include <stddef.h>

typedef struct TValue TValue;
typedef struct Proto Proto;
typedef struct LClosure LClosure;
typedef union CLValue CLValue;

union CLValue {
    struct LClosure *cl;
};

struct TValue {
    CLValue value;
};

struct Proto {
    unsigned char is_vararg;
};

struct LClosure {
    struct Proto *p;
};

struct CallInfo {
    TValue *func;
    union {
        struct {
            int nextraargs;
        } l;
    } u;
};

typedef struct CallInfo CallInfo;
typedef TValue* StkId;

#define s2v(o) ((TValue*)(o))
#define clLvalue(o) ((o)->value.cl)