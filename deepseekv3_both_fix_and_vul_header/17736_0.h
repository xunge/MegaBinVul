#include <string.h>

typedef enum {
    HTTP_SUCCESS
} http_status_t;

typedef struct {
    char *pathquery;
} uri_type;

typedef struct service_info {
    char *eventURL;
    struct service_info *next;
} service_info;

typedef struct {
    service_info *serviceList;
} service_table;

int parse_uri(const char *uri, size_t len, uri_type *parsed);
int token_cmp(uri_type *a, uri_type *b);