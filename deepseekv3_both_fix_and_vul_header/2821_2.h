#include <stddef.h>

typedef long Py_ssize_t;
typedef struct _object PyObject;

typedef struct {
    Py_ssize_t memo_size; 
    PyObject **memo;
} UnpicklerObject;