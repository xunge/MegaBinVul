#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

typedef bool gboolean;
typedef int gint;
typedef unsigned int guint;
typedef uint8_t guint8;
typedef uint32_t guint32;
typedef char gchar;

#define TRUE true
#define FALSE false

struct tvbuff;
typedef struct tvbuff tvbuff_t;

struct packet_info;
typedef struct packet_info packet_info;

struct proto_tree;
typedef struct proto_tree proto_tree;

struct proto_item;
typedef struct proto_item proto_item;

struct expert_field;
typedef struct expert_field expert_field;

extern int hf_eap_identity_wlan_mcc_mnc;
extern int hf_eap_identity_wlan_mcc_mnc_3digits;
extern int hf_eap_identity_wlan_mcc_mnc_2digits;
extern int hf_eap_identity_wlan_prefix;
extern int hf_eap_identity_pseudo;
extern int hf_eap_identity_reauth;
extern int hf_eap_identity_wlan_mcc;
extern int ett_identity;
extern expert_field ei_eap_identity_invalid;

void* wmem_packet_scope();
guint8* tvb_get_string_enc(void* scope, tvbuff_t* tvb, int offset, int length, int enc);
gchar** g_strsplit_set(const gchar* string, const gchar* delimiters, int max_tokens);
int g_ascii_strncasecmp(const char* s1, const char* s2, size_t n);
void g_strfreev(gchar** str_array);
void dissect_e212_utf8_imsi(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, int offset, guint size);
proto_tree* proto_item_add_subtree(proto_item* item, int ett);
proto_item* proto_tree_add_uint(proto_tree* tree, int hfindex, tvbuff_t* tvb, gint start, gint length, guint32 value);
void proto_tree_add_item(proto_tree* tree, int hfindex, tvbuff_t* tvb, gint start, gint length, int encoding);
void expert_add_info(packet_info* pinfo, proto_item* item, expert_field* expert);

#define ENC_ASCII 0
#define ENC_NA 0