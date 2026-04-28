#include <stdlib.h>
#include <wchar.h>

typedef struct scheme scheme;
typedef wchar_t gunichar;

struct scheme {
    char *strbuff;
};

static int is_one_of(char *delim, gunichar c);
static gunichar inchar(scheme *sc);
static void backchar(scheme *sc, gunichar c);
static int g_unichar_to_utf8(gunichar c, char *outbuf);