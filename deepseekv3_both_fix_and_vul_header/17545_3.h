extern void* _state;
extern bool managed_vm;

int lua_loadstring(void* L);
int _clua_loadfile(void* L);
int _clua_dofile(void* L);
int _clua_require(void* L);
int _clua_guarded_pcall(void* L);

void cluaopen_kills(void* ls);
void cluaopen_you(void* ls);
void cluaopen_item(void* ls);
void cluaopen_food(void* ls);
void cluaopen_crawl(void* ls);
void cluaopen_file(void* ls);
void cluaopen_moninf(void* ls);
void cluaopen_options(void* ls);
void cluaopen_travel(void* ls);
void cluaopen_view(void* ls);
void cluaopen_spells(void* ls);
void cluaopen_globals(void* ls);

void lua_pushcfunction(void* L, int (*func)(void*));
void lua_setglobal(void* L, const char* name);
void lua_register(void* L, const char* name, int (*func)(void*));

class lua_stack_cleaner {
public:
    lua_stack_cleaner(void* L);
    ~lua_stack_cleaner();
};

class CLua {
public:
    void* state();
    void init_libraries();
    void execfile(const char* file, bool trusted, bool must_exist);
    void execstring(const char* str, const char* chunkname);
};