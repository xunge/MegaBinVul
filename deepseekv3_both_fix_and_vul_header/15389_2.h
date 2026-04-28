#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include <assert.h>
#include <grp.h>

#define POSIX_CALL(call) do { if ((call) == -1) goto error; } while (0)
#define Py_NO_INLINE
#define VFORK_USABLE
#define HAVE_SETSID
#define HAVE_SETPGID
#define HAVE_SETGROUPS
#define HAVE_SETREGID
#define HAVE_SETREUID

typedef long Py_ssize_t;
typedef struct _object PyObject;
#define Py_None ((PyObject*)0)

static const char Py_hexdigits[] = "0123456789abcdef";
#define _Py_IS_TYPE_SIGNED(type) (((type)-1) < 0)

extern int _Py_set_inheritable_async_safe(int fd, int inheritable, int *atomic_flag_works);
extern void _Py_RestoreSignals(void);
extern int make_inheritable(int *fds_to_keep, Py_ssize_t fds_to_keep_len, int errpipe_write);
extern void _close_open_fds(int start_fd, int *fds_to_keep, Py_ssize_t fds_to_keep_len);
extern int _Py_write_noraise(int fd, const char *buf, size_t count);
extern PyObject* PyObject_Call(PyObject *callable, PyObject *args, PyObject *kwargs);
extern void reset_signal_handlers(const void *sigmask);