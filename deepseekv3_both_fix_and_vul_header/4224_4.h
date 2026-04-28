#include <stddef.h>
#include <stdio.h>

#define MAXINTSIZE 16

typedef struct lua_State lua_State;
void luaL_error(lua_State *L, const char *fmt, ...);

// First version of getnum (used in first optsize)
static int getnum_v1(lua_State *L, const char **fmt, int d);

// Second version of getnum (used in second optsize) 
static int getnum_v2(const char **fmt, int d);