#include <unistd.h>
#include <stdlib.h>

struct mk_event_loop;

struct mk_event {
    int fd;
    int mask;
    void *data;
};

struct mk_list {
    struct mk_list *next;
    struct mk_list *prev;
};

struct mqtt_ctx {
    struct mk_event_loop *evl;
};

struct mqtt_conn {
    struct mqtt_ctx *ctx;
    struct mk_event event;
    int fd;
    struct mk_list _head;
};

void mk_event_del(struct mk_event_loop *evl, struct mk_event *event);
void mk_list_del(struct mk_list *list);
void flb_free(void *ptr);