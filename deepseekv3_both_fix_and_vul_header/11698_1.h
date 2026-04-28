#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <errno.h>
#include <string.h>
#include <syslog.h>

extern char *stats_file;
extern void log_message(int level, const char *fmt, ...);
extern FILE *fopen_safe(const char *path, const char *mode);

typedef struct element {
    struct element *next;
    void *data;
} *element;

typedef struct list {
    struct element *head;
} list;

#define LIST_HEAD(l) ((l).head)
#define ELEMENT_NEXT(e) ((e)->next)
#define ELEMENT_DATA(e) ((e)->data)
#define LIST_FOREACH(l, v, e) for((e) = LIST_HEAD(l); (e); (e) = ELEMENT_NEXT(e)) if((v) = ELEMENT_DATA(e), 1)

typedef struct vrrp_stats {
    uint64_t advert_rcvd;
    int advert_sent;
    int become_master;
    int release_master;
    uint64_t packet_len_err;
    uint64_t ip_ttl_err;
    uint64_t invalid_type_rcvd;
    uint64_t advert_interval_err;
    uint64_t addr_list_err;
    int invalid_authtype;
    int authtype_mismatch;
    int auth_failure;
    uint64_t pri_zero_rcvd;
    uint64_t pri_zero_sent;
} vrrp_stats;

typedef struct vrrp_t {
    char *iname;
    vrrp_stats *stats;
} vrrp_t;

typedef struct vrrp_data_t {
    list vrrp;
} vrrp_data_t;

extern vrrp_data_t *vrrp_data;