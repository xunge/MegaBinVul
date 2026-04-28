#include <sys/types.h>
#include <time.h>

typedef struct _GObject GObject;
typedef struct _GObjectClass GObjectClass;
typedef struct _GError GError;

struct _GObject {
    void *g_type_instance;
    unsigned int ref_count;
    void *qdata;
};

struct _GObjectClass {
    void *g_type_class;
    void (*constructed)(GObject *object);
};

typedef struct _PolkitUnixProcess PolkitUnixProcess;
typedef struct _PolkitUnixProcessClass PolkitUnixProcessClass;

struct _PolkitUnixProcess {
    GObject parent_instance;
    pid_t pid;
    uid_t uid;
    time_t start_time;
};

struct _PolkitUnixProcessClass {
    GObjectClass parent_class;
};

#define POLKIT_UNIX_PROCESS(object) ((PolkitUnixProcess*)(object))
#define G_OBJECT_CLASS(class) ((GObjectClass*)(class))

extern time_t get_start_time_for_pid(pid_t pid, GError **error);
extern uid_t _polkit_unix_process_get_owner(PolkitUnixProcess *process, GError **error);
extern void g_error_free(GError *error);
extern GObjectClass *polkit_unix_process_parent_class;