#include <stddef.h>

typedef struct js_State js_State;
typedef struct js_Environment js_Environment;

typedef struct {
    int numparams;
    int varlen;
} js_Function;

typedef struct {
    // js_Value members
} js_Value;

extern void jsR_savescope(js_State *J, js_Environment *scope);
extern void js_pop(js_State *J, int n);
extern void js_pushundefined(js_State *J);
extern void jsR_run(js_State *J, js_Function *F);
extern js_Value *stackidx(js_State *J, int idx);
extern void js_pushvalue(js_State *J, js_Value v);
extern void jsR_restorescope(js_State *J);

extern int TOP;
extern int BOT;