#include <stdint.h>

typedef unsigned int guint;
typedef int gint;

typedef struct _GObject GObject;
typedef struct _GValue GValue;
typedef struct _GParamSpec GParamSpec;

#define POLKIT_UNIX_PROCESS(object) ((PolkitUnixProcess*)(object))

typedef struct _PolkitUnixProcess PolkitUnixProcess;

enum {
    PROP_PID,
    PROP_UID,
    PROP_START_TIME
};

static inline gint g_value_get_int(const GValue* value) { return 0; }
static inline uint64_t g_value_get_uint64(const GValue* value) { return 0; }
#define g_return_if_fail(expr) do { if (!(expr)) return; } while(0)
#define G_OBJECT_WARN_INVALID_PROPERTY_ID(obj, id, pspec)

void polkit_unix_process_set_pid(PolkitUnixProcess* process, gint pid);
void polkit_unix_process_set_uid(PolkitUnixProcess* process, gint uid);
void polkit_unix_process_set_start_time(PolkitUnixProcess* process, uint64_t start_time);