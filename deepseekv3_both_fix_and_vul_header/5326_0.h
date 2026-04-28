#include <stdlib.h>
#include <string.h>

typedef struct js_State js_State;
typedef struct js_Regexp js_Regexp;
typedef struct js_Buffer js_Buffer;
typedef struct Resub Resub;

struct Resub {
    struct {
        const char *sp;
        const char *ep;
    } sub[10];
    int nsub;
};

struct js_Regexp {
    void *prog;
    int flags;
    int last;
};

struct js_Buffer {
    char *s;
    int n;
    int size;
};

extern const char *checkstring(js_State *J, int idx);
extern js_Regexp *js_toregexp(js_State *J, int idx);
extern int js_regexec(void *prog, const char *string, Resub *sub, int flags);
extern int js_iscallable(js_State *J, int idx);
extern void js_copy(js_State *J, int idx);
extern void js_pushundefined(js_State *J);
extern void js_pushlstring(js_State *J, const char *s, int n);
extern void js_pushnumber(js_State *J, double n);
extern void js_call(js_State *J, int n);
extern const char *js_tostring(js_State *J, int idx);
extern void js_putm(js_State *J, js_Buffer **sb, const char *a, const char *b);
extern void js_puts(js_State *J, js_Buffer **sb, const char *s);
extern void js_putc(js_State *J, js_Buffer **sb, int c);
extern void js_pop(js_State *J, int n);
extern int js_try(js_State *J);
extern void js_free(js_State *J, void *ptr);
extern void js_throw(js_State *J);
extern void js_pushstring(js_State *J, const char *v);
extern void js_endtry(js_State *J);

#define JS_REGEXP_G 1
#define REG_NOTBOL 1