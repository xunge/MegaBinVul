#include <stdlib.h>

typedef struct _GSocketClientAsyncConnectData GSocketClientAsyncConnectData;
struct _GSocketClientAsyncConnectData {
    void *task;
    void *connectable;
    void *enumerator;
    void *proxy_addr;
    void *socket;
    void *connection;
    struct GSList *connection_attempts;
    void *last_error;
};

typedef struct _ConnectionAttempt ConnectionAttempt;
struct _ConnectionAttempt {
    int ref_count;
};

struct GSList {
    void *data;
    struct GSList *next;
};

static void connection_attempt_unref(void *attempt) {
    ConnectionAttempt *ca = (ConnectionAttempt *)attempt;
    if (--ca->ref_count == 0)
        free(ca);
}

static void g_clear_object(void **object_ptr) {
    *object_ptr = NULL;
}

static void g_clear_error(void **error_ptr) {
    *error_ptr = NULL;
}

static void g_slist_free_full(struct GSList *list, void (*free_func)(void*)) {
    while (list) {
        struct GSList *next = list->next;
        free_func(list->data);
        free(list);
        list = next;
    }
}

#define g_slice_free(type, ptr) free(ptr)