#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

struct timeval time_now;

typedef struct vrrp_t vrrp_t;
typedef struct element {
    vrrp_t *next;
    vrrp_t *prev;
} element;

typedef struct {
    vrrp_t *vrrp;
} vrrp_data_t;

typedef struct {
    unsigned long alloc;
} master_t;

typedef struct {
    char *network_namespace;
    char *instance_name;
} global_data_t;

extern master_t *master;
extern vrrp_data_t *vrrp_data;
extern global_data_t *global_data;
extern char *make_file_name(const char *path, const char *type, const char *ns, const char *instance);
extern void set_time_now(void);
extern void dump_thread_data(master_t *master, FILE *fp);

#define FREE(ptr) free(ptr)

enum {
    VRRP_STATE_INIT,
    VRRP_STATE_BACK,
    VRRP_STATE_MAST,
    VRRP_STATE_FAULT,
    VRRP_STATE_STOP,
    VRRP_DISPATCHER
};

struct vrrp_t {
    char *iname;
    struct timeval sands;
    int state;
    element e;
};

#define LIST_FOREACH(list, var, elem) \
    for ((var) = (list); (var) != NULL; (var) = (var)->elem.next)