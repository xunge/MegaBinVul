#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MAX_RTP_SETUP_METHOD_SIZE 255
#define PT_UDP 0
#define NO_ADDR_B 0
#define NO_PORT_B 0
#define NO_ADDR2 0
#define NO_PORT2 0
#define AT_NONE 0
#define _U_
#define DEBUG 0

typedef uint32_t guint32;
typedef int gboolean;
typedef char gchar;
typedef void GHashTable;

typedef struct {
    struct {
        struct {
            unsigned int visited;
        } flags;
        unsigned int num;
    } *fd;
} packet_info;

typedef struct {
    // address fields
} address;

typedef struct {
    guint32 setup_frame;
    // other conversation fields
} conversation_t;

typedef struct rtp_private_conv_info {
    void* multisegment_pdus;
    // other fields
} rtp_private_conv_info;

typedef struct _rtp_conversation_info {
    GHashTable* rtp_dyn_payload;
    guint32 extended_seqno;
    struct rtp_private_conv_info* rtp_conv_info;
    char method[MAX_RTP_SETUP_METHOD_SIZE+1];
    guint32 frame_number;
    gboolean is_video;
    struct srtp_info* srtp_info;
    void* bta2dp_info;
    void* btvdp_info;
} _rtp_conversation_info;

typedef struct srtp_info {
    // srtp info fields
} srtp_info;

extern void *rtp_handle;
extern void *proto_rtp;
extern void *wmem_file_scope();

void SET_ADDRESS(address *addr, int type, int len, const void *data);
char *ep_address_to_str(const address *addr);
conversation_t *find_conversation(guint32 setup_frame, const address *addr1, const address *addr2, int pt, int port1, int port2, int options);
conversation_t *conversation_new(guint32 setup_frame, const address *addr1, const address *addr2, int pt, guint32 port1, guint32 port2, int options);
void conversation_set_dissector(conversation_t *conv, void *handle);
void *conversation_get_proto_data(conversation_t *conv, void *proto);
void conversation_add_proto_data(conversation_t *conv, void *proto, void *proto_data);
void rtp_free_hash_dyn_payload(void *hash);
void *wmem_new(void *scope, size_t size);
void *wmem_tree_new(void *scope);
size_t g_strlcpy(char *dest, const char *src, size_t dest_size);

// Fix for wmem_new calls
#define wmem_new(scope, type) ((type*)wmem_new_impl(scope, sizeof(type)))
void *wmem_new_impl(void *scope, size_t size);