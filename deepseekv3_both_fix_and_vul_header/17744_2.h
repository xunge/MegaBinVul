#include <sys/types.h>
#include <sys/socket.h>
#include <sys/uio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <alloca.h>
#include <stdbool.h>

typedef struct {
    int fd;
} DBusSocket;

typedef struct {
    char *data;
    int len;
    int allocated;
} DBusString;

typedef bool dbus_bool_t;
#define TRUE true
#define FALSE false

#define DBUS_MAXIMUM_MESSAGE_UNIX_FDS 16
#define HAVE_UNIX_FD_PASSING 1
#define _DBUS_LIKELY(expr) (expr)
#define _DBUS_STATIC_ASSERT(expr)
#define _DBUS_ZERO(var) memset(&(var), 0, sizeof(var))

int _dbus_read_socket(DBusSocket fd, DBusString *buffer, int count);
void _dbus_assert(int condition);
int _dbus_string_get_length(DBusString *buffer);
int _dbus_string_lengthen(DBusString *buffer, int count);
void _dbus_string_set_length(DBusString *buffer, int length);
void* _dbus_string_get_data_len(DBusString *buffer, int start, int count);
void _dbus_fd_set_close_on_exec(int fd);