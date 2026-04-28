#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/times.h>
#include <sys/time.h>

#define FPM_LOG_BUFFER 1024
#define ZLOG_WARNING 1
#define ZLOG_NOTICE 2

struct fcgi_request {
    void *server_context;
};

struct fpm_scoreboard_proc_s {
    struct timeval duration;
    struct timeval cpu_duration;
    struct tms last_request_cpu;
    char script_filename[128];
    char request_method[16];
    char query_string[128];
    char request_uri[128];
    char auth_user[32];
    size_t content_length;
    size_t memory;
    time_t accepted_epoch;
};

struct fpm_scoreboard_s {
    char pool[32];
};

struct sapi_header_struct {
    char *header;
    size_t header_len;
};

struct zend_llist_element {
    struct zend_llist_element *next;
    struct zend_llist_element *prev;
    char data[1];
};

struct zend_llist {
    size_t count;
    struct zend_llist_element *head;
    struct zend_llist_element *tail;
    void *dtor;
    size_t size;
};

struct zend_llist_position {
    struct zend_llist_element *pos;
};

struct sapi_headers_struct {
    int http_response_code;
    struct zend_llist headers;
};

struct _zend_sapi_globals_struct {
    struct sapi_headers_struct sapi_headers;
    void *server_context;
};

extern struct _zend_sapi_globals_struct sapi_globals;
#define SG(v) (sapi_globals.v)

extern char *fpm_log_format;
extern int fpm_log_fd;

extern struct fpm_scoreboard_s *fpm_scoreboard_get();
extern struct fpm_scoreboard_proc_s *fpm_scoreboard_proc_acquire(struct fpm_scoreboard_s *, int, int);
extern void fpm_scoreboard_proc_release(struct fpm_scoreboard_proc_s *);
extern float fpm_scoreboard_get_tick();
extern void zlog(int level, const char *format, ...);
extern char *fcgi_getenv(struct fcgi_request *, char *, size_t);
extern const char *fcgi_get_last_client_ip();
extern void *zend_llist_get_first_ex(struct zend_llist *, struct zend_llist_position *);
extern void *zend_llist_get_next_ex(struct zend_llist *, struct zend_llist_position *);

typedef struct sapi_header_struct sapi_header_struct;
typedef struct zend_llist_position zend_llist_position;
typedef struct sapi_headers_struct sapi_headers_struct;
typedef struct fcgi_request fcgi_request;