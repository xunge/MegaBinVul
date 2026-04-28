#include <string.h>
#include <regex.h>

typedef struct js_State js_State;
typedef struct js_Regexp js_Regexp;

struct js_Regexp {
    regex_t *prog;
    int flags;
    int last;
};

typedef struct Resub Resub;
typedef struct Resubmatch Resubmatch;

struct Resubmatch {
    const char *sp;
    const char *ep;
};

struct Resub {
    Resubmatch sub[10];
    int nsub;
};

int js_regexec(regex_t *prog, const char *text, Resub *m, int opts);
void js_pushnull(js_State *J);
void js_newarray(js_State *J);
void js_pushstring(js_State *J, const char *v);
void js_setproperty(js_State *J, int idx, const char *name);
void js_pushnumber(js_State *J, double v);
void js_pushlstring(js_State *J, const char *v, int n);
void js_setindex(js_State *J, int idx, int i);
double js_utfptrtoidx(const char *s, const char *p);

#define JS_REGEXP_G 1