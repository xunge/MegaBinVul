#include <string.h>
#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

#define list_for_each_entry(pos, head, member) \
    for (pos = (typeof(pos))((char *)(head)->next - offsetof(typeof(*pos), member)); \
         &pos->member != (head); \
         pos = (typeof(pos))((char *)pos->member.next - offsetof(typeof(*pos), member)))

typedef struct Sg_request {
    struct list_head entry;
    int done;
    struct {
        unsigned int masked_status;
        unsigned int host_status;
        unsigned int driver_status;
        unsigned int duration;
        int pack_id;
        void *usr_ptr;
    } header;
    int orphan;
    int sg_io_owned;
} Sg_request;

typedef struct Sg_fd {
    struct list_head rq_list;
} Sg_fd;

typedef struct {
    int req_state;
    int problem;
    unsigned int duration;
    int orphan;
    int sg_io_owned;
    int pack_id;
    void *usr_ptr;
} sg_req_info_t;

#define SG_MAX_QUEUE 16
#define SZ_SG_REQ_INFO sizeof(sg_req_info_t)

unsigned int jiffies;
static inline unsigned int jiffies_to_msecs(unsigned long j) {
    return j * 10;
}