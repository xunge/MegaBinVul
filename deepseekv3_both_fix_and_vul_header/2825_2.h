#include <stddef.h>
#include <assert.h>
#include <stdint.h>

typedef struct _PyObject PyObject;
typedef long Py_ssize_t;

typedef struct {
    PyObject *me_key;
    Py_ssize_t me_value;
} PyMemoEntry;

typedef struct {
    Py_ssize_t mt_used;
    Py_ssize_t mt_allocated;
    size_t mt_mask;
} PyMemoTable;

int _PyMemoTable_ResizeTable(PyMemoTable *self, size_t desired_size);
PyMemoEntry *_PyMemoTable_Lookup(PyMemoTable *self, PyObject *key);
void Py_INCREF(PyObject *);