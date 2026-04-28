#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

typedef struct HttpRequest HttpRequest;
typedef struct HttpResponse HttpResponse;
typedef struct WikiPageList {
    char *name;
    time_t mtime;
} WikiPageList;

char *http_request_param_get(HttpRequest *req, const char *param);
char *http_request_get_query_string(HttpRequest *req);
void http_response_printf(HttpResponse *res, const char *format, ...);
void http_response_send(HttpResponse *res);
void http_response_set_status(HttpResponse *res, int code, const char *message);
char *file_read(const char *path);
void file_write(const char *path, const char *content);
WikiPageList **wiki_get_pages(int *n_pages, const char *expr);