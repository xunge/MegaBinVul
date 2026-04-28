#include <string.h>
#include <sys/types.h>

typedef long Py_ssize_t;
typedef struct _object PyObject;
typedef long off_t;

extern PyObject* PyList_Type;
extern PyObject* PyExc_TypeError;
extern PyObject* PyExc_ValueError;

static int PyArg_ParseTuple(PyObject*, const char*, ...) { return 0; }
static PyObject* PyErr_NoMemory() { return 0; }
static void* PyMem_Malloc(size_t) { return 0; }
static void PyMem_Free(void*) {}
static int PyList_GET_SIZE(PyObject*) { return 0; }
static PyObject* PyList_GET_ITEM(PyObject*, int) { return 0; }
static int PyTuple_Check(PyObject*) { return 0; }
static int PyTuple_GET_SIZE(PyObject*) { return 0; }
static long PyLong_AsLong(PyObject*) { return 0; }
static PyObject* PyTuple_GET_ITEM(PyObject*, int) { return 0; }
static void PyErr_SetString(PyObject*, const char*) {}
static PyObject* PyBytes_FromStringAndSize(const char*, Py_ssize_t) { return 0; }