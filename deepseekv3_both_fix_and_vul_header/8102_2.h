#include <stdlib.h>
#include <string.h>

typedef struct _zend_object {
    void *properties;
    void *ce;
} zend_object;

typedef struct _zend_class_entry {
    char *name;
} zend_class_entry;

typedef struct _zend_object_value {
    unsigned int handle;
    void *handlers;
} zend_object_value;

typedef struct _zend_object_handlers {
    int offset;
    void *clone_obj;
    void *dtor_obj;
    void *free_obj;
} zend_object_handlers;

typedef struct _php_snmp_object {
    zend_object zo;
} php_snmp_object;

typedef void (*zend_objects_store_dtor_t)(void *object);
typedef void (*zend_objects_free_object_storage_t)(void *object);

#define TSRMLS_DC
#define TSRMLS_CC
#define emalloc malloc

static zend_object_handlers php_snmp_object_handlers;

static void php_snmp_object_free_storage(void *object TSRMLS_DC) {}
static void zend_object_std_init(zend_object *object, zend_class_entry *class_type TSRMLS_DC) {}
static void object_properties_init(zend_object *object, zend_class_entry *class_type) {}
static unsigned int zend_objects_store_put(void *object, zend_objects_store_dtor_t dtor, 
    zend_objects_free_object_storage_t free_storage, void *destructor TSRMLS_DC) { return 0; }
static void zend_objects_destroy_object(void *object TSRMLS_DC) {}