#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

typedef struct PyArray_Descr {
    char byteorder;
    int elsize;
} PyArray_Descr;

typedef struct _object {
    // Minimal PyObject definition
} PyObject;

#define NPY_NOTYPE 0
#define NPY_STRING 1
#define NPY_UNICODE 2
#define NPY_VOID 3
#define NPY_STRINGLTR 'S'
#define NPY_STRINGLTR2 'a'
#define NPY_UNICODELTR 'U'
#define NPY_VOIDLTR 'V'

#define PyArray_ISNBO(c) (0)
#define PyDataType_ISUNSIZED(d) (0)
#define PyArray_DESCR_REPLACE(d) (0)
#define PyExc_TypeError 0

typedef ssize_t Py_ssize_t;

static PyObject *typeDict;

static int _check_for_commastring(const char *type, Py_ssize_t len) { return 0; }
static PyArray_Descr *_convert_from_commastring(PyObject *obj, int align) { return NULL; }
static int is_datetime_typestr(const char *type, Py_ssize_t len) { return 0; }
static PyArray_Descr *parse_dtype_from_datetime_typestr(const char *type, Py_ssize_t len) { return NULL; }
static int PyArray_TypestrConvert(int elsize, int kind) { return 0; }
static PyArray_Descr *_convert_from_any(PyObject *item, int align) { return NULL; }
static int DEPRECATE(const char *msg) { return 0; }
static int PyErr_Occurred(void) { return 0; }
static void PyErr_Clear(void) {}
static PyObject *PyDict_GetItemWithError(PyObject *dict, PyObject *key) { return NULL; }
static PyArray_Descr *PyArray_DescrFromType(int type) { return NULL; }
static void PyErr_Format(int exc, const char *format, ...) {}
static char *PyUnicode_AsUTF8AndSize(PyObject *obj, Py_ssize_t *size) { return NULL; }