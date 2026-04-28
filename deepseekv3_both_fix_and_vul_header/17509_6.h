#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct sd_bus sd_bus;
typedef struct sd_bus_message sd_bus_message;
typedef struct sd_bus_slot sd_bus_slot;
typedef struct sd_event sd_event;
typedef struct sd_event_source sd_event_source;

struct sd_bus_error {
    const char *name;
    const char *message;
    int _need_free;
};
typedef struct sd_bus_error sd_bus_error;

typedef struct AsyncPolkitQuery {
    sd_bus_slot *slot;
    sd_bus_message *request;
    sd_bus_message *reply;
    sd_event_source *defer_event_source;
} AsyncPolkitQuery;

#define SD_BUS_ERROR_NULL { NULL, NULL, 0 }
#define SD_EVENT_PRIORITY_IDLE 0
#define SD_EVENT_ONESHOT 0

#define _cleanup_(x) __attribute__((cleanup(x)))

static void sd_bus_error_free(sd_bus_error *e) {}
static sd_bus_slot *sd_bus_slot_unref(sd_bus_slot *s) { return NULL; }
static sd_bus_message *sd_bus_message_ref(sd_bus_message *m) { return NULL; }
static sd_event *sd_bus_get_event(sd_bus *b) { return NULL; }
static sd_bus *sd_bus_message_get_bus(sd_bus_message *m) { return NULL; }
static int sd_event_add_defer(sd_event *e, sd_event_source **s, void (*cb)(sd_event_source*, void*), void *u) { return 0; }
static int sd_event_source_set_priority(sd_event_source *s, int p) { return 0; }
static int sd_event_source_set_enabled(sd_event_source *s, int m) { return 0; }
static int sd_bus_message_rewind(sd_bus_message *m, bool b) { return 0; }
static int sd_bus_enqeue_for_read(sd_bus *b, sd_bus_message *m) { return 0; }
static void log_debug_errno(int e, const char *m) {}
static int sd_bus_reply_method_errno(sd_bus_message *m, int e, void *u) { return 0; }
static void async_polkit_query_free(AsyncPolkitQuery *q) {}
static void async_polkit_defer(sd_event_source *s, void *u) {}