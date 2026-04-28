#include <string.h>
#include <stdlib.h>

#define CHOLMOD_A 0
#define CHOLMOD_LDLt 1
#define CHOLMOD_LD 2
#define CHOLMOD_DLt 3
#define CHOLMOD_L 4
#define CHOLMOD_Lt 5
#define CHOLMOD_D 6
#define CHOLMOD_P 7
#define CHOLMOD_Pt 8
#define CHOLMOD_REAL 0
#define CHOLMOD_COMPLEX 1
#define CHOLMOD_PATTERN 2
#define CHOLMOD_OK 0
#define CHOLMOD_OUT_OF_MEMORY 1

#define INT 0
#define DOUBLE 1
#define COMPLEX 2

#define MAX(a,b) ((a) > (b) ? (a) : (b))

typedef struct cholmod_common_struct {
    int status;
} cholmod_common;

typedef struct cholmod_factor_struct {
    int xtype;
    int n;
    int minor;
} cholmod_factor;

typedef struct cholmod_dense_struct {
    void *x;
} cholmod_dense;

typedef struct {
    int id;
    int nrows;
    int ncols;
    int lgt;
    void *buf;
} matrix;

static cholmod_common Common;

static const char *strCFDL = "CHOLMOD FACTOR DL";
static const char *strCFDU = "CHOLMOD FACTOR DU";
static const char *strCFZL = "CHOLMOD FACTOR ZL";
static const char *strCFZU = "CHOLMOD FACTOR ZU";

static int E_SIZE[] = {sizeof(int), sizeof(double), sizeof(double)};

#define MAT_ID(m) ((m)->id)
#define MAT_NROWS(m) ((m)->nrows)
#define MAT_NCOLS(m) ((m)->ncols)
#define MAT_LGT(m) ((m)->lgt)
#define MAT_BUF(m) ((m)->buf)

static int Matrix_Check(void *m) { return 1; }
static int set_options(void) { return 1; }
static void err_CO(const char *s) {}
static void PY_ERR_TYPE(const char *s) {}
static void PY_ERR(void *type, const char *msg) {}
static void err_ld(const char *s) {}
static void err_nn_int(const char *s) {}
static void err_buf_len(const char *s) {}

typedef struct {
    int dummy;
} PyObject;

#define Py_BuildValue(x) NULL
#define PyExc_ValueError NULL
#define PyExc_ArithmeticError NULL
#define PyErr_NoMemory() NULL
#define PyErr_SetString(a,b) 
#define PyArg_ParseTupleAndKeywords(a,b,c,d,...) 1
#define PyCapsule_CheckExact(a) 1
#define PyCapsule_GetName(a) ""
#define PyCapsule_GetPointer(a,b) NULL
#define PyCObject_Check(a) 1
#define PyCObject_GetDesc(a) ""
#define PyCObject_AsVoidPtr(a) NULL

cholmod_dense* cholmod_allocate_dense(int a, int b, int c, int d, cholmod_common *e) { return NULL; }
void cholmod_free_dense(cholmod_dense **a, cholmod_common *b) {}
cholmod_dense* cholmod_solve(int a, cholmod_factor *b, cholmod_dense *c, cholmod_common *d) { return NULL; }

#define CHOL(name) cholmod_##name