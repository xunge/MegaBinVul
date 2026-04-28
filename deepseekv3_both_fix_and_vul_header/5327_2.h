#include <string.h>
#include <limits.h>

typedef struct Resub {
    struct {
        const char *sp;
        const char *ep;
    } sub[10];
    int nsub;
} Resub;

typedef struct js_State js_State;

struct js_Regexp {
    void *prog;
};

typedef struct js_Regexp js_Regexp;

extern const char *checkstring(js_State *J, int idx);
extern struct js_Regexp *js_toregexp(js_State *J, int idx);
extern int js_isdefined(js_State *J, int idx);
extern int js_tointeger(js_State *J, int idx);
extern void js_newarray(js_State *J);
extern void js_pushliteral(js_State *J, const char *s);
extern void js_setindex(js_State *J, int idx, int n);
extern int js_regexec(void *prog, const char *string, Resub *sub, int flags);
extern void js_pushlstring(js_State *J, const char *s, int n);
extern void js_pushstring(js_State *J, const char *s);

#define REG_NOTBOL 1