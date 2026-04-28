#include <string.h>
#include <stdlib.h>

#define MODE_ECB 1
#define MODE_CBC 2
#define MODE_CFB 3
#define MODE_PGP 4
#define MODE_OFB 5
#define MODE_CTR 6
#define BLOCK_SIZE 16
#define KEY_SIZE 0

typedef struct PyObject PyObject;
typedef struct PyTypeObject PyTypeObject;

struct PyObject {
    PyTypeObject *ob_type;
};

struct PyTypeObject {
    int dummy;
};

typedef struct {
    int segment_size;
    PyObject *counter;
    int counter_shortcut;
    unsigned char IV[BLOCK_SIZE];
    unsigned char oldCipher[BLOCK_SIZE];
    int mode;
    int count;
#ifdef PCT_ARC2_MODULE
    struct {
        int effective_keylen;
    } st;
#else
    void *st;
#endif
} ALGobject;

#define PyExc_ValueError ((PyObject*)1)
#define PyExc_TypeError ((PyObject*)2)
#define PCT_CounterBEType ((PyTypeObject*)3)
#define PCT_CounterLEType ((PyTypeObject*)4)

static char *kwlist[] = {"key", "keylen", "mode", "IV", "IVlen", "counter", "segment_size", "effective_keylen", NULL};

extern ALGobject *newALGobject(void);
extern void block_init(void *st, unsigned char *key, int keylen);
extern int PyArg_ParseTupleAndKeywords(PyObject*, PyObject*, const char*, char**, ...);
extern void PyErr_Format(PyObject*, const char*, ...);
extern void PyErr_SetString(PyObject*, const char*);
extern PyTypeObject* Py_TYPE(PyObject*);
extern int PyCallable_Check(PyObject*);
extern void Py_XINCREF(PyObject*);
extern int PyErr_Occurred(void);
extern void Py_DECREF(PyObject*);