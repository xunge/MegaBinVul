#include <stddef.h>

typedef struct lua_State lua_State;
typedef struct CallInfo CallInfo;
typedef struct TValue *StkId;
typedef struct TValue {
    int dummy;
} TValue;

struct CallInfo {
  union {
    struct {
      int nextraargs;
    } l;
  } u;
  TValue *func;
};

struct lua_State {
  StkId top;
};

#define checkstackp(L,n,p) 
#define setobjs2s(L,x,y) 
#define setnilvalue(x) 
#define s2v(x) ((TValue*)(x))