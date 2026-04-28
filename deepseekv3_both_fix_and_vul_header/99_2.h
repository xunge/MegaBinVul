#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef union Value {
    struct TString *ts;
} Value;

typedef struct TString {
    size_t len;
    char *str;
} TString;

typedef struct lua_State {
    Value *top;
} lua_State;

typedef Value *StkId;

#define ttisstring(o) ((o)->ts != NULL)
#define cvt2str(o) (0)
#define s2v(o) (o)
#define tostring(L, o) (1)
#define isemptystr(o) ((o)->ts->len == 0)
#define setobjs2s(L, o1, o2) (*(o1) = *(o2))
#define vslen(o) ((o)->ts->len)
#define l_unlikely(x) (x)
#define MAX_SIZE (SIZE_MAX)
#define LUAI_MAXSHORTLEN (40)
#define copy2buff(top, n, buff) (void)0
#define luaS_newlstr(L, s, len) ((TString*)malloc(sizeof(TString)))
#define luaS_createlngstrobj(L, len) ((TString*)malloc(sizeof(TString)))
#define getstr(ts) ((ts)->str)
#define setsvalue2s(L, o, ts) ((o)->ts = (ts))
#define cast_void(x) (void)(x)

void luaT_tryconcatTM(lua_State *L);
void luaG_runerror(lua_State *L, const char *msg);