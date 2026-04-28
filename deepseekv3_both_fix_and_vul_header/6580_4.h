#include <stddef.h>

#define MAX_LINE_LENGTH 4096

typedef struct FILE_T {
    /* 定义FILE_T结构体需要的成员 */
    int fd;  // 示例成员，实际应根据需要定义
} FILE_T;

typedef char gchar;
typedef long long gint64;
typedef int gint;

typedef struct lua_State lua_State;

gint64 file_tell(FILE_T ft);
gchar* file_gets(gchar *s, gint size, FILE_T ft);

void lua_pushnil(lua_State *L);
void lua_pushlstring(lua_State *L, const char *s, size_t l);