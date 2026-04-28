#include <stdlib.h>
#include <stdint.h>

typedef int32_t gint;
typedef struct _GObject GObject;
typedef struct _PolkitIdentity PolkitIdentity;

#define POLKIT_IDENTITY(obj) ((PolkitIdentity*)obj)
#define POLKIT_TYPE_UNIX_USER 0

GObject* g_object_new(int type, const char* first_property_name, ...);