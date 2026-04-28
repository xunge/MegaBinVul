#include <stddef.h>

#define LUA_OK 0

typedef struct lua_State lua_State;
typedef struct global_State global_State;

#define G(L) ((L)->l_G)

struct lua_State {
    global_State *l_G;
    void *stack;
    void *ci;
    int nci;
    int stacksize;
    lua_State *twups;
    void *errorJmp;
    void *hook;
    int hookmask;
    int basehookcount;
    int allowhook;
    void *openupval;
    int status;
    int errfunc;
    int oldpc;
};

void resethookcount(lua_State *L);