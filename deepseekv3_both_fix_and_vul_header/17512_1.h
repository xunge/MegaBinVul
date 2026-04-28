#include <sys/types.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct sd_bus sd_bus;
typedef struct sd_bus_message sd_bus_message;
typedef struct sd_bus_error sd_bus_error;
typedef struct sd_bus_slot sd_bus_slot;
typedef int (*sd_bus_message_handler_t)(sd_bus_message *m, void *userdata, sd_bus_error *ret_error);
typedef struct Hashmap Hashmap;

typedef struct AsyncPolkitQuery {
        sd_bus_message *request;
        sd_bus_message *reply;
        char *action;
        char **details;
        sd_bus_message_handler_t callback;
        void *userdata;
        sd_bus_slot *slot;
        Hashmap *registry;
} AsyncPolkitQuery;