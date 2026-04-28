typedef struct lua_State lua_State;
typedef struct wslua_ops {
    void (*browser_open_data_file)(const char*);
} wslua_ops;

#define WSLUA_FUNCTION int
#define WSLUA_ERROR(func, msg) 

extern wslua_ops* ops;
extern const char* luaL_checkstring(lua_State* L, int idx);