#include <stddef.h>

typedef struct _object PyObject;
typedef long long Py_ssize_t;

typedef struct {
    Py_ssize_t memo_size;
    Py_ssize_t memo_len;
    PyObject **memo;
} UnpicklerObject;