#include <stddef.h>
#include <stdlib.h>

#define CHOLMOD_OK 0
#define CHOLMOD_OUT_OF_MEMORY -2

typedef struct PyObject {
    int ob_refcnt;
    void *ob_type;
} PyObject;

typedef struct {
    PyObject ob_base;
    int id;
    int nrows;
    int ncols;
    void *buffer;
} spmatrix;

typedef struct {
    PyObject ob_base;
    int id;
    int lgt;
    void *buffer;
} matrix;

typedef struct cholmod_sparse_struct cholmod_sparse;
typedef struct cholmod_factor_struct cholmod_factor;
typedef struct {
    int status;
} cholmod_common;

#define SP_ID(A) (((spmatrix *)(A))->id)
#define SP_NROWS(A) (((spmatrix *)(A))->nrows)
#define SP_NCOLS(A) (((spmatrix *)(A))->ncols)
#define MAT_ID(A) (((matrix *)(A))->id)
#define MAT_LGT(A) (((matrix *)(A))->lgt)
#define MAT_BUFI(A) (((matrix *)(A))->buffer)

#define DOUBLE 1
#define INT 2

extern cholmod_common Common;
extern int set_options(void);
extern cholmod_sparse* pack(spmatrix *A, char uplo);
extern void cvxopt_free_cholmod_factor(void *L);
extern int check_perm(int *P, int n, int m, cholmod_common *Common);
extern cholmod_factor* analyze_p(cholmod_sparse *A, int *Perm, int *fset, size_t fsize, cholmod_common *Common);
extern void free_sparse(cholmod_sparse **A, cholmod_common *Common);

static const char *strCFDL = "CHOLMOD FACTOR D L";
static const char *strCFDU = "CHOLMOD FACTOR D U"; 
static const char *strCFZL = "CHOLMOD FACTOR Z L";
static const char *strCFZU = "CHOLMOD FACTOR Z U";

int SpMatrix_Check(void *obj);
int Matrix_Check(void *obj);
void err_int_mtrx(const char *s);
void err_buf_len(const char *s);
void err_char(const char *s, const char *vals);
PyObject* PyErr_NoMemory(void);
int PyArg_ParseTupleAndKeywords(PyObject*, PyObject*, const char*, char**, ...);
PyObject* PyCapsule_New(void*, const char*, void (*)(void*));
PyObject* PyCObject_FromVoidPtrAndDesc(void*, void*, void (*)(void*));
void PyErr_SetString(void*, const char*);

#define PyExc_ValueError ((void*)1)
#define CHOL(name) name
#define PY_ERR_TYPE(msg) {return NULL;}
#define PY_ERR(exc, msg) {return NULL;}