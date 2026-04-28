#include <stdint.h>
#include <stddef.h>

typedef int gint;

typedef struct address {
    uint8_t addr_type;
    uint8_t addr_len;
    uint8_t addr_data[16];
} address;

typedef struct packet_info {
    address src;
    address dst;
    uint16_t srcport;
    uint16_t destport;
} packet_info;

typedef struct conversation_t conversation_t;
typedef struct wmem_allocator_t wmem_allocator_t;

typedef struct {
    uint32_t outbound_port;
    uint32_t inbound_port;
    int altrows;
    int altcols;
    int rows;
    int cols;
    int extended;
    address outbound_addr;
    address inbound_addr;
} tn3270_conv_info_t;

extern int proto_tn3270;
extern wmem_allocator_t *wmem_file_scope(void);

conversation_t *find_or_create_conversation(packet_info *pinfo);
void *conversation_get_proto_data(conversation_t *conv, int proto);
void conversation_add_proto_data(conversation_t *conv, int proto, void *proto_data);
void *wmem_new(wmem_allocator_t *allocator, size_t size);
void copy_address(address *dst, const address *src);

#define wmem_new(allocator, type) ((type *)malloc(sizeof(type)))