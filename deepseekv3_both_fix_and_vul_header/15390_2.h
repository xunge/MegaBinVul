#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <pthread.h>
#include <stdlib.h>

#define Py_ssize_t int
#define PyObject void
#define Py_None NULL
#define MAX_GROUPS 32
#define HAVE_SETGROUPS
#define HAVE_SETREGID
#define HAVE_SETREUID
#define VFORK_USABLE

#define PyExc_RuntimeError ((PyObject*)1)
#define PyExc_ValueError ((PyObject*)2)
#define PyExc_TypeError ((PyObject*)3)
#define PyExc_MemoryError ((PyObject*)4)
#define PyExc_OSError ((PyObject*)5)

struct _PyInterpreterState {
    int finalizing;
};
typedef struct _PyInterpreterState PyInterpreterState;

static PyInterpreterState* _PyInterpreterState_GET(void) { return NULL; }
static PyInterpreterState* PyInterpreterState_Main(void) { return NULL; }
static int PyGC_Disable(void) { return 0; }
static void PyGC_Enable(void) {}
static int PyTuple_GET_SIZE(PyObject *t) { return 0; }
static int PyList_Check(PyObject *o) { return 0; }
static int PySequence_Size(PyObject *o) { return 0; }
static PyObject* PySequence_GetItem(PyObject *o, int i) { return NULL; }
static int PyLong_Check(PyObject *o) { return 0; }
static void Py_DECREF(PyObject *o) {}
static void Py_XDECREF(PyObject *o) {}
static void Py_CLEAR(PyObject *o) {}
static void PyErr_SetString(PyObject *type, const char *msg) {}
static void PyErr_SetFromErrno(PyObject *type) {}
static void PyErr_BadInternalCall(void) {}
static PyObject* PyLong_FromPid(pid_t pid) { return NULL; }
static PyObject* PySequence_Fast(PyObject *o, const char *msg) { return NULL; }
static int PySequence_Fast_GET_SIZE(PyObject *o) { return 0; }
static PyObject* PySequence_Fast_GET_ITEM(PyObject *o, int i) { return NULL; }
static PyObject* PyTuple_New(int size) { return NULL; }
static void PyTuple_SET_ITEM(PyObject *t, int pos, PyObject *o) {}
static int PyUnicode_FSConverter(PyObject *obj, PyObject **result) { return 0; }
static char* PyBytes_AsString(PyObject *o) { return NULL; }
static int _Py_Gid_Converter(PyObject *obj, gid_t *gid) { return 0; }
static int _Py_Uid_Converter(PyObject *obj, uid_t *uid) { return 0; }
static int _sanity_check_python_fd_sequence(PyObject *obj) { return 0; }
static int convert_fds_to_keep_to_c(PyObject *py_fds, int *c_fds) { return 0; }
static char** _PySequence_BytesToCharpArray(PyObject *obj) { return NULL; }
static void _Py_FreeCharPArray(char **array) {}
static void PyOS_BeforeFork(void) {}
static void PyOS_AfterFork_Parent(void) {}
static void* PyMem_RawMalloc(size_t size) { return malloc(size); }
static void PyMem_RawFree(void *ptr) { free(ptr); }
static void* PyMem_Malloc(size_t size) { return malloc(size); }
static void PyMem_Free(void *ptr) { free(ptr); }

static pid_t do_fork_exec(char *const *exec_array, char *const *argv, char *const *envp, const char *cwd,
                         int p2cread, int p2cwrite, int c2pread, int c2pwrite,
                         int errread, int errwrite, int errpipe_read, int errpipe_write,
                         int close_fds, int restore_signals, int call_setsid, pid_t pgid_to_set,
                         gid_t gid, Py_ssize_t extra_group_size, gid_t *extra_groups,
                         uid_t uid, int child_umask, const void *old_sigmask,
                         int *c_fds_to_keep, Py_ssize_t fds_to_keep_len,
                         PyObject *preexec_fn, PyObject *preexec_fn_args_tuple) { return -1; }