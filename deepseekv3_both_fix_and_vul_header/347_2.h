#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <net/if.h>

typedef enum {
    ACL_DENY,
    ACL_DENY_ALL,
    ACL_ALLOW,
    ACL_ALLOW_ALL
} ACLType;

typedef struct ACLRule {
    ACLType type;
    char iface[IFNAMSIZ];
    struct ACLRule *next;
} ACLRule;

typedef struct ACLList {
    ACLRule *first;
    ACLRule *last;
} ACLList;

#define g_malloc malloc
#define QSIMPLEQ_INSERT_TAIL(head, elm, field) do { \
    (elm)->next = NULL; \
    if ((head)->first == NULL) { \
        (head)->first = (elm); \
    } else { \
        (head)->last->next = (elm); \
    } \
    (head)->last = (elm); \
} while (0)