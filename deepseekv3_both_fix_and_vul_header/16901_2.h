#include <stddef.h>

typedef struct {
    void *current_tasks;
} asyncio_state;

typedef long Py_hash_t;
typedef struct _object PyObject;
#define Py_None ((PyObject *)0x1)
#define Py_XNewRef(obj) (obj)
#define Py_DECREF(obj) 
#define PyErr_Occurred() (0)
#define PyObject_Hash(obj) (0)
#define _PyDict_GetItem_KnownHash(dict, key, hash) (0)
#define _PyDict_DelItem_KnownHash(dict, key, hash) (0)
#define _PyDict_SetItem_KnownHash(dict, key, value, hash) (0)