#include <unistd.h>
#include <stddef.h>
#include <wchar.h>

typedef struct {
    wchar_t *wide;
    char *narrow;
} path_t;

#define DEFAULT_DIR_FD (-1)
#define HAVE_SYMLINKAT 1

typedef unsigned long DWORD;

struct _object;
typedef struct _object PyObject;

extern int win32_can_symlink;
extern int check_CreateSymbolicLink(void);
extern int Py_CreateSymbolicLinkW(const wchar_t *, const wchar_t *, int);
extern int _check_dirW(const wchar_t *, const wchar_t *);
extern PyObject *path_error2(path_t *, path_t *);

#define Py_BEGIN_ALLOW_THREADS
#define Py_END_ALLOW_THREADS
#define _Py_BEGIN_SUPPRESS_IPH
#define _Py_END_SUPPRESS_IPH
#define Py_RETURN_NONE return NULL
#define PyExc_NotImplementedError ((PyObject*)0)
#define PyExc_OSError ((PyObject*)0)
#define PyExc_ValueError ((PyObject*)0)
#define PyErr_SetString(a, b)