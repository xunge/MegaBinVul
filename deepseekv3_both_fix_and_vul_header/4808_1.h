#include <stdbool.h>
#include <stddef.h>

struct ndp_msg {
    void *addrto;
};

enum ndp_msg_type {
    NDP_MSG_TYPE_UNKNOWN
};

struct ndp_msg_type_info {
    size_t raw_struct_size;
    bool (*addrto_validate)(const void *);
};

size_t ndp_msg_payload_len(struct ndp_msg *msg);
enum ndp_msg_type ndp_msg_type(struct ndp_msg *msg);
struct ndp_msg_type_info *ndp_msg_type_info(enum ndp_msg_type msg_type);