#include <stdlib.h>
#include <string.h>
#include <stddef.h>

typedef void PyObject;
typedef ptrdiff_t Py_ssize_t;

typedef struct _PyMemoEntry {
    PyObject *me_key;
} PyMemoEntry;

typedef struct _PyMemoTable {
    Py_ssize_t mt_used;
    Py_ssize_t mt_allocated;
    Py_ssize_t mt_mask;
    PyMemoEntry *mt_table;
} PyMemoTable;

static PyMemoTable *PyMemoTable_New(void);
#define PyMem_FREE free
#define PyMem_NEW(type, size) ((type *)malloc(sizeof(type) * (size)))
#define Py_XINCREF(op) 
#define PyErr_NoMemory()