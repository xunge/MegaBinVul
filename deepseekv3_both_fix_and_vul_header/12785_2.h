#include <assert.h>

#define DEBUGASSERT(x) assert(x)

struct Curl_easy {
    struct connectdata *conn;
    void *conn_queue;
};

struct Curl_llist_node {
    void *ptr;
    struct Curl_llist_node *next;
    struct Curl_llist_node *prev;
};

struct Curl_llist {
    struct Curl_llist_node *head;
    struct Curl_llist_node *tail;
};

struct Curl_handler {
    void (*attach)(struct Curl_easy *data, struct connectdata *conn);
};

struct connectdata {
    struct Curl_handler *handler;
    struct Curl_llist easyq;
};

void Curl_llist_insert_next(struct Curl_llist *list, void *tail, void *data, void *element);