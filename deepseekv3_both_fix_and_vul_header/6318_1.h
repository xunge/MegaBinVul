#include <stdlib.h>
#include <string.h>

#define UNUSED(x) (void)(x)
#define U_OK 0
#define Y_LOG_LEVEL_ERROR 1

struct connection_info_struct {
    int callback_first_iteration;
    void *u_instance;
    void *map_url_initial;
    struct _u_request *request;
    size_t max_post_param_size;
};

struct _u_request {
    char *http_url;
    char *url_path;
};

void *o_malloc(size_t size);
void o_free(void *ptr);
char *o_strdup(const char *str);
char *o_strndup(const char *str, size_t n);
char *o_strchr(const char *str, int c);
void u_map_init(void **map);
int ulfius_init_request(struct _u_request *request);
void ulfius_clean_request_full(struct _u_request *request);
void y_log_message(int level, const char *message);