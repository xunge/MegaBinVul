#include <unistd.h>

#define MK_TRUE 1

struct session_request {
    int fd_file;
    int fd_is_fdt;
    struct {
        char *location;
    } headers;
    struct {
        char *data;
    } uri_processed;
    struct {
        char *data;
    } uri;
    struct {
        char *data;
    } real_path;
    char real_path_static[1];
};

void mk_vhost_close(struct session_request *sr);
void mk_mem_free(void *ptr);
void mk_ptr_free(void *ptr);