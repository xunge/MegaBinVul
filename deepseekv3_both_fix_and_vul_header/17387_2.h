#include <assert.h>
#include <limits.h>
#include <stddef.h>

typedef struct mp_cur {
    unsigned char *p;
    size_t left;
    int err;
} mp_cur;

typedef struct lua_State lua_State;

void mp_decode_to_lua_type(lua_State *L, mp_cur *c);