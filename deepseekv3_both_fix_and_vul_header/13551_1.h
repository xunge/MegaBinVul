#include <stdio.h>
#include <string.h>

typedef unsigned int guint;
typedef unsigned char guint8;
typedef unsigned char guchar;

typedef enum {
    CONVERSATION_NONE,
    CONVERSATION_UDP, 
    CONVERSATION_TCP
} conversation_type;

typedef struct {
    int type;
    int len;
    void* data;
} address;

typedef struct {} tvbuff_t;
typedef struct {
    void* pool;
    void* cinfo;
} packet_info;
typedef struct {} proto_tree;

extern int hf_msmms_command_prefix1;
extern int hf_msmms_command_prefix2; 
extern int hf_msmms_command_client_transport_info;

#define ENC_LITTLE_ENDIAN 0
#define ENC_UTF_16 0
#define AT_IPv4 0
#define COL_INFO 0

char* tvb_get_string_enc(void* pool, tvbuff_t* tvb, guint offset, int len, int enc);
void proto_tree_add_item(proto_tree* tree, int hf, tvbuff_t* tvb, guint offset, int len, int enc);
void proto_tree_add_string_format(proto_tree* tree, int hf, tvbuff_t* tvb, guint offset, int len, char* str, const char* fmt, ...);
void col_append_fstr(void* cinfo, int col, const char* fmt, ...);
char* format_text(void* pool, guchar* data, int len);
void msmms_data_add_address(packet_info* pinfo, address* addr, conversation_type ckt, guint port);