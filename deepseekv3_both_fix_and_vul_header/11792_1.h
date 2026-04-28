#include <stdlib.h>

typedef struct _PolkitUnixUser PolkitUnixUser;
struct _PolkitUnixUser {
    int uid;
};

#define POLKIT_IS_UNIX_USER(user) (1)
#define g_return_if_fail(expr) do { if (!(expr)) return; } while (0)
typedef int gint;