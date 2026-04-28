#include <stddef.h>
#include <stdint.h>

typedef intptr_t Py_ssize_t;
typedef struct _object {
    Py_ssize_t ob_refcnt;
    struct _typeobject *ob_type;
} PyObject;

typedef struct _typeobject {
    Py_ssize_t ob_refcnt;
    const char *tp_name;
    Py_ssize_t tp_basicsize;
} PyTypeObject;

#define PyObject_HEAD PyObject ob_base

typedef struct {
    PyObject_HEAD;
    PyObject **memo;
    size_t memo_size;
} UnpicklerObject;

typedef struct {
    PyObject_HEAD;
    UnpicklerObject *unpickler;
} UnpicklerMemoProxyObject;

extern PyTypeObject *PyExc_TypeError;
extern PyTypeObject *PyExc_ValueError;
extern PyTypeObject UnpicklerMemoProxyType;

PyObject **_Unpickler_NewMemo(size_t size);
int _Unpickler_MemoPut(UnpicklerObject *self, Py_ssize_t idx, PyObject *value);
void _Unpickler_MemoCleanup(UnpicklerObject *self);

void PyErr_SetString(PyTypeObject *, const char *);
int PyDict_Check(PyObject *);
int PyLong_Check(PyObject *);
Py_ssize_t PyLong_AsSsize_t(PyObject *);
int PyDict_Next(PyObject *, Py_ssize_t *, PyObject **, PyObject **);
void Py_XINCREF(PyObject *);
void Py_XDECREF(PyObject *);
void PyMem_FREE(void *);
Py_ssize_t PyDict_GET_SIZE(PyObject *);
int PyErr_Occurred(void);
void PyErr_Format(PyTypeObject *, const char *, ...);
PyTypeObject *Py_TYPE(PyObject *);