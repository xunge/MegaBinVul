#include <string>
#include <stdexcept>
#include <iostream>

struct lua_State;

class ScriptApiSecurity {
public:
    static bool isSecure(lua_State* L);
};

class ModApiBase {
public:
    static void* getGuiEngine(lua_State* L);
};

class LuaError : public std::runtime_error {
public:
    explicit LuaError(const std::string& msg) : std::runtime_error(msg) {}
};

extern std::ostream errorstream;
extern std::ostream infostream;

std::string script_get_backtrace(lua_State* L);