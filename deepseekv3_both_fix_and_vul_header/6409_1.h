typedef char *sds;

struct ldbState {
    int step;
};

struct redisServer {
    int lua_replicate_commands;
};

extern struct ldbState ldb;
extern struct redisServer server;

typedef struct lua_State lua_State;

unsigned long sdslen(const sds s);