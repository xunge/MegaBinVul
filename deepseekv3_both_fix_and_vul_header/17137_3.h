#include <stdint.h>
#include <stddef.h>

#define ADB_TCP_PORT 5555
#define max_in_frame 0
#define A_CLSE 0
#define A_OPEN 1
#define A_OKAY 2
#define WTAP_HAS_INTERFACE_ID 0x01
#define proto_usb 0

typedef uint32_t guint32;
typedef int32_t gint;
typedef uint8_t guint8;

typedef struct {
    guint32 num;
    guint32 srcport;
    guint32 destport;
    struct {
        guint32 presence_flags;
        guint32 interface_id;
    } *phdr;
} packet_info;

typedef struct {
    int length;
    void *key;
} wmem_tree_key_t;

typedef struct wmem_tree_t wmem_tree_t;

typedef enum {
    P2P_DIR_UNKNOWN,
    P2P_DIR_SENT,
    P2P_DIR_RECV
} p2p_dir_t;

typedef struct {
    guint32 command;
    guint32 arg0;
    guint32 arg1;
    guint32 command_in_frame;
    guint32 response_in_frame;
    guint32 crc32;
    guint32 data_length;
    guint32 completed_in_frame;
    guint32 reassemble_data_length;
    guint8 *reassemble_data;
    guint32 reassemble_error_in_frame;
} command_data_t;

typedef struct {
    guint32 start_in_frame;
    guint32 close_local_in_frame;
    guint32 close_remote_in_frame;
    guint32 local_id;
    guint32 remote_id;
    const char *service;
} service_data_t;

typedef struct {
    gint direction;
    guint32 bus_id;
    guint32 device_address;
} usb_conv_info_t;

extern wmem_tree_t *service_info;
extern wmem_tree_t *command_info;
extern void *wmem_file_scope();
extern void *wmem_alloc(void *allocator, size_t size);
extern void *wmem_new0(void *allocator, size_t size);
extern void wmem_tree_insert32_array(wmem_tree_t *tree, wmem_tree_key_t *key, void *data);
extern void *wmem_tree_lookup32_array(wmem_tree_t *tree, wmem_tree_key_t *key);
extern void *wmem_tree_lookup32_le(wmem_tree_t *tree, guint32 frame);

#define DISSECTOR_ASSERT(expr) ((void)0)
#define wmem_new(allocator, type) ((type *)wmem_new0(allocator, sizeof(type)))