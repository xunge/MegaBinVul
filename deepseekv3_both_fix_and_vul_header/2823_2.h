#include <stddef.h>

typedef struct _object PyObject;
typedef long Py_ssize_t;

typedef struct {
    PyObject **memo;
    Py_ssize_t memo_size;
} UnpicklerObject;

typedef struct {
    UnpicklerObject *unpickler;
} UnpicklerMemoProxyObject;

PyObject* PyDict_New(void);
PyObject* PyLong_FromSsize_t(Py_ssize_t);
int PyDict_SetItem(PyObject*, PyObject*, PyObject*);
void Py_DECREF(PyObject*);