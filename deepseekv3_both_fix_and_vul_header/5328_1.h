#include <stddef.h>

typedef struct js_State js_State;

typedef struct Resub {
    struct {
        const char *sp;
        const char *ep;
    } sub[10];
} Resub;

typedef struct js_Regexp {
    void *prog;
} js_Regexp;

const char *checkstring(js_State *J, int idx);
int js_isregexp(js_State *J, int idx);
int js_isundefined(js_State *J, int idx);
void js_copy(js_State *J, int idx);
void js_newregexp(js_State *J, const char *pattern, int flags);
js_Regexp *js_toregexp(js_State *J, int idx);
int js_regexec(void *prog, const char *string, Resub *sub, int eflags);
double js_pushnumber(js_State *J, double n);
const char *js_tostring(js_State *J, int idx);
double js_utfptrtoidx(const char *s, const char *p);