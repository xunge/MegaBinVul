#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <syslog.h>

#define HTTP_PORT 80
#define HTTP_PORT_SSL 443
#define TRUE 1
#define FALSE 0
#define LOG_ERR 3
#define LOG_INFO 6
#define LOG_NOTICE 5
#define PATH_MAX 4096

struct request_s {
    char *method;
    char *protocol;
    char *host;
    int port;
};

struct conn_s {
    char *request_line;
    struct {
        unsigned int major;
        unsigned int minor;
    } protocol;
    int client_fd;
    int connect_method;
    int show_stats;
};

struct config_s {
    int *connect_ports;
    char *reversepath_list;
    int reverseonly;
    int filter;
    int filter_opts;
    char *stathost;
};

extern struct config_s *config;

typedef void* orderedmap;

void *safecalloc(size_t nmemb, size_t size);
void *safemalloc(size_t size);
void safefree(void *ptr);
void log_message(int priority, const char *format, ...);
void indicate_http_error(struct conn_s *connptr, int code, const char *message, ...);
int UPSTREAM_CONFIGURED(void);
int extract_url(char *url, int port, struct request_s *request);
int check_allowed_connect_ports(int port, int *allowed_ports);
void free_request_struct(struct request_s *request);