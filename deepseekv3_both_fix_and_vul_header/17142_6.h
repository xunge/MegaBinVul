#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LAPD_PACKET_LEN 1024
#define _U_
#define TRUE 1
#define FALSE 0
#define proto_lapd 0

typedef uint8_t guint8;
typedef int gint;
typedef bool gboolean;

enum lapd_bitstream_states {
    OUT_OF_SYNC,
    FLAGS,
    DATA
};

typedef struct {
    void* src;
    void* dst;
    uint16_t srcport;
    uint16_t destport;
} packet_info;

typedef struct {
    void* tree;
} proto_tree;

typedef struct {
    void* tvb;
} tvbuff_t;

typedef struct {
    enum lapd_bitstream_states state;
    guint8 full_byte;
    guint8 bit_offset;
    guint8 ones;
    guint8 data[MAX_LAPD_PACKET_LEN];
    int data_len;
} lapd_byte_state_t;

typedef struct {
    void* addr_a;
    void* addr_b;
    uint16_t port_a;
    uint16_t port_b;
    lapd_byte_state_t *byte_state_a;
    lapd_byte_state_t *byte_state_b;
} lapd_convo_data_t;

typedef struct {
    gboolean has_crc;
    lapd_byte_state_t start_byte_state;
} lapd_ppi_t;

typedef struct {
    void* conversation;
} conversation_t;

static void* wmem_file_scope() { return NULL; }
static conversation_t* find_or_create_conversation(packet_info* pinfo) { return NULL; }
static void* p_get_proto_data(void* scope, packet_info* pinfo, int proto, int idx) { return NULL; }
static void* conversation_get_proto_data(conversation_t* conv, int proto) { return NULL; }
static int addresses_equal(void* a, void* b) { return 0; }
static int tvb_reported_length_remaining(tvbuff_t* tvb, int offset) { return 0; }
static guint8 tvb_get_guint8(tvbuff_t* tvb, int offset) { return 0; }
static void* g_memdup(void* data, int len) { return NULL; }
static tvbuff_t* tvb_new_child_real_data(tvbuff_t* parent, void* data, int len, int reported_len) { return NULL; }
static void tvb_set_free_cb(tvbuff_t* tvb, void(*cb)(void*)) {}
static void g_free(void* ptr) {}
static void add_new_data_source(packet_info* pinfo, tvbuff_t* tvb, const char* name) {}
static void lapd_log_abort(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, int offset, const char* msg) {}
static void dissect_lapd_full(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, gboolean flag) {}
static void new_byte(guint8 byte, guint8* data, int* data_len) {}
static void* wmem_new0(void* scope, size_t size) { return calloc(1, size); }
static void fill_lapd_byte_state(lapd_byte_state_t* state, enum lapd_bitstream_states s, 
                               guint8 fb, guint8 bo, guint8 o, guint8* d, int dl) {}
static void p_add_proto_data(void* scope, packet_info* pinfo, int proto, int idx, void* data) {}
static void copy_address(void** dst, void** src) {}
static void conversation_add_proto_data(conversation_t* conv, int proto, void* data) {}
static int tvb_captured_length(tvbuff_t* tvb) { return 0; }

#define wmem_new(scope, type) ((type*)wmem_new0(scope, sizeof(type)))