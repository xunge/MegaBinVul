#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

typedef int ci_off_t;

struct http_info {
    char *url;
    char *method;
};

typedef struct {
    char *url;
    char *user;
    char *clientip;
    void *body;
    int blocked;
} av_req_data_t;

typedef struct {
    char *request_header;
} ci_request_t;

typedef struct {
    // Define as needed for headers list
} ci_headers_list_t;

#define CI_ERROR -1
#define CI_MOD_ALLOW204 0
#define CI_MOD_CONTINUE 1

#define TRUSTUSER ""
#define WHITELIST ""
#define ABORT ""
#define ABORTCONTENT ""
#define MAX_URL_SIZE 1024
#define SEND_PERCENT_BYTES -1
#define START_SEND_AFTER 0

extern int dnslookup;
extern int usepipe;
extern int maxsize;
extern int logredir;
extern char *squidguard;
extern FILE *sgfpw;
extern FILE *sgfpr;

extern void ci_debug_printf(int level, const char *format, ...);
extern ci_headers_list_t *ci_http_request_headers(ci_request_t *req);
extern char *ci_headers_value(char *headers, const char *name);
extern int simple_pattern_compare(const char *str, const char *pattern);
extern int client_pattern_compare(const char *ip, const char *name);
extern int extract_http_info(ci_request_t *req, ci_headers_list_t *headers, struct http_info *httpinf);
extern av_req_data_t *ci_service_data(ci_request_t *req);
extern char *http_content_type(ci_request_t *req);
extern ci_off_t ci_http_content_length(ci_request_t *req);
extern int ci_req_hasbody(ci_request_t *req);
extern int ci_req_hasalldata(ci_request_t *req);
extern void ci_req_unlock_data(ci_request_t *req);
extern void *ci_buffer_alloc(size_t size);
extern void *ci_simple_file_new(int flags);
extern int ci_simple_file_write(void *file, const char *buf, int len, int all);
extern void ci_simple_file_lock_all(void *file);
extern void generate_redirect_page(char *url, ci_request_t *req, av_req_data_t *data);
extern void xfree(void *ptr);