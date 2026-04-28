#include <stdlib.h>

typedef struct sd_bus_slot sd_bus_slot;
typedef struct sd_bus_message sd_bus_message;
typedef struct sd_event_source sd_event_source;
typedef struct Hashmap Hashmap;

typedef struct AsyncPolkitQuery {
        sd_bus_slot *slot;
        Hashmap *registry;
        sd_bus_message *request;
        sd_bus_message *reply;
        char *action;
        char **details;
        sd_event_source *defer_event_source;
} AsyncPolkitQuery;