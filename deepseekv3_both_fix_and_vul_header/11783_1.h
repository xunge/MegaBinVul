#include <stdlib.h>

typedef struct _PolkitUnixGroup PolkitUnixGroup;
struct _PolkitUnixGroup {
    int gid;
};

#define POLKIT_IS_UNIX_GROUP(group) (1)
#define g_return_if_fail(expr) do { if (!(expr)) return; } while (0)
typedef int gint;