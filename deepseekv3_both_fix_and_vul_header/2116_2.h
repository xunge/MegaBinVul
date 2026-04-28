#include <stddef.h>

typedef enum {
    FRIBIDI_TYPE_RTL,
    FRIBIDI_TYPE_LTR,
    FRIBIDI_TYPE_ON
} FriBidiParType;

typedef struct _object {
    struct _typeobject *ob_type;
} PyObject;

typedef struct _typeobject {
    char *tp_name;
} PyTypeObject;

typedef struct {
    PyObject ob_base;
} PyUnicodeObject;

#define PyExc_ValueError ((PyObject*)1)
#define PyExc_TypeError ((PyObject*)2)
#define PyString_Check(obj) (0)
#define PyUnicode_Check(obj) (0)

static int PyArg_ParseTupleAndKeywords(PyObject*, PyObject*, const char*, char**, ...) { return 0; }
static PyObject* PyErr_Format(PyObject*, const char*, ...) { return NULL; }
static PyObject* unicode_log2vis(PyUnicodeObject*, FriBidiParType, int, int) { return NULL; }
static PyObject* log2vis_unicode(PyObject*, FriBidiParType, int, int) { return NULL; }
static PyObject* log2vis_encoded_string(PyObject*, const char*, FriBidiParType, int, int) { return NULL; }