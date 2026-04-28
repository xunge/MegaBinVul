#include <ctype.h>
#include <string.h>

typedef struct {
  int endian;
} Header;

typedef struct lua_State lua_State;
typedef double lua_Number;

static void defaultoptions(Header *h);
static size_t optsize(lua_State *L, int opt, const char **fmt);
static size_t gettoalign(size_t pos, Header *h, int opt, size_t size);
static lua_Number getinteger(const char *buff, int endian, int issigned, size_t size);
static void correctbytes(char *b, size_t size, int endian);
static void controloptions(lua_State *L, int opt, const char **fmt, Header *h);