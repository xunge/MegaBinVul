#include <stddef.h>

#define LUA_TNIL 0
#define LUA_TBOOLEAN 1
#define LUA_TNUMBER 3
#define LUA_TSTRING 4
#define LUA_TTABLE 5

typedef struct redisObject redisObject;
typedef char *sds;

struct sharedObjectsStruct {
    redisObject *cone;
    redisObject *null[3];
};

extern struct sharedObjectsStruct shared;

typedef struct client {
    int resp;
} client;

struct redisServer {
    client *lua_client;
    int resp;
};

extern struct redisServer server;

typedef struct lua_State lua_State;

int lua_type(lua_State *L, int idx);
const char *lua_tostring(lua_State *L, int idx);
size_t lua_strlen(lua_State *L, int idx);
int lua_toboolean(lua_State *L, int idx);
double lua_tonumber(lua_State *L, int idx);
void lua_pushstring(lua_State *L, const char *s);
void lua_gettable(lua_State *L, int idx);
void lua_pop(lua_State *L, int n);
void lua_pushnil(lua_State *L);
int lua_next(lua_State *L, int idx);
void lua_pushvalue(lua_State *L, int idx);
void lua_pushnumber(lua_State *L, double n);

void addReplyBulkCBuffer(client *c, char *s, size_t len);
void addReply(client *c, redisObject *obj);
void addReplyBool(client *c, int b);
void addReplyLongLong(client *c, long long ll);
void addReplySds(client *c, sds s);
void addReplyDouble(client *c, double d);
void *addReplyDeferredLen(client *c);
void setDeferredMapLen(client *c, void *replylen, int len);
void setDeferredSetLen(client *c, void *replylen, int len);
void setDeferredArrayLen(client *c, void *replylen, int len);
void addReplyNull(client *c);

sds sdsnew(const char *init);
sds sdsempty(void);
sds sdscatprintf(sds s, const char *fmt, ...);
void sdsfree(sds s);
void sdsmapchars(sds s, const char *from, const char *to, size_t setlen);