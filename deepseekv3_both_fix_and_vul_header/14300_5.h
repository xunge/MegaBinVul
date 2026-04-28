#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <complex.h>

typedef int64_t int_t;

#define PY_MAJOR_VERSION 3
#define CHOLMOD_PATTERN 0
#define CHOLMOD_REAL 1
#define PyExc_ValueError 0

typedef struct PyObject {
    int ob_refcnt;
    void* ob_type;
} PyObject;

typedef struct cholmod_common_struct {
    int dummy;
} cholmod_common;

typedef struct cholmod_factor_struct {
    int xtype;
} cholmod_factor;

typedef struct cholmod_sparse_struct {
    int_t nrow;
    int_t ncol;
    int_t nzmax;
    int xtype;
    int_t* p;
    int_t* i;
    void* x;
} cholmod_sparse;

static cholmod_common Common;
static const char *strCFDL = "CHOLMOD FACTOR DL";
static const char *strCFDU = "CHOLMOD FACTOR DU";
static const char *strCFZL = "CHOLMOD FACTOR ZL";
static const char *strCFZU = "CHOLMOD FACTOR ZU";

typedef struct {
    PyObject ob_base;
    int_t nrow;
    int_t ncol;
    int_t nzmax;
    int type;
    int_t *col;
    int_t *row;
    void *val;
} spmatrix;

#define SP_COL(m) ((m)->col)
#define SP_ROW(m) ((m)->row)
#define SP_VAL(m) ((m)->val)
#define SP_ID(m) ((m)->type)
#define DOUBLE 0
#define COMPLEX 1
static const size_t E_SIZE[] = {sizeof(double), sizeof(double _Complex)};

static int set_options(void) { return 1; }
static void err_CO(const char* s) {}
static void PY_ERR_TYPE(const char* s) {}
static void PY_ERR(int exc, const char* s) {}
static PyObject* PyErr_NoMemory(void) { return NULL; }
static int PyArg_ParseTuple(PyObject* args, const char* fmt, ...) { return 1; }
static int PyCapsule_CheckExact(PyObject* obj) { return 1; }
static const char* PyCapsule_GetName(PyObject* obj) { return ""; }
static void* PyCapsule_GetPointer(PyObject* obj, const char* name) { return NULL; }
static cholmod_sparse* factor_to_sparse(cholmod_factor* L, cholmod_common* c) { return NULL; }
static void free_sparse(cholmod_sparse** L, cholmod_common* c) {}
static spmatrix* SpMatrix_New(int_t nrow, int_t ncol, int_t nzmax, int type) { return NULL; }

#define CHOL(name) name