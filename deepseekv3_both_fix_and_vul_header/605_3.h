#include <assert.h>
#include <stddef.h>

typedef struct lua_State lua_State;
typedef int lua_KContext;

struct ssh_userdata {
    void *session;
    int sp[1];
};

#define SSH2_UDATA "ssh2"
#define LIBSSH2_ERROR_EAGAIN -37
#define LUA_OK 0

int libssh2_session_handshake(void *session, int sock);
void libssh2_session_free(void *session);

void *nseU_checkudata(lua_State *L, int index, const char *tname, const char *type);
int luaL_error(lua_State *L, const char *fmt, ...);
int lua_gettop(lua_State *L);
int lua_status(lua_State *L);
void luaL_getmetafield(lua_State *L, int idx, const char *field);
void lua_pushvalue(lua_State *L, int idx);
void lua_callk(lua_State *L, int nargs, int nresults, lua_KContext ctx, int (*k)(lua_State*, int, lua_KContext));
void lua_settop(lua_State *L, int idx);