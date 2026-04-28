#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <assert.h>
#include <grp.h>
#include <pthread.h>

typedef long Py_ssize_t;
typedef struct _object PyObject;
#define Py_None ((PyObject*)0)

#define Py_NO_INLINE
#define POSIX_CALL(x) do { if ((x) == -1) goto error; } while (0)
#define _Py_IS_TYPE_SIGNED(x) (1)
#define VFORK_USABLE
#define HAVE_SETSID
#define HAVE_SETPGID
#define HAVE_SETGROUPS
#define HAVE_SETREGID
#define HAVE_SETREUID

extern int make_inheritable(int *fds_to_keep, Py_ssize_t fds_to_keep_len, int errpipe_write);
extern int _Py_set_inheritable_async_safe(int fd, int inheritable, int *atomic_flag_works);
extern void _Py_RestoreSignals(void);
extern void reset_signal_handlers(const void *sigmask);
extern void _close_open_fds(int fd, int *fds_to_keep, Py_ssize_t fds_to_keep_len);
extern ssize_t _Py_write_noraise(int fd, const void *buf, size_t count);
extern const char Py_hexdigits[];
extern PyObject* PyObject_Call(PyObject *callable, PyObject *args, PyObject *kwargs);