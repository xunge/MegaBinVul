#include <stdlib.h>

typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct _wmem_allocator_t wmem_allocator_t;

typedef struct packet_info {
    void *pool;
} packet_info;

#define SEC_TVB_KEY 0
#define _U_ __attribute__((unused))

extern int proto_geonw;
extern wmem_allocator_t *wmem_file_scope();

void p_add_proto_data(void *pool, packet_info *pinfo, int proto, int key, tvbuff_t *tvb);
int tvb_reported_length(tvbuff_t *tvb);