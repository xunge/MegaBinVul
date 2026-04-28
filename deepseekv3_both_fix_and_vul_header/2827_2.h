#include <stddef.h>

typedef struct PyObject {
    int ob_refcnt;
    void* ob_type;
} PyObject;

typedef long Py_ssize_t;

typedef struct {
    PyObject *me_key;
    Py_ssize_t me_value;
} PyMemoEntry;

typedef struct {
    PyMemoEntry *mt_table;
    size_t mt_allocated;
} PyMemoTable;

typedef struct PicklerObject {
    PyMemoTable *memo;
} PicklerObject;

typedef struct PicklerMemoProxyObject {
    PyObject _base;
    PicklerObject *pickler;
} PicklerMemoProxyObject;

#define PyDict_New() ((PyObject*)0)
#define PyLong_FromVoidPtr(p) ((PyObject*)0)
#define Py_BuildValue(fmt, ...) ((PyObject*)0)
#define PyDict_SetItem(d, k, v) (0)
#define Py_DECREF(op) ((void)0)
#define Py_XDECREF(op) ((void)0)