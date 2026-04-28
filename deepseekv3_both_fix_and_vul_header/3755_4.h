#include <stddef.h>

#define BASIC_STACK_SIZE 20
#define LUAI_MAXSTACK 1000000
#define EXTRA_STACK 200

typedef struct lua_State {
    int stacksize;
} lua_State;

int stackinuse(lua_State *L);
void luaD_reallocstack(lua_State *L, int newsize, int raiseerror);
void condmovestack(lua_State *L, int, int);
void luaE_shrinkCI(lua_State *L);

#define condmovestack(L, a, b) condmovestack(L, 0, 0)