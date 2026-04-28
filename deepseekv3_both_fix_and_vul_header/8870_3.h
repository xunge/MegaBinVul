#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_INTERFACE_NAME_LEN 64
#define CONST_HTTP_CONN "HTTP_CONN"
#define CONST_ALLOWED_NETS "ALLOWED_NETS"
#define CONST_ALLOWED_IFNAME "ALLOWED_IFNAME"
#define CONST_STR_USER_ALLOWED_IFNAME "ntopng.user.%s.allowed_ifname"
#define CONST_LUA_OK 0
#define TRACE_WARNING 1
#define PAGE_ERROR "error"
#define NTOPNG_PRO

struct mg_connection;
struct mg_request_info {
    const char *query_string;
    const char *uri;
};
struct AddressTree {
    void addAddresses(const char*);
};
struct lua_State;

extern lua_State *L;

void lua_register_classes(lua_State*, bool);
void lua_push_str_table_entry(lua_State*, const char*, const char*);
void purifyHTTPParameter(char*);
char* http_decode(const char*);
int send_error(struct mg_connection*, int, const char*, const char*, const char*, const char*);
void setInterface(const char*);
char* mg_get_header(struct mg_connection*, const char*);
void mg_get_cookie(struct mg_connection*, const char*, char*, size_t);
int luaL_dofile(lua_State*, const char*);
void luaL_openlibs(lua_State*);
void lua_pushlightuserdata(lua_State*, void*);
void lua_setglobal(lua_State*, const char*);
void lua_newtable(lua_State*);
const char* lua_tostring(lua_State*, int);
int __ntop_lua_handlefile(lua_State*, const char*, bool);

class Lua {
public:
    static int handle_script_request(struct mg_connection *conn,
                                   const struct mg_request_info *request_info,
                                   char *script_path);
};

class Utils {
public:
    static void urlDecode(const char *src, char *dst, size_t dst_len);
    static void purifyHTTPparam(char *param, bool strict, bool allow_spaces);
};

class ntopng {
public:
    class Redis {
    public:
        int get(const char *key, char *value, size_t size);
        int delKey(const char *key);
    };
    
    class Trace {
    public:
        void traceEvent(int level, const char *format, ...);
    };
    
    class Pro {
    public:
        bool has_valid_license();
    };
    
    Redis *getRedis();
    Trace *getTrace();
    Pro *getPro();
};

extern ntopng *ntop;