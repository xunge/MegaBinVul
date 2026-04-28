#include <stddef.h>

typedef struct lua_State lua_State;
typedef ptrdiff_t StkId;

#define CSTACKERR 0
#define incXCcalls(L) ((void)0)
#define decXCcalls(L) ((void)0)
#define getCcalls(L) (0)
void luaE_freeCI(lua_State *L);
void luaD_call(lua_State *L, StkId func, int nResults);