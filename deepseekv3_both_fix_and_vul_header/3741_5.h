#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <time.h>
#include <errno.h>
#include <poll.h>
#include <pwd.h>
#include <sys/types.h>

#define WPANTUND_SERVICE_USER "wpantund"
#define WPAN_TUNNEL_DBUS_NAME "com.nestlabs.WPANTunnelDriver"
#define DBUS_BUS_SYSTEM 1
#define ERRORCODE_HELP 1
#define ERRORCODE_BADARG 2
#define ERRORCODE_ERRNO 3
#define ERRORCODE_NOCOMMAND 4
#define ERRORCODE_QUIT 5

struct DBusError {
    const char *name;
    const char *message;
};

struct DBusConnection;

typedef struct DBusError DBusError;
typedef struct DBusConnection DBusConnection;

extern int gRet;
extern int gDebugMode;
extern char gInterfaceName[100];
extern int istty;
extern struct option option_list[];

void print_version(void);
void print_arg_list_help(struct option *opts, const char *name, const char *help);
void print_commands(void);
int find_cmd(const char *cmd);
int exec_command(int argc, char *argv[]);
int wpan_dbus_version_check(DBusConnection *connection);
void process_input_line(char *line);

static inline void dbus_error_init(DBusError *error) { error->name = NULL; error->message = NULL; }
static inline void dbus_error_free(DBusError *error) { }
static inline DBusConnection* dbus_bus_get(int type, DBusError *error) { return NULL; }
static inline int dbus_bus_register(DBusConnection *connection, DBusError *error) { return 0; }
static inline int dbus_bus_request_name(DBusConnection *connection, const char *name, unsigned int flags, DBusError *error) { return 0; }
static inline void dbus_connection_unref(DBusConnection *connection) { }
static inline void dbus_connection_read_write_dispatch(DBusConnection *connection, int timeout_milliseconds) { }
static inline int dbus_connection_get_unix_fd(DBusConnection *connection, int *fd) { return -1; }

#define require_string(cond, label, msg) do { if (!(cond)) { fprintf(stderr, "Error: %s\n", msg); goto label; } } while(0)