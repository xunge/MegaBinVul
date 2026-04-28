#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define VALUE_MAXLEN 255
#define NOTUNDERSTOOD "notunderstood"
#define GFP_KERNEL 0

struct list_head {
    struct list_head *next, *prev;
};

struct iscsi_extra_response {
    char key[256];
    char value[256];
    struct list_head er_list;
};

struct iscsi_param_list {
    struct list_head extra_response_list;
};

static inline void INIT_LIST_HEAD(struct list_head *list)
{
    list->next = list;
    list->prev = list;
}

static inline void list_add_tail(struct list_head *new, struct list_head *head)
{
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}

#define kzalloc(size, flags) calloc(1, size)
#define pr_err(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)