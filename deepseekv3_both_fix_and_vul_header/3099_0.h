#include <stddef.h>

typedef struct RingItem RingItem;
typedef struct RedChannel RedChannel;
typedef struct RedChannelClient RedChannelClient;

struct RingItem {
    RingItem *next;
    RingItem *prev;
};

#define RING_FOREACH_SAFE(var, next, head) \
    for ((var) = (head)->next; (next) = (var)->next, (var) != (head); (var) = (next))

#define RING_FOREACH(var, head) \
    for ((var) = (head)->next; (var) != (head); (var) = (var)->next)

#define SPICE_CONTAINEROF(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

struct RedChannel {
    RingItem clients;
};

struct RedChannelClient {
    RingItem channel_link;
};

void red_channel_client_pipe_add_empty_msg(RedChannelClient *client, int msg_type);