#include <stdint.h>
#include <stddef.h>

typedef struct lua_State lua_State;
typedef struct GCfunc GCfunc;
typedef struct GCproto GCproto;
typedef struct GCstr GCstr;
typedef struct GCtab GCtab;
typedef struct TValue TValue;
typedef struct lj_Debug lj_Debug;

#define LJ_TFUNC 0
#define PROTO_VARARG (1<<0)

typedef uint32_t BCLine;
typedef uint32_t MSize;

#define tvisfunc(o) (0)
#define funcV(o) (NULL)
#define setfuncV(L,o,f) (void)0
#define setboolV(o,b) (void)0
#define settabV(L,o,t) (void)0
#define setnilV(o) (void)0
#define incr_top(L) (void)0
#define lua_assert(c) (void)0
#define api_check(L,c) (void)0
#define tvref(r) (NULL)
#define frame_func(f) (NULL)
#define isluafunc(f) (0)
#define funcproto(f) (NULL)
#define proto_chunkname(p) (NULL)
#define strdata(s) (NULL)
#define lj_debug_shortname(b,n,l) (void)0
#define debug_frameline(L,f,n) (0)
#define lj_debug_funcname(L,f,n) (NULL)
#define lj_tab_new(L,a,b) (NULL)
#define proto_lineinfo(p) (NULL)
#define lj_tab_setint(L,t,k) (NULL)

struct lj_Debug {
  const char *source;
  char short_src[4];
  int linedefined;
  int lastlinedefined;
  const char *what;
  int currentline;
  int nups;
  int nparams;
  int isvararg;
  const char *namewhat;
  const char *name;
  uint32_t i_ci;
};

struct GCproto {
  BCLine firstline;
  int numline;
  MSize sizebc;
  int numparams;
  uint8_t flags;
};

struct GCfunc {
  struct {
    uint8_t gct;
    uint8_t nupvalues;
  } c;
};

struct GCtab {};

struct GCstr {
  const char *data;
};

struct TValue {};

struct lua_State {
  TValue *top;
  TValue *stack;
  TValue *maxstack;
};