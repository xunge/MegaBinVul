#include <stddef.h>

typedef struct _object PyObject;
typedef long Py_hash_t;

typedef struct {
    PyObject *me_key;
} PyMemoEntry;

typedef struct {
    PyMemoEntry *mt_table;
    int mt_mask;
} PyMemoTable;

#define PERTURB_SHIFT 5
#define Py_UNREACHABLE()