#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct lua_State lua_State;

class Lua {
private:
    lua_State* L;
public:
    void setParamsTable(lua_State* vm, const char* table_name, const char* query) const;
};

class Utils {
public:
    static void urlDecode(const char* src, char* dest, int dest_len);
    static void purifyHTTPparam(char* param, bool strict, bool allow_newline);
};

class ntop {
public:
    class Trace {
    public:
        void traceEvent(int level, const char* format, ...);
    };
    Trace* getTrace();
};

extern ntop* ntop;

#define TRACE_WARNING 1

extern void purifyHTTPParameter(char *param);
extern void lua_newtable(lua_State* L);
extern void lua_push_str_table_entry(lua_State* vm, const char* key, const char* value);
extern void lua_setglobal(lua_State* L, const char* name);