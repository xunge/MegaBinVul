#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

typedef struct {
    int socket;
    char *servename;
} SERVER;

typedef struct {
    SERVER *server;
} CLIENT;

typedef struct {
    size_t len;
    void *data;
} GArray;

typedef struct {
    char *message;
} GError;

GArray *modernsocks;
int is_sighup_caught;

#define LOG_INFO 0
#define LOG_ERR 1
#define NEG_INIT 1
#define NEG_MODERN 2

#define g_array_index(array, type, index) (((type*)(array)->data)[index])

int append_new_servers(GArray *servers, GError **gerror);
void msg(int level, const char *format, ...);
void err_nonfatal(const char *format, ...);
void DEBUG(const char *format, ...);
CLIENT *negotiate(int net, void *arg, GArray *servers, int flags);
void handle_connection(GArray *servers, int net, SERVER *serve, CLIENT *client);