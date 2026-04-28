#include <stdlib.h>
#include <string.h>

typedef struct PyObject {
    int dummy;
} PyObject;

typedef struct spmatrix {
    int dummy;
    void* col;
    void* row;
    void* val;
} spmatrix;

typedef struct cholmod_sparse {
    int nrow;
    int ncol;
    void* p;
    void* i;
    void* x;
} cholmod_sparse;

typedef struct cholmod_factor {
    int xtype;
    int n;
    int minor;
} cholmod_factor;

typedef struct {
    int status;
} cholmod_common;

extern cholmod_common Common;

#define CHOLMOD_A 0
#define CHOLMOD_LDLt 1
#define CHOLMOD_LD 2
#define CHOLMOD_DLt 3
#define CHOLMOD_L 4
#define CHOLMOD_Lt 5
#define CHOLMOD_D 6
#define CHOLMOD_P 7
#define CHOLMOD_Pt 8
#define CHOLMOD_OK 0
#define CHOLMOD_OUT_OF_MEMORY 1

#define CHOLMOD_REAL 0
#define CHOLMOD_COMPLEX 1
#define CHOLMOD_PATTERN 2

#define DOUBLE 0
#define COMPLEX 1

#define PY_MAJOR_VERSION 3

#define strCFDL "CHOLMOD FACTOR DL"
#define strCFDU "CHOLMOD FACTOR DU" 
#define strCFZL "CHOLMOD FACTOR ZL"
#define strCFZU "CHOLMOD FACTOR ZU"

typedef int int_t;
#define SP_ID(m) (0)
#define SP_NROWS(m) (0)
#define SP_COL(m) ((m)->col)
#define SP_ROW(m) ((m)->row)
#define SP_VAL(m) ((m)->val)
static const int E_SIZE[] = {8, 16};

static int set_options(void) { return 1; }
static cholmod_sparse* create_matrix(spmatrix* m) { return NULL; }
static void free_matrix(cholmod_sparse* m) {}
static cholmod_sparse* cholmod_spsolve(int sys, cholmod_factor* L, cholmod_sparse* B, cholmod_common* c) { return NULL; }
static void cholmod_free_sparse(cholmod_sparse** m, cholmod_common* c) {}
static spmatrix* SpMatrix_New(int nrow, int ncol, int nnz, int type) { return NULL; }
static int SpMatrix_Check(void* o) { return 0; }

static int PyArg_ParseTupleAndKeywords(PyObject*, PyObject*, const char*, char**, ...) { return 0; }
static int PyCapsule_CheckExact(PyObject*) { return 0; }
static const char* PyCapsule_GetName(PyObject*) { return NULL; }
static void* PyCapsule_GetPointer(PyObject*, const char*) { return NULL; }
static PyObject* PyErr_NoMemory() { return NULL; }

#define CHOL(name) cholmod_##name
#define err_CO(s) do { return NULL; } while(0)
#define PY_ERR_TYPE(s) do { return NULL; } while(0)
#define PY_ERR(e, s) do { return NULL; } while(0)