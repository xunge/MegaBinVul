#include <stdint.h>
#include <limits.h>

#define G_OBJECT_CLASS(klass) ((GObjectClass*)klass)
#define G_MAXINT INT_MAX
#define G_MININT INT_MIN
#define G_MAXUINT64 UINT64_MAX
#define G_PARAM_CONSTRUCT (1 << 0)
#define G_PARAM_READWRITE (1 << 1)
#define G_PARAM_STATIC_NAME (1 << 2)
#define G_PARAM_STATIC_BLURB (1 << 3)
#define G_PARAM_STATIC_NICK (1 << 4)

struct _GObjectClass {
    void (*get_property)(void);
    void (*set_property)(void);
    void (*constructed)(void);
};

typedef struct _GObjectClass GObjectClass;
typedef struct _PolkitUnixProcessClass PolkitUnixProcessClass;

enum {
  PROP_PID = 1,
  PROP_UID,
  PROP_START_TIME
};

void polkit_unix_process_get_property(void);
void polkit_unix_process_set_property(void);
void polkit_unix_process_constructed(void);

void* g_object_class_install_property(GObjectClass*, int, void*);
void* g_param_spec_int(const char*, const char*, const char*, int, int, int, int);
void* g_param_spec_uint64(const char*, const char*, const char*, uint64_t, uint64_t, uint64_t, int);