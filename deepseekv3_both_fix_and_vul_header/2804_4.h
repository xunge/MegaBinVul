#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

#define CL_OPTION_DEVICE_TYPE 1
#define CL_OPTION_DEVICE_SERIAL_NUMBER 2
#define CL_OPTION_HARDWARE_VERSION_NUMBER 3
#define CL_OPTION_SOFTWARE_VERSION_NUMBER 4
#define CL_OPTION_BOOT_ROM_VERSION 5
#define CL_OPTION_MODEL_NUMBER 6
#define CL_OPTION_VENDOR_NAME 7
#define CL_OPTION_CONFIG_FILE_NAME 8
#define CL_OPTION_EMBEDDED_COMPONENT_LIST 9
#define CL_OPTION_VENDOR_OUI 10
#define CL_OPTION_ORO 11
#define CL_OPTION_TFTP_SERVERS 12
#define CL_OPTION_SYSLOG_SERVERS 13
#define CL_OPTION_RFC868_SERVERS 14
#define CL_OPTION_DEVICE_ID 15
#define CL_OPTION_TLV5 16
#define CL_OPTION_TIME_OFFSET 17
#define CL_OPTION_IP_PREF 18
#define CL_OPTION_DOCS_CMTS_CAP 19
#define CL_CM_MAC_ADDR 20
#define CL_EROUTER_CONTAINER_OPTION 21
#define CL_OPTION_CCC 22
#define CL_OPTION_CCCV6 23
#define CL_OPTION_CORRELATION_ID 24
#define CL_OPTION_DOCS_CMTS_TLV_VERS_NUM 1

#define ENC_BIG_ENDIAN 0
#define ENC_NA 1
#define ENC_ASCII 2

typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct packet_info packet_info;
typedef struct tvbuff tvbuff_t;
typedef struct expert_field {
    int dummy1;
    int dummy2;
} expert_field;
typedef struct wmem_allocator wmem_allocator;
typedef char gchar;
typedef unsigned int guint;
typedef unsigned short guint16;
typedef unsigned char guint8;
typedef uint32_t guint32;
typedef int gint;

static int hf_cablelabs_opts = -1;
static int hf_cablelabs_ipv6_server = -1;
static int hf_modem_capabilities_encoding_type = -1;
static int hf_eue_capabilities_encoding_type = -1;
static int hf_capabilities_encoding_length = -1;
static int hf_capabilities_encoding_bytes = -1;
static int hf_capabilities_encoding_number = -1;
static int hf_cablelabs_docsis_version_number = -1;
static int ett_dhcpv6_vendor_option = -1;
static int ett_dhcpv6_tlv5_type = -1;
static expert_field ei_dhcpv6_bogus_length = {0, 0};

static inline guint16 tvb_get_ntohs(tvbuff_t *tvb, int offset) { return 0; }
static inline guint32 tvb_get_ntohl(tvbuff_t *tvb, int offset) { return 0; }
static inline guint8 tvb_get_guint8(tvbuff_t *tvb, int offset) { return 0; }
static inline char* tvb_get_string_enc(wmem_allocator *scope, tvbuff_t *tvb, int offset, int length, int encoding) { return NULL; }
static inline char* tvb_format_stringzpad(tvbuff_t *tvb, int offset, int length) { return NULL; }
static inline char* tvb_bytes_to_str_punct(wmem_allocator *scope, tvbuff_t *tvb, int offset, int length, char punct) { return NULL; }
static inline char* tvb_bytes_to_str(wmem_allocator *scope, tvbuff_t *tvb, int offset, int length) { return NULL; }
static inline proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding) { return NULL; }
static inline void proto_item_append_text(proto_item *item, const char *format, ...) {}
static inline proto_tree* proto_item_add_subtree(proto_item *item, int ett) { return NULL; }
static inline void proto_item_prepend_text(proto_item *item, const char *format, ...) {}
static inline void expert_add_info_format(packet_info *pinfo, proto_item *item, expert_field *ef, const char *format, ...) {}
static inline wmem_allocator* wmem_packet_scope(void) { return NULL; }
static inline int g_ascii_strncasecmp(const char *s1, const char *s2, size_t n) { return 0; }
static inline int dissect_packetcable_ccc_option(proto_tree *tree, proto_item *item, packet_info *pinfo, tvbuff_t *tvb, int offset, int len) { return 0; }
static inline int dissect_packetcable_cccV6_option(proto_tree *tree, proto_item *item, packet_info *pinfo, tvbuff_t *tvb, int offset, int len) { return 0; }