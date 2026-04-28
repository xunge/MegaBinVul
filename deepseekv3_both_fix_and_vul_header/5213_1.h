#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct flb_input_instance {
    struct {
        char *listen;
        int port;
    } host;
};

struct mk_list {
    struct mk_list *prev;
    struct mk_list *next;
};

struct flb_in_mqtt_config {
    char *listen;
    char *tcp_port;
    struct mk_list conns;
};

void *flb_calloc(size_t nmemb, size_t size);
void *flb_malloc(size_t size);
char *flb_strdup(const char *s);
char *flb_input_get_property(const char *key, struct flb_input_instance *i_ins);
void flb_debug(const char *fmt, ...);
void flb_errno(void);
void mk_list_init(struct mk_list *list);