#include <stdlib.h>
#include <stdint.h>

typedef struct _address {
    uint8_t data[4];
} address;

typedef struct _packet_info {
    uint32_t num;
    address src;
    address dst;
    uint32_t ptype;
    uint16_t srcport;
    uint16_t destport;
    uint8_t p2p_dir;
} packet_info;

typedef struct _conversation_t conversation_t;

typedef struct _h223_call_info {
    address srcaddress;
    uint16_t srcport;
} h223_call_info;

#define PT_UDP 0
#define P2P_DIR_SENT 0
#define P2P_DIR_RECV 1

extern int proto_h223;
extern void DISSECTOR_ASSERT(conversation_t*);
extern conversation_t *find_conversation(uint32_t, address*, address*, uint32_t, uint16_t, uint16_t, int);
extern void *conversation_get_proto_data(conversation_t*, int);
extern void conversation_add_proto_data(conversation_t*, int, void*);
extern h223_call_info *create_call_info(uint32_t);
extern void copy_address(address*, address*);
extern int addresses_equal(address*, address*);