#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct HttpRequest HttpRequest;
typedef struct HttpResponse HttpResponse;

extern char *CssData;
extern unsigned char *FaviconData;
extern size_t FaviconDataLen;

void util_dehttpize(char *str);
HttpResponse *http_response_new(HttpRequest *req);
char *http_request_get_path_info(HttpRequest *req);
char *http_request_get_query_string(HttpRequest *req);
char *http_request_param_get(HttpRequest *req, const char *name);
void http_response_set_content_type(HttpResponse *res, const char *type);
void http_response_printf(HttpResponse *res, const char *format, ...);
void http_response_set_data(HttpResponse *res, const void *data, size_t len);
void http_response_send(HttpResponse *res);
void http_response_set_status(HttpResponse *res, int code, const char *status);
void wiki_redirect(HttpResponse *res, const char *url);
void wiki_handle_rest_call(HttpRequest *req, HttpResponse *res, const char *page);
void wiki_show_changes_page(HttpResponse *res);
void wiki_show_changes_page_rss(HttpResponse *res);
void wiki_show_search_results_page(HttpResponse *res, const char *expr);
void wiki_show_create_page(HttpResponse *res);
void file_write(const char *path, const char *content);
char *file_read(const char *path);
void wiki_show_edit_page(HttpResponse *res, const char *wikitext, const char *page);
void wiki_show_page(HttpResponse *res, const char *wikitext, const char *page);