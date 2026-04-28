#include <string.h>
#include <stdlib.h>

typedef struct {
    int id;
    int nrows;
    int ncols;
} spmatrix;

typedef struct {
    int status;
} cholmod_common;

typedef struct {
    int is_ll;
    int minor;
} cholmod_factor;

typedef struct {
} cholmod_sparse;

typedef struct {
} PyObject;

static PyObject* PyExc_ValueError;
static PyObject* PyExc_ArithmeticError;
static PyObject* PyExc_RuntimeWarning;
static PyObject* PyExc_UserWarning;

extern cholmod_common Common;

#define SP_ID(A) ((A)->id)
#define SP_NROWS(A) ((A)->nrows)
#define SP_NCOLS(A) ((A)->ncols)
#define SpMatrix_Check(A) (1)
#define PY_ERR_TYPE(msg) (NULL)
#define err_CO(msg) (NULL)
#define CHOL(f) cholmod_##f
#define DOUBLE 0

#define CHOLMOD_OUT_OF_MEMORY (-1)
#define CHOLMOD_NOT_POSDEF (1)
#define CHOLMOD_DSMALL (2)

static const char *strCFDL = "CHOLMOD FACTOR D L";
static const char *strCFDU = "CHOLMOD FACTOR D U";
static const char *strCFZL = "CHOLMOD FACTOR Z L";
static const char *strCFZU = "CHOLMOD FACTOR Z U";

static int PyArg_ParseTuple(PyObject *args, const char *fmt, ...) { return 1; }
static int PyCObject_Check(PyObject *obj) { return 1; }
static char* PyCObject_GetDesc(PyObject *obj) { return NULL; }
static void* PyCObject_AsVoidPtr(PyObject *obj) { return NULL; }
static int cholmod_factorize(cholmod_sparse *A, cholmod_factor *L, cholmod_common *Common) { return 0; }
static int cholmod_free_sparse(cholmod_sparse **A, cholmod_common *Common) { return 0; }

static int set_options(void) { return 1; }
static cholmod_sparse* pack(spmatrix *A, char uplo) { return NULL; }
static void* PyErr_NoMemory() { return NULL; }
static void PyErr_SetString(PyObject* exc, const char* msg) {}
static void PyErr_SetObject(PyObject* exc, PyObject* val) {}
static void PyErr_Warn(PyObject* exc, const char* msg) {}
static PyObject* Py_BuildValue(const char* fmt, ...) { return NULL; }