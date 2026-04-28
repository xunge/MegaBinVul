#include <stddef.h>

typedef struct lua_State lua_State;
typedef struct global_State global_State;
typedef struct UpVal UpVal;

struct lua_State {
    lua_State *twups;
    UpVal *openupval;
};

struct global_State {
    lua_State *twups;
};

struct UpVal {
    struct {
        struct {
            UpVal *next;
        } open;
    } u;
    void *v;
};

#define isblack(x) (0)
#define isgray(x) (0)
#define iswhite(x) (0)
#define markvalue(g, v) ((void)0)
#define lua_assert(x) ((void)0)