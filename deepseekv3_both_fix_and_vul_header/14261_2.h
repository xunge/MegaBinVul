#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef struct Mono_Time Mono_Time;

enum {
    TCP_STATUS_NO_STATUS,
    TCP_STATUS_CONFIRMED
};

typedef struct TCP_Secure_Connection {
    uint8_t public_key[32];
    int status;
    uint32_t identifier;
    uint64_t last_pinged;
    uint64_t ping_id;
} TCP_Secure_Connection;

typedef struct bs_list {
    uint8_t *keys;
    int *values;
    uint32_t size;
    uint32_t capacity;
} bs_list;

typedef struct TCP_Server {
    TCP_Secure_Connection *accepted_connection_array;
    bs_list accepted_key_list;
    uint32_t size_accepted_connections;
    uint32_t num_accepted_connections;
    uint32_t counter;
} TCP_Server;

static int bs_list_add(bs_list *list, const uint8_t *key, int value);
static int get_TCP_connection_index(TCP_Server *tcp_server, const uint8_t *public_key);
static void kill_accepted(TCP_Server *tcp_server, int index);
static int realloc_connection(TCP_Server *tcp_server, uint32_t new_size);
static uint64_t mono_time_get(const Mono_Time *mono_time);