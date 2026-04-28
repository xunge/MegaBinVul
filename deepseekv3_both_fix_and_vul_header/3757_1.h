#include <stddef.h>
#include <assert.h>

typedef struct lua_State lua_State;
typedef struct CallInfo CallInfo;
typedef struct Proto Proto;
typedef struct TValue TValue;

#define cast_int(x) (int)((ptrdiff_t)(x))
#define checkstackGC(L,n) 
#define setobjs2s(L,x,y) 
#define setnilvalue(x) 
#define s2v(x) ((TValue*)(x))
#define lua_assert(x) assert(x)

struct lua_State {
    TValue *top;
    TValue *stack_last;
};

struct CallInfo {
    union {
        struct {
            int nextraargs;
        } l;
    } u;
    TValue *func;
    TValue *top;
};

struct Proto {
    int maxstacksize;
};

struct TValue {
    int tt_;
};