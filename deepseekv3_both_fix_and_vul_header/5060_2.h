#include <stddef.h>

typedef struct lua_State lua_State;
typedef struct Proto Proto;
typedef struct UpVal UpVal;

typedef union {
    struct {
        void *p;
        int tt;
    } gc;
} TValue;

typedef TValue *StkId;

typedef struct LClosure {
    struct Proto *p;
    UpVal *upvals[1];
} LClosure;

#define ttisLclosure(o) (1)
#define clLvalue(o) ((LClosure*)(o))
#define api_check(L, cond, msg) ((void)0)

static StkId index2addr(lua_State *L, int idx) { return NULL; }