#include <pthread.h>
#include <string.h>

typedef char *flb_sds_t;

struct mk_list {
    struct mk_list *next;
    struct mk_list *prev;
};

struct flb_hs_buf {
    int users;
    flb_sds_t data;
    void *raw_data;
    size_t raw_size;
    struct mk_list _head;
};

typedef struct mk_mq_t mk_mq_t;  // Forward declaration since actual definition isn't available

extern pthread_key_t hs_metrics_key;
extern void flb_errno(void);
extern void *flb_malloc(size_t size);
extern void mk_list_init(struct mk_list *list);
extern flb_sds_t flb_msgpack_raw_to_json_sds(void *data, size_t size);
extern void flb_sds_destroy(flb_sds_t s);
extern void mk_list_add(struct mk_list *new, struct mk_list *head);
extern void cleanup_metrics(void);