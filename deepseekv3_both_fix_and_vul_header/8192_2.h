#include <stdint.h>
#include <stdlib.h>

typedef struct conversation_t conversation_t;
typedef struct ldss_broadcast_t ldss_broadcast_t;
typedef struct ldss_transfer_info_t ldss_transfer_info_t;
typedef struct wmem_allocator_t wmem_allocator_t;

enum {
    PT_TCP,
    NO_ADDR2,
    NO_PORT2
};

struct ldss_broadcast_t {
    uint32_t num;
    struct {
        uint32_t addr;
        uint16_t port;
    } *broadcaster;
};

struct ldss_transfer_info_t {
    ldss_broadcast_t *broadcast;
};

extern wmem_allocator_t *wmem_file_scope(void);
extern void *wmem_new0(wmem_allocator_t *allocator, size_t size);
extern int proto_ldss;
extern void *ldss_tcp_handle;

#define wmem_new0(allocator, type) ((type *)wmem_new0(allocator, sizeof(type)))

conversation_t *conversation_new(uint32_t num, const void *addr1, const void *addr2, int ptype, uint16_t port1, uint16_t port2, int flags);
void conversation_add_proto_data(conversation_t *conv, int proto_id, void *proto_data);
void conversation_set_dissector(conversation_t *conv, void *handle);