#include <stdbool.h>
#include <string.h>

typedef bool gboolean;
#define TRUE true
#define FALSE false

typedef struct _MonoObject {
    void *dummy;
} MonoObject;

typedef struct _MonoClass MonoClass;
typedef struct _MonoVTable MonoVTable;

typedef struct {
    MonoVTable *vtable;
    MonoClass *klass;
} MonoObjectBase;

typedef struct {
    MonoObjectBase obj;
    void *bounds;
} MonoArray;

typedef struct _MonoClass {
    int rank;
    MonoClass *element_class;
    bool valuetype;
    bool enumtype;
    bool has_references;
} MonoClass;

typedef struct _MonoVTable {
    MonoClass *klass;
} MonoVTable;

typedef struct {
    MonoClass *object_class;
} MonoDefaults;

extern MonoDefaults mono_defaults;
extern void MONO_ARCH_SAVE_REGS;

unsigned int mono_array_length(MonoArray *array);
int mono_array_element_size(MonoClass *klass);
void *mono_array_addr_with_size(MonoArray *array, int size, int idx);
#define mono_array_get(array, type, idx) ((type*)mono_array_addr_with_size((array), sizeof(type), (idx)))
gboolean mono_object_isinst(MonoObject *obj, MonoClass *klass);
void mono_value_copy(void *dest, void *src, MonoClass *klass);
void mono_value_copy_array(MonoArray *dest, int dest_idx, void *src, int length);
void mono_array_memcpy_refs(MonoArray *dest, int dest_idx, MonoArray *src, int src_idx, int length);
gboolean mono_class_is_subclass_of(MonoClass *child, MonoClass *parent, gboolean check_interfaces);