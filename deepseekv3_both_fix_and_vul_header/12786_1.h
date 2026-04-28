#include <stddef.h>

struct Curl_llist_node {
    void *ptr;
    struct Curl_llist_node *prev;
    struct Curl_llist_node *next;
};

struct Curl_llist {
    struct Curl_llist_node *head;
    struct Curl_llist_node *tail;
    size_t size;
};

struct connectdata {
    struct Curl_llist easyq;
};

struct Curl_easy {
    struct connectdata *conn;
    struct Curl_llist_node conn_queue;
};

void Curl_llist_remove(struct Curl_llist *list, struct Curl_llist_node *element, void *user);