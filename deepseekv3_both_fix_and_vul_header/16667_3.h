typedef struct lua_State lua_State;
#define WSLUA_FUNCTION int

typedef struct {
    void (*browser_open_url)(const char*);
} wslua_ops_t;

extern wslua_ops_t* ops;

#define WSLUA_ERROR(func, msg) return 0
#define luaL_checkstring(L, n) ((const char*)0)
#define luaL_error(L, msg) 0