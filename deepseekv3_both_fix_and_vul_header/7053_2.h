#include <stdint.h>
#include <stdlib.h>

typedef struct _address {
    // address structure members
} address;

typedef struct _wmem_map_t {
    // wmem_map_t structure members
} wmem_map_t;

typedef struct _conversation_key {
    int type;
    address addr_val;
} conversation_key;

typedef struct _conversation_t {
    uint32_t options;
    conversation_key key_ptr[7];
} conversation_t;

#define DISSECTOR_ASSERT_HINT(cond, hint)
#define DPRINT(args)
#define DINDENT()
#define DENDENT()

#define CONVERSATION_TEMPLATE (1 << 0)
#define NO_ADDR2 (1 << 1)
#define NO_PORT2 (1 << 2)

#define ENDP_NO_PORT2_IDX 0
#define ENDP_NO_ADDR2_PORT2_IDX 1
#define ENDP_EXACT_IDX 2
#define ENDP_NO_ADDR2_IDX 3
#define PORT2_IDX 4
#define PORT2_NO_ADDR2_IDX 5
#define ADDR2_IDX 6

#define CE_ADDRESS 0

extern wmem_map_t *conversation_hashtable_no_addr2_or_port2;
extern wmem_map_t *conversation_hashtable_no_addr2;
extern wmem_map_t *conversation_hashtable_no_port2;
extern wmem_map_t *conversation_hashtable_exact_addr_port;

char *address_to_str(void *scope, const address *addr);
void wmem_free(void *scope, void *ptr);
void *wmem_file_scope(void);
void copy_address_wmem(void *scope, address *dst, const address *src);
void conversation_remove_from_hashtable(wmem_map_t *hashtable, conversation_t *conv);
void conversation_insert_into_hashtable(wmem_map_t *hashtable, conversation_t *conv);