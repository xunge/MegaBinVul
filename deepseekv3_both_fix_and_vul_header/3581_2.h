#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <getopt.h>
#include <locale.h>
#include <string.h>
#include <fcntl.h>
#include <list>
#include <queue>
#include <wchar.h>
#include <sys/uio.h>

#define GETOPT_STRING "hv"
#define FISH_BUILD_VERSION ""

struct connection_t {
    int fd;
    bool killme;
    std::queue<struct message_t*> unsent;
    connection_t(int fd) : fd(fd), killme(false) {}
};

struct message_t {
    int count;
};

typedef std::list<connection_t> connection_list_t;

static int sock;
static bool quit;
static connection_list_t connections;
static const wchar_t *program_name;
static const char *GREETING = "";

int set_main_thread();
int setup_fork_guards();
int wsetlocale(int category, const wchar_t *locale);
void print_help(const char *name, int print_all);
void debug(int level, const wchar_t *format, ...);
void init();
void save();
int make_fd_nonblocking(int fd);
void enqueue_all(connection_t *c);
void try_send_all(connection_t *c);
void read_message(connection_t *c);
void connection_destroy(connection_t *c);
int maxi(int a, int b);
void wperror(const wchar_t *s);
int getpeereid(int fd, uid_t *euid, gid_t *egid);