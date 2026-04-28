#include <stddef.h>

typedef struct RingItem RingItem;

struct RingItem {
    RingItem *next;
    RingItem *prev;
};

typedef struct RedChannel RedChannel;
typedef struct RedChannelClient RedChannelClient;

struct RedChannel {
    RingItem clients;
};

struct RedChannelClient {
    RingItem channel_link;
};

void red_channel_client_pipe_add_type(RedChannelClient *client, int pipe_item_type);
void red_channel_pipes_add_type(RedChannel *channel, int pipe_item_type);

#define RING_FOREACH_SAFE(var, next, head) \
    for ((var) = (head)->next; (var) != (head) && ((next) = (var)->next, 1); (var) = (next))

#define RING_FOREACH(var, head) \
    for ((var) = (head)->next; (var) != (head); (var) = (var)->next)

#define SPICE_CONTAINEROF(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))