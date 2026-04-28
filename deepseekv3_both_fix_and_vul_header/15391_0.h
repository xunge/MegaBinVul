#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>
#include <assert.h>
#include <pthread.h>

#define POSIX_CALL(call) do { if ((call) == -1) goto error; } while (0)
#define Py_NO_INLINE
#define Py_ssize_t long
#define PyObject void
#define Py_None NULL
#define Py_hexdigits "0123456789abcdef"
#define _Py_IS_TYPE_SIGNED(type) ((type)-1 < (type)0)
#define _Py_set_inheritable_async_safe(fd, inheritable, filename) (-1)
#define _Py_RestoreSignals()
#define _Py_write_noraise(fd, buf, count) write(fd, buf, count)
#define VFORK_USABLE
#define HAVE_SETSID
#define HAVE_SETPGID
#define HAVE_SETGROUPS
#define HAVE_SETREGID
#define HAVE_SETREUID

typedef int pid_t;
typedef unsigned int uid_t;
typedef unsigned int gid_t;