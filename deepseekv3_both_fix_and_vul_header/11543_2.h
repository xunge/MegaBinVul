#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdbool.h>

#define NTR_MAX_SELECTION_METHOD_LEN 16

enum ofperr {
    OFPERR_OFPBPC_BAD_VALUE,
    OFPERR_OFPGMFC_BAD_TYPE,
    OFPERR_OFPGMFC_BAD_COMMAND,
    OFPERR_OFPBPC_BAD_LEN
};

enum ofp11_group_type {
    OFPGT11_SELECT,
    OFPGT11_ALL,
    OFPGT11_INDIRECT,
    OFPGT11_FF
};

enum ofp15_group_mod_command {
    OFPGC15_ADD,
    OFPGC15_MODIFY,
    OFPGC15_ADD_OR_MOD,
    OFPGC15_DELETE,
    OFPGC15_INSERT_BUCKET,
    OFPGC15_REMOVE_BUCKET
};

struct ofpbuf {
    void *data;
    size_t size;
};

struct ofputil_group_props {
    char selection_method[NTR_MAX_SELECTION_METHOD_LEN];
    uint64_t selection_method_param;
    void *fields;
};

struct ntr_group_prop_selection_method {
    char selection_method[NTR_MAX_SELECTION_METHOD_LEN];
    uint64_t selection_method_param;
    uint16_t length;
};

extern struct ofpbuf bad_ofmsg_rl;

static inline uint64_t ntohll(uint64_t x) {
    return ((uint64_t)ntohl(x & 0xFFFFFFFF) << 32) | ntohl(x >> 32);
}

void OFPPROP_LOG(struct ofpbuf *rl, bool log, const char *format, ...);
enum ofperr oxm_pull_field_array(void *data, size_t len, void **fields);
void ofpbuf_pull(struct ofpbuf *buf, size_t size);