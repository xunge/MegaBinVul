#include <string.h>

typedef long int_t;
typedef struct { double re, im; } complex_t;

typedef struct {
    void* super;
    void* pi;
    void* px;
    void* x;
    int xtype;
    int minor;
    int n;
    int is_ll;
    int is_super;
    int nsuper;
} cholmod_factor;

typedef struct _object {
    int _ob_refcnt;
    struct _typeobject *_ob_type;
} PyObject;

typedef struct {
    PyObject _ob_base;
    int_t nrow;
    int_t ncol;
    int id;
    void *buf;
} matrix;

#define DOUBLE 1
#define COMPLEX 2
#define CHOLMOD_PATTERN 0
#define CHOLMOD_REAL 1
#define MAT_ID(m) (((matrix *)m)->id)
#define MAT_BUFD(m) ((double *)((matrix *)m)->buf)
#define MAT_BUFZ(m) ((complex_t *)((matrix *)m)->buf)

static const char strCFDL[] = "CHOLMOD FACTOR DL";
static const char strCFDU[] = "CHOLMOD FACTOR DU";
static const char strCFZL[] = "CHOLMOD FACTOR ZL";
static const char strCFZU[] = "CHOLMOD FACTOR ZU";

static PyObject* PyExc_ValueError;

int PyArg_ParseTuple(PyObject*, const char*, ...);
int PyCObject_Check(PyObject*);
char* PyCObject_GetDesc(PyObject*);
void* PyCObject_AsVoidPtr(PyObject*);
void err_CO(const char*);
void PY_ERR_TYPE(const char*);
void PY_ERR(PyObject*, const char*);

extern int set_options(void);
extern matrix* Matrix_New(int_t nrow, int_t ncol, int id);
extern void dcopy_(int *n, double *x, int *incx, double *y, int *incy);
extern void zcopy_(int *n, complex_t *x, int *incx, complex_t *y, int *incy);