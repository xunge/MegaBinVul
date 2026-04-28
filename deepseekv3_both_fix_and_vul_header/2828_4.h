#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#define PY_SSIZE_T_MAX ((size_t)-1 >> 1)
#define MT_MINSIZE 8

typedef ptrdiff_t Py_ssize_t;

typedef struct {
    void *me_key;
    void *me_value;
} PyMemoEntry;

typedef struct {
    PyMemoEntry *mt_table;
    Py_ssize_t mt_allocated;
    Py_ssize_t mt_used;
    Py_ssize_t mt_mask;
} PyMemoTable;

#define PyMem_NEW(type, size) ((type *)malloc((size) * sizeof(type)))
#define PyMem_FREE(ptr) free(ptr)
#define PyErr_NoMemory() (void)0

static PyMemoEntry* _PyMemoTable_Lookup(PyMemoTable *self, void *key);