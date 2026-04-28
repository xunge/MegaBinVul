#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

#define BUF_SIZE 1024

struct list_head {
    struct list_head *next, *prev;
};

struct rad_dict_value_t {
    union {
        int integer;
        char *string;
    } val;
    char *name;
    struct list_head entry;
};

struct rad_dict_attr_t {
    char *name;
    int id;
    int type;
    int size;
    int array;
    struct list_head values;
    struct list_head tlv;
    struct list_head entry;
};

struct rad_dict_vendor_t {
    char *name;
    int id;
    unsigned int tag;
    unsigned int len;
    struct list_head items;
    struct list_head entry;
};

enum {
    ATTR_TYPE_INTEGER,
    ATTR_TYPE_STRING,
    ATTR_TYPE_DATE,
    ATTR_TYPE_IPADDR,
    ATTR_TYPE_OCTETS,
    ATTR_TYPE_IFID,
    ATTR_TYPE_IPV6ADDR,
    ATTR_TYPE_IPV6PREFIX,
    ATTR_TYPE_ETHER,
    ATTR_TYPE_TLV
};

static char buf[BUF_SIZE];
static char path[PATH_MAX];
static char fname1[PATH_MAX];
static struct {
    struct list_head items;
    struct list_head vendors;
} *dict;

#define INIT_LIST_HEAD(ptr) do { \
    (ptr)->next = (ptr); (ptr)->prev = (ptr); \
} while (0)

static inline void list_add_tail(struct list_head *new, struct list_head *head)
{
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}

static void log_emerg(const char *fmt, ...) {}
static void log_warn(const char *fmt, ...) {}
static int split(char *buf, char **ptr) { return 0; }
static struct rad_dict_vendor_t *rad_dict_find_vendor_name(const char *name) { return NULL; }
static struct rad_dict_attr_t *find_attr(struct list_head *items, const char *name) { return NULL; }