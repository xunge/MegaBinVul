#include <string.h>
#include <assert.h>

#define CSHARP_LEGACY 1
#define JAVA_LEGACY 2

struct module_state {
    void* DBRef;
    void* Binary;
    void* UUID;
    void* ObjectId;
    void* UTC;
    void* RECompile;
    void* Code;
    void* MinKey;
    void* MaxKey;
    void* Timestamp;
};

typedef struct _object {
    int ob_refcnt;
    struct _typeobject *ob_type;
} PyObject;

typedef struct _typeobject {
    const char *tp_name;
    /* ... other fields ... */
} PyTypeObject;

extern PyTypeObject PyDict_Type;

#define Py_None ((PyObject*)&_Py_NoneStruct)
#define Py_True ((PyObject*)&_Py_TrueStruct)
#define Py_False ((PyObject*)&_Py_FalseStruct)
#define Py_INCREF(op) (((PyObject*)(op))->ob_refcnt++)
#define Py_DECREF(op) do { \
    if (--((PyObject*)(op))->ob_refcnt == 0) \
        ; /* actual deallocation would go here */ \
} while (0)

extern PyObject _Py_NoneStruct;
extern PyObject _Py_TrueStruct;
extern PyObject _Py_FalseStruct;

/* Function prototypes */
#define GETSTATE(self) ((struct module_state*)0)
static PyObject* PyFloat_FromDouble(double);
static PyObject* PyUnicode_DecodeUTF8(const char*, int, const char*);
static PyObject* PyDict_GetItemString(PyObject*, const char*);
static void PyDict_DelItemString(PyObject*, const char*);
static PyObject* PyObject_CallFunctionObjArgs(void*, ...);
static PyObject* PyList_New(int);
static void PyList_Append(PyObject*, PyObject*);
static PyObject* PyString_FromStringAndSize(const char*, int);
static PyObject* PyTuple_New(int);
static PyObject* PyDict_New(void);
static int PyDict_SetItemString(PyObject*, const char*, PyObject*);
static PyObject* PyObject_Call(PyObject*, PyObject*, PyObject*);
static PyObject* PyInt_FromLong(long);
static PyObject* PyObject_CallFunction(void*, const char*, ...);
static PyObject* PyObject_GetAttrString(PyObject*, const char*);
static void PyErr_SetString(PyObject*, const char*);
static void PyErr_SetNone(PyObject*);
static PyObject* PyLong_FromLongLong(long long);

static PyObject* _error(const char* name);
static PyObject* datetime_from_millis(long long millis);
static PyObject* elements_to_dict(PyObject* self, const char* buffer, int size, PyObject* as_class, unsigned char tz_aware, unsigned char uuid_subtype);
static void _fix_java(const char* in, char* out);