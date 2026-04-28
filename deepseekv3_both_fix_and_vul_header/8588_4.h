#include <string.h>
#include <limits.h>
#include <stddef.h>
#include <stdint.h>

typedef ptrdiff_t Py_ssize_t;

typedef struct Py_buffer {
    void *buf;
    Py_ssize_t len;
    int readonly;
    const char *format;
    int ndim;
    Py_ssize_t *shape;
    Py_ssize_t *strides;
    Py_ssize_t *suboffsets;
    void *internal;
} Py_buffer;

typedef struct PyObject {
    Py_ssize_t ob_refcnt;
    struct _typeobject *ob_type;
} PyObject;

typedef struct ImagingBufferInstance {
    PyObject* target;
    Py_buffer view;
} ImagingBufferInstance;

typedef struct Imaging {
    char* mode;
    int xsize;
    int ysize;
    char** image;
    void (*destroy)(struct Imaging*);
    ImagingBufferInstance* buffer;
} *Imaging;

typedef struct _typeobject {
    const char *tp_name;
} PyTypeObject;

extern PyObject *PyExc_TypeError;
extern PyObject *PyExc_MemoryError;
extern PyObject *PyExc_ValueError;

void (*mapping_destroy_buffer)(Imaging);

int PyArg_ParseTuple(PyObject*, const char*, ...);
int PyImaging_CheckBuffer(PyObject*);
int PyImaging_GetBuffer(PyObject*, Py_buffer*);
Imaging ImagingNewPrologueSubtype(const char*, int, int, size_t);
int ImagingNewEpilogue(Imaging);
PyObject* PyImagingNew(Imaging);
void Py_INCREF(PyObject*);
void PyErr_SetString(PyObject*, const char*);