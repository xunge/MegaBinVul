typedef struct _PolkitUnixProcess {
    int uid;
} PolkitUnixProcess;

#define POLKIT_IS_UNIX_PROCESS(obj) (1)
#define g_return_if_fail(expr) do { if (!(expr)) return; } while (0)
typedef int gint;