#include <string.h>

typedef struct js_State js_State;

struct Resubmatch {
    const char *sp;
    const char *ep;
};

struct Resub {
    struct Resubmatch sub[10];
};

struct js_Regexp {
    void *prog;
    int flags;
    int last;
};

extern const char *checkstring(js_State *J, int idx);
extern int js_isregexp(js_State *J, int idx);
extern void js_copy(js_State *J, int idx);
extern int js_isundefined(js_State *J, int idx);
extern void js_newregexp(js_State *J, const char *pattern, int flags);
extern const char *js_tostring(js_State *J, int idx);
extern struct js_Regexp *js_toregexp(js_State *J, int idx);
extern void js_RegExp_prototype_exec(js_State *J, struct js_Regexp *re, const char *text);
extern int js_regexec(void *prog, const char *string, struct Resub *sub, int flags);
extern void js_newarray(js_State *J);
extern void js_pushlstring(js_State *J, const char *str, int len);
extern void js_setindex(js_State *J, int idx, int i);
extern void js_pop(js_State *J, int n);
extern void js_pushnull(js_State *J);

#define JS_REGEXP_G 1
#define REG_NOTBOL 1

typedef struct js_Regexp js_Regexp;
typedef struct Resub Resub;