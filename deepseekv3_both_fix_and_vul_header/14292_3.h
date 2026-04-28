#include <stdlib.h>
#include <string.h>

#define NPY_NO_EXPORT

typedef struct PyObject PyObject;
typedef struct PyTypeObject {
    PyObject *(*tp_alloc)(struct PyTypeObject *, int);
} PyTypeObject;
typedef struct PyArray_Descr {
    int elsize;
    int type_num;
    int subarray;
} PyArray_Descr;
typedef struct PyArrayObject PyArrayObject;
typedef long npy_intp;
typedef unsigned int npy_ucs4;

typedef struct PyArrayObject_fields {
    void *_buffer_info;
    int nd;
    npy_intp *dimensions;
    void *data;
    int flags;
    PyArray_Descr *descr;
    PyObject *base;
    PyObject *weakreflist;
    npy_intp *strides;
} PyArrayObject_fields;

typedef int PyArray_FinalizeFunc(PyArrayObject *, PyObject *);

#define NPY_MAXDIMS 32
#define NPY_ARRAY_DEFAULT 0
#define NPY_ARRAY_F_CONTIGUOUS 0x0001
#define NPY_ARRAY_C_CONTIGUOUS 0x0002
#define NPY_ARRAY_WRITEBACKIFCOPY 0x0004
#define NPY_ARRAY_UPDATEIFCOPY 0x0008
#define NPY_ARRAY_OWNDATA 0x0010
#define NPY_ARRAY_UPDATE_ALL 0x0020

#define PyDataType_ISUNSIZED(d) 0
#define PyDataType_ISFLEXIBLE(d) 0
#define PyDataType_ISSTRING(d) 0
#define PyDataType_FLAGCHK(d, f) 0
#define NPY_NEEDS_INIT 0
#define NPY_STRING 0

static PyObject *npy_ma_str_array_finalize = NULL;
static PyTypeObject PyArray_Type;

static int _update_descr_and_dimensions(PyArray_Descr **descr, npy_intp *dims, npy_intp *strides, int nd) {
    return nd;
}

static void _array_fill_strides(npy_intp *strides, const npy_intp *dims, int nd, int elsize, int flags, int *out_flags) {
}

static void *npy_alloc_cache_dim(size_t size) {
    return malloc(size);
}

static void *npy_alloc_cache_zero(size_t size) {
    return calloc(1, size);
}

static void *npy_alloc_cache(size_t size) {
    return malloc(size);
}

static void raise_memory_error(int nd, npy_intp *dims, PyArray_Descr *descr) {
}

static int PyArray_SetBaseObject(PyArrayObject *arr, PyObject *base) {
    return 0;
}

static void PyArray_UpdateFlags(PyArrayObject *arr, int flags) {
}

#define PyArray_DESCR_REPLACE(d) do {} while(0)

static int npy_mul_with_overflow_intp(npy_intp *result, npy_intp a, npy_intp b) {
    return 0;
}

#define Py_INCREF(obj) 
#define Py_DECREF(obj) 
#define Py_XDECREF(obj) 
#define PyErr_NoMemory() 
#define PyErr_SetString(type, msg) 
#define PyErr_Format(type, fmt, ...) 
#define PyExc_ValueError NULL
#define PyExc_TypeError NULL
#define Py_None NULL
#define PyCapsule_CheckExact(obj) 0
#define PyCapsule_GetPointer(obj, name) NULL
#define PyObject_GetAttr(obj, attr) NULL
#define PyTuple_New(size) NULL
#define PyTuple_SET_ITEM(tup, pos, item) 
#define PyObject_Call(func, args, kwargs) NULL