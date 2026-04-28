typedef int gint;
typedef struct _GError GError;
typedef struct _PolkitUnixProcess PolkitUnixProcess;

gint _polkit_unix_process_get_owner(PolkitUnixProcess *process, GError **error);