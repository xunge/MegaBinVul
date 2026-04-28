#include <stdlib.h>
#include <string.h>

typedef struct _MonoObject MonoObject;
typedef struct _MonoVTable MonoVTable;
typedef struct _MonoClass MonoClass;
typedef struct _MonoGenericClass MonoGenericClass;
typedef struct _MonoGenericInst MonoGenericInst;
typedef struct _MonoImage MonoImage;
typedef struct _MonoDynamicImage MonoDynamicImage;
typedef struct _MonoMethod MonoMethod;
typedef struct _MonoMethodInflated MonoMethodInflated;
typedef struct _MonoMethodSignature MonoMethodSignature;
typedef struct _MonoReflectionMethod MonoReflectionMethod;
typedef struct _MonoReflectionMethodBuilder MonoReflectionMethodBuilder;
typedef struct _MonoReflectionTypeBuilder MonoReflectionTypeBuilder;
typedef struct _MonoReflectionType MonoReflectionType;
typedef struct _MonoType MonoType;
typedef struct _MonoArray MonoArray;

struct _MonoObject {
    MonoVTable *vtable;
};

struct _MonoVTable {
    MonoClass *klass;
};

struct _MonoClass {
    char *name;
    MonoGenericClass *generic_class;
    MonoImage *image;
};

struct _MonoGenericClass {
    struct {
        MonoGenericInst *class_inst;
        MonoGenericInst *method_inst;
    } context;
};

typedef struct {
    MonoGenericInst *class_inst;
    MonoGenericInst *method_inst;
} MonoGenericContext;

struct _MonoImage {
    int dynamic;
};

struct _MonoMethod {
    MonoClass *klass;
    int is_inflated;
    MonoMethodSignature *signature;
};

struct _MonoMethodInflated {
    MonoMethod *declaring;
};

struct _MonoMethodSignature {
    int generic_param_count;
};

struct _MonoReflectionMethod {
    MonoObject object;
    MonoMethod *method;
};

struct _MonoReflectionMethodBuilder {
    struct _MonoReflectionMethod parent;
    void *type;
};

struct _MonoReflectionTypeBuilder {
    MonoObject object;
};

#define MONO_ARCH_SAVE_REGS
#define DISABLE_REFLECTION_EMIT
#define g_assert_not_reached() abort()
#define g_new0(type, size) calloc(size, sizeof(type))
#define g_free(ptr) free(ptr)
#define mono_array_length(arr) 0
#define mono_array_get(arr, type, idx) NULL
#define mono_method_signature(method) ((MonoMethodSignature*)0)
#define mono_reflection_type_get_handle(type) NULL
#define mono_metadata_get_generic_inst(count, argv) NULL
#define mono_class_inflate_generic_method(method, context) NULL
#define mono_method_get_object(domain, method, error) NULL
#define mono_object_domain(obj) NULL
#define mono_loader_lock()
#define mono_loader_unlock()
#define mono_g_hash_table_insert(hash, key, value)
#define mono_raise_exception(exception)
#define mono_get_exception_argument(arg1, arg2) NULL
#define mono_verifier_is_method_valid_generic_instantiation(method) 1
#define mono_class_from_mono_type(type) NULL