#include <stddef.h>

typedef struct lua_State lua_State;

typedef struct mp_buf {
    char *b;
    size_t len, free;
} mp_buf;

void mp_encode_array(lua_State *L, mp_buf *buf, size_t len);
void mp_encode_lua_type(lua_State *L, mp_buf *buf, int level);