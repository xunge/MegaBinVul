#include <stddef.h>
#include <assert.h>
#include <stdbool.h>

typedef struct sd_bus sd_bus;
typedef struct sd_bus_message sd_bus_message;
typedef struct sd_bus_slot sd_bus_slot;
typedef struct sd_event sd_event;
typedef struct sd_event_source sd_event_source;

typedef struct sd_bus_error {
    const char *name;
    const char *message;
    int _need_free;
} sd_bus_error;

#define SD_BUS_ERROR_NULL { NULL, NULL, 0 }
#define SD_EVENT_PRIORITY_IDLE 0
#define SD_EVENT_ONESHOT 0

#define _cleanup_(x) __attribute__((cleanup(x)))
static void sd_bus_error_free(sd_bus_error *error) {}

typedef struct AsyncPolkitQuery {
    sd_bus_slot *slot;
    sd_bus_message *request;
    sd_bus_message *reply;
    sd_event_source *defer_event_source;
    int (*callback)(sd_bus_message *m, void *userdata, sd_bus_error *error);
    void *userdata;
} AsyncPolkitQuery;

static void async_polkit_query_free(AsyncPolkitQuery *q) {}
static int async_polkit_defer(sd_event_source *s, void *userdata) { return 0; }
static int bus_maybe_reply_error(sd_bus_message *m, int r, sd_bus_error *error) { return 0; }