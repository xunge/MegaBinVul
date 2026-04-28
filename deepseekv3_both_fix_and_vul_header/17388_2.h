#include <stddef.h>

typedef struct lua_State lua_State;

typedef struct mp_buf {
    unsigned char *b;
    size_t len, free;
} mp_buf;

mp_buf *mp_buf_new(lua_State *L);
void mp_buf_free(lua_State *L, mp_buf *buf);
void mp_encode_lua_type(lua_State *L, mp_buf *buf, int level);