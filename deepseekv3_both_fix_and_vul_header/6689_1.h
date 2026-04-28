#include <stddef.h>
#include <string.h>

struct tr_list {
    void* data;
    struct tr_list* next;
};

typedef struct tr_rpc_server {
    char* whitelistStr;
    struct tr_list whitelist;
} tr_rpc_server;

extern void* tr_list_pop_front(struct tr_list*);
extern void tr_list_append(struct tr_list*, void*);
extern char* tr_strdup(const char*);
extern char* tr_strndup(const char*, size_t);
extern void tr_free(void*);
extern void tr_logAddNamedInfo(const char*, const char*, ...);

#define MY_NAME ""