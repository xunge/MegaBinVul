#include <assert.h>
#include <stdlib.h>
#include <stddef.h>
#include <errno.h>

typedef struct _object PyObject;
typedef ptrdiff_t Py_ssize_t;

typedef struct {
    PyObject **memo;
    Py_ssize_t memo_size;
} UnpicklerObject;

#define PyMem_RESIZE(p, type, n) \
    ((p) = (type *) realloc((p), (n) * sizeof(type)))

#define PyErr_NoMemory() (errno = ENOMEM)