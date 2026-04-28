#include <stdlib.h>
#include <unistd.h>

struct mk_list {
    struct mk_list *prev;
    struct mk_list *next;
};

struct mk_event {
    int fd;
    int type;
    int mask;
    void (*handler)(void);
    int status;
};

struct flb_in_mqtt_config {
    void *evl;
    struct mk_list conns;
};

struct mqtt_conn {
    struct mk_event event;
    int fd;
    struct flb_in_mqtt_config *ctx;
    size_t buf_pos;
    size_t buf_len;
    size_t buf_frame_end;
    int status;
    struct mk_list _head;
};

enum {
    FLB_ENGINE_EV_CUSTOM,
    MK_EVENT_EMPTY,
    MK_EVENT_NONE,
    MK_EVENT_READ,
    MQTT_NEW
};

void *flb_malloc(size_t size);
void flb_errno();
void flb_error(const char *msg);
void flb_free(void *ptr);
int mk_event_add(void *evl, int fd, int type, int mask, void *data);
void mk_list_add(struct mk_list *new, struct mk_list *head);
void mqtt_conn_event(void);