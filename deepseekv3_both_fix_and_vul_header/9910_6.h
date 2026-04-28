#include <stdint.h>
#include <string.h>

typedef struct _MonoType MonoType;
typedef struct _MonoClass MonoClass;
typedef struct _MonoVTable MonoVTable;
typedef struct _MonoArray MonoArray;
typedef struct _MonoClassField MonoClassField;
typedef struct _MonoException MonoException;

struct _MonoType {
    int type;
    int attrs;
};

struct _MonoClass {
    MonoType byval_arg;
    MonoClass* element_class;
    int has_references;
};

struct _MonoVTable {
    MonoClass* klass;
};

struct _MonoArray {
    struct {
        MonoVTable* vtable;
    } obj;
    int max_length;
};

struct _MonoClassField {
    MonoType* type;
};

#define MONO_TYPE_IS_REFERENCE(type) 0
#define MONO_TYPE_VALUETYPE 0
#define FIELD_ATTRIBUTE_HAS_FIELD_RVA 0
#define G_BYTE_ORDER 0
#define G_LITTLE_ENDIAN 0
#define MONO_TYPE_CHAR 0
#define MONO_TYPE_I2 0
#define MONO_TYPE_U2 0
#define MONO_TYPE_I4 0
#define MONO_TYPE_U4 0
#define MONO_TYPE_R4 0
#define MONO_TYPE_I8 0
#define MONO_TYPE_U8 0
#define MONO_TYPE_R8 0
#define ARM_FPU_FPA 0

typedef uint32_t guint32;
typedef int gint;

static guint32 mono_array_element_size(MonoClass* klass) { return 0; }
static MonoType* mono_type_get_underlying_type(MonoType* type) { return NULL; }
static MonoException* mono_get_exception_argument(const char* arg, const char* msg) { return NULL; }
static void mono_raise_exception(MonoException* exc) {}
static const char* mono_field_get_data(MonoClassField* field) { return NULL; }
static int mono_type_size(MonoType* type, int* align) { return 0; }
static void* mono_array_addr_with_type(MonoArray* array, int type, int index) { return NULL; }
#define mono_array_addr(array, type, index) mono_array_addr_with_type(array, 0, index)
static MonoClass* mono_type_get_class(MonoType* type) { return NULL; }
static uint16_t read16(const void* src) { return 0; }
static uint32_t read32(const void* src) { return 0; }
static uint64_t read64(const void* src) { return 0; }
static void readr8(double* dst, double* src) {}