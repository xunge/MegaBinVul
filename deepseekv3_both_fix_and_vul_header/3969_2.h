#include <stdlib.h>

typedef struct _object PyObject;
typedef struct _arrayobject PyArrayObject;
typedef long npy_intp;

static int NI_ObjectToInputArray(PyObject* obj, PyArrayObject** arr) { return 0; }
static int NI_FindObjects(PyArrayObject* input, npy_intp max_label, npy_intp* regions) { return 0; }

#define Py_None NULL
#define Py_INCREF(x) ((void)0)
#define Py_XDECREF(x) ((void)0)
#define PyErr_NoMemory() ((void)0)
#define PyErr_Occurred() 0
#define PyArg_ParseTuple(args, fmt, conv, arg1, arg2) 0
#define PyArray_NDIM(arr) 0
#define PyList_New(size) NULL
#define PyTuple_New(size) NULL
#define PyLong_FromSsize_t(val) NULL
#define PySlice_New(start, end, step) NULL
#define PyTuple_SetItem(tuple, pos, item) ((void)0)
#define PyList_SetItem(list, pos, item) ((void)0)