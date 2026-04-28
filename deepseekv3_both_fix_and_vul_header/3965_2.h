#include <stdlib.h>

typedef struct _object PyObject;
typedef struct _arrayobject PyArrayObject;
typedef long npy_intp;

static int NI_ObjectToInputArray(PyObject* obj, PyArrayObject** arr) { return 0; }
static int NI_FindObjects(PyArrayObject* input, npy_intp max_label, npy_intp* regions) { return 0; }

#define Py_None ((PyObject*)0)
#define Py_INCREF(op) ((void)0)
#define Py_XDECREF(op) ((void)0)
#define PyErr_NoMemory() ((void)0)
#define PyErr_Occurred() (0)
#define PyArg_ParseTuple(args, format, ...) (0)
#define PyList_New(size) ((PyObject*)0)
#define PyTuple_New(size) ((PyObject*)0)
#define PyLong_FromSsize_t(val) ((PyObject*)0)
#define PySlice_New(start, stop, step) ((PyObject*)0)
#define PyTuple_SetItem(t, pos, o) (0)
#define PyList_SetItem(l, pos, o) (0)
#define PyArray_NDIM(arr) (0)