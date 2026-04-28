#include <stdint.h>
#include <string.h>

typedef uint32_t guint32;

typedef struct enip_conn_key_t {
    uint32_t ConnSerialNumber;
    uint32_t VendorID;
    uint32_t DeviceSerialNumber;
    uint32_t O2TConnID;
    uint32_t T2OConnID;
} enip_conn_key_t;

typedef struct enip_conn_val_t {
    uint32_t ConnSerialNumber;
    uint32_t VendorID;
    uint32_t DeviceSerialNumber;
    uint32_t O2TConnID;
    uint32_t T2OConnID;
    uint8_t TransportClass_trigger;
    uint8_t safety;
    uint8_t motion;
    uint32_t ClassID;
    uint32_t open_frame;
    uint32_t open_reply_frame;
    uint32_t close_frame;
    uint32_t connid;
} enip_conn_val_t;

typedef struct address {
    uint32_t type;
    uint32_t len;
    void* data;
} address;

typedef struct e_in6_addr {
    uint8_t addr[16];
} e_in6_addr;

typedef struct packet_info {
    uint32_t num;
    struct {
        struct {
            uint32_t visited;
        } flags;
    }* fd;
    address src;
    address dst;
} packet_info;

typedef struct cip_conn_info_t {
    uint32_t ConnSerialNumber;
    uint32_t VendorID;
    uint32_t DeviceSerialNumber;
    uint8_t TransportClass_trigger;
    uint8_t safety;
    uint8_t motion;
    uint32_t ClassID;
    uint32_t forward_open_frame;
    struct {
        uint32_t connID;
        uint16_t port;
        uint8_t type;
        address ipaddress;
    } O2T, T2O;
} cip_conn_info_t;

typedef struct enip_conv_info_t {
    void* O2TConnIDs;
    void* T2OConnIDs;
} enip_conv_info_t;

typedef struct conversation_t conversation_t;

#define CI_TRANSPORT_CLASS_MASK 0x03
#define ENIP_IO_PORT 2222
#define NO_PORT_B 0
#define NO_PORT2 0
#define PT_UDP 1
#define AT_NONE 0
#define AT_IPv4 1
#define AT_IPv6 2
#define ENIP_CONNECTION_INFO 0
#define proto_enip 0
#define CONN_TYPE_MULTICAST 1

extern int enip_unique_connid;
extern void* enip_conn_hashtable;
extern void* wmem_file_scope();
extern void* wmem_new0(void* pool, size_t size);
extern void* wmem_map_lookup(void* map, const void* key);
extern void wmem_map_insert(void* map, void* key, void* val);
extern void* wmem_tree_new(void* pool);
extern void wmem_tree_insert32(void* tree, uint32_t key, void* val);
extern conversation_t* find_conversation(uint32_t frame_num, const address* addr1, const address* addr2, int ptype, uint16_t port1, uint16_t port2, uint32_t options);
extern conversation_t* conversation_new(uint32_t frame_num, const address* addr1, const address* addr2, int ptype, uint16_t port1, uint16_t port2, uint32_t options);
extern void* conversation_get_proto_data(conversation_t* conv, int proto);
extern void conversation_add_proto_data(conversation_t* conv, int proto, void* proto_data);
extern conversation_t* find_or_create_conversation(packet_info* pinfo);
extern void copy_address_wmem(void* pool, address* dst, const address* src);
extern void copy_address_shallow(address* dst, const address* src);
extern void p_add_proto_data(void* pool, packet_info* pinfo, int proto, int key, void* val);

#define wmem_new(pool, type) ((type*)wmem_new0(pool, sizeof(type)))