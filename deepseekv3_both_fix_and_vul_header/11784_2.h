#include <stdint.h>
#include <stddef.h>

typedef struct _PolkitIdentity PolkitIdentity;
typedef int32_t gint;

#define POLKIT_IDENTITY(obj) ((PolkitIdentity*)(obj))
#define POLKIT_TYPE_UNIX_GROUP 1

void* g_object_new(int type, const char* first_property_name, ...);