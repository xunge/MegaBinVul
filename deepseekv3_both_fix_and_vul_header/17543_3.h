extern "C" {
    struct lua_State;
    void lua_pushcfunction(lua_State* L, int (*f)(lua_State*));
    void lua_setglobal(lua_State* L, const char* name);
    void lua_pushnil(lua_State* L);
    void lua_register(lua_State* L, const char* name, int (*f)(lua_State*));
}

extern lua_State* _state;
extern bool managed_vm;

int lua_loadstring(lua_State* L);
int _clua_loadfile(lua_State* L);
int _clua_dofile(lua_State* L);
int _clua_require(lua_State* L);
int _clua_guarded_pcall(lua_State* L);

void cluaopen_kills(lua_State* L);
void cluaopen_you(lua_State* L);
void cluaopen_item(lua_State* L);
void cluaopen_food(lua_State* L);
void cluaopen_crawl(lua_State* L);
void cluaopen_file(lua_State* L);
void cluaopen_moninf(lua_State* L);
void cluaopen_options(lua_State* L);
void cluaopen_travel(lua_State* L);
void cluaopen_view(lua_State* L);
void cluaopen_spells(lua_State* L);
void cluaopen_globals(lua_State* L);

class lua_stack_cleaner {
public:
    lua_stack_cleaner(lua_State* L);
    ~lua_stack_cleaner();
};

class CLua {
public:
    lua_State* state();
    void init_libraries();
    void execfile(const char* file, bool trusted, bool warn);
    void execstring(const char* str, const char* chunkname);
};