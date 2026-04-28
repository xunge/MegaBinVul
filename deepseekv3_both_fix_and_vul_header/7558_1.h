#include <assert.h>

typedef struct TString TString;
typedef struct FuncState FuncState;

typedef struct LexState {
    FuncState *fs;
    TString *envn;
} LexState;

typedef struct expdesc {
    int k;
} expdesc;

enum {
    VVOID
};

#define lua_assert assert

static void singlevaraux(FuncState *fs, TString *varname, expdesc *var, int flag);
static TString *str_checkname(LexState *ls);
static void codestring(expdesc *e, TString *s);
static void luaK_indexed(FuncState *fs, expdesc *t, expdesc *k);