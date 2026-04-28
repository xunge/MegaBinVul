#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXINTSIZE 16

typedef struct lua_State lua_State;
void luaL_error(lua_State *L, const char *fmt, ...);

// 两个不同版本的getnum函数声明
static int getnum_v1(const char **fmt, int d);
static int getnum_v2(lua_State *L, const char **fmt, int d);