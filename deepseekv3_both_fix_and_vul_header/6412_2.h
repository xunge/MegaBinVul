#include <string.h>

typedef struct lua_State lua_State;

typedef struct {
    int resp;
} client;

typedef struct {
    client *lua_client;
} serverStruct;

extern serverStruct server;

extern char *redisProtocolToLuaType(lua_State *lua, char *reply);
extern int string2ll(const char *s, size_t slen, long long *value);