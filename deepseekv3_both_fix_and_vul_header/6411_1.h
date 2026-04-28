typedef struct lua_State lua_State;

char *redisProtocolToLuaType_Int(lua_State *lua, char* reply);
char *redisProtocolToLuaType_Bulk(lua_State *lua, char* reply);
char *redisProtocolToLuaType_Status(lua_State *lua, char* reply);
char *redisProtocolToLuaType_Error(lua_State *lua, char* reply);
char *redisProtocolToLuaType_Aggregate(lua_State *lua, char* reply, char type);
char *redisProtocolToLuaType_Null(lua_State *lua, char* reply);
char *redisProtocolToLuaType_Bool(lua_State *lua, char* reply, char value);
char *redisProtocolToLuaType_Double(lua_State *lua, char* reply);