#include <stddef.h>

typedef struct js_State js_State;
typedef struct js_Object js_Object;

#define JS_READONLY  0x01
#define JS_DONTENUM  0x02
#define JS_DONTCONF  0x04

void js_pushobject(js_State *J, js_Object *obj);
int js_hasproperty(js_State *J, int idx, const char *name);
int js_toboolean(js_State *J, int idx);
void js_pop(js_State *J, int n);
void js_setproperty(js_State *J, int idx, const char *name);
void js_typeerror(js_State *J, const char *msg);
void js_pushundefined(js_State *J);
void js_defaccessor(js_State *J, int idx, const char *name, int atts);