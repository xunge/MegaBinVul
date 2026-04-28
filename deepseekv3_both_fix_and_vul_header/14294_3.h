#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long npy_intp;

typedef struct PyObject {
    int ob_refcnt;
    struct _typeobject *ob_type;
} PyObject;

typedef struct PyArray_Descr {
    PyObject ob_base;
    char type;
    int elsize;
} PyArray_Descr;

typedef struct PyArrayObject {
    PyObject ob_base;
    char *data;
    int nd;
    npy_intp *dimensions;
    npy_intp *strides;
    PyObject *base;
    PyArray_Descr *descr;
    int flags;
} PyArrayObject;

#define F2PY_INTENT_HIDE 1
#define F2PY_INTENT_CACHE 2
#define F2PY_OPTIONAL 4
#define F2PY_INTENT_C 8
#define F2PY_INTENT_OUT 16
#define F2PY_INTENT_COPY 32
#define F2PY_INTENT_INOUT 64
#define F2PY_INTENT_INPLACE 128

#define NPY_INTP_FMT "ld"
#define NPY_CHARLTR 'c'
#define NPY_STRING 0

#define Py_None ((PyObject*)0)
#define Py_INCREF(obj) ((obj)->ob_base.ob_refcnt++)
#define Py_DECREF(obj) if (--(obj)->ob_base.ob_refcnt == 0) free(obj)
#define Py_XDECREF(obj) if (obj) Py_DECREF(obj)
#define PyErr_SetString(type, msg)
#define PyErr_Format(type, fmt, ...)

#define PyArray_Check(obj) 0
#define PyArray_New(type, rank, dims, type_num, data, strides, is_f_order, requirements, obj) ((PyArrayObject*)0)
#define PyArray_DescrFromType(type_num) ((PyArray_Descr*)0)
#define PyArray_DESCR_REPLACE(descr) 0
#define PyArray_FILLWBYTE(arr, val)
#define PyArray_ISONESEGMENT(arr) 0
#define PyArray_ITEMSIZE(arr) 0
#define PyArray_ISCARRAY(arr) 0
#define PyArray_ISFARRAY(arr) 0
#define PyArray_ISCARRAY_RO(arr) 0
#define PyArray_ISFARRAY_RO(arr) 0
#define PyArray_NDIM(arr) 0
#define PyArray_DIMS(arr) ((npy_intp*)0)
#define PyArray_DESCR(arr) ((PyArray_Descr*)0)
#define PyArray_CopyInto(dest, src) 0
#define PyArray_FromAny(obj, descr, min_depth, max_depth, requirements, context) ((PyArrayObject*)0)

#define F2PY_GET_ALIGNMENT(intent) ((intent) >> 8)
#define F2PY_CHECK_ALIGNMENT(arr, intent) 0
#define F2PY_REPORT_ON_ARRAY_COPY_FROMARR
#define F2PY_REPORT_ON_ARRAY_COPY_FROMANY

extern int count_negative_dimensions(int rank, npy_intp *dims);
extern int check_and_fix_dimensions(PyArrayObject *arr, int rank, npy_intp *dims);
extern int swap_arrays(PyArrayObject *arr1, PyArrayObject *arr2);
extern int ARRAY_ISCOMPATIBLE(PyArrayObject *arr, int type_num);
extern int ARRAY_ISALIGNED(PyArrayObject *arr, int alignment);