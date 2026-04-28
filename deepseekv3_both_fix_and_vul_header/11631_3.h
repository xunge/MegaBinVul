#include <stdint.h>
#include <string.h>

typedef int gint;
typedef int32_t gint32;
typedef int64_t gint64;
typedef uint8_t guint8;
typedef uint32_t guint32;
typedef uint64_t guint64;

typedef struct tvbuff tvbuff_t;
typedef struct _packet_info {
    struct {
        int COL_INFO;
    } *cinfo;
} packet_info;
typedef struct _proto_tree proto_tree;
typedef struct _proto_item proto_item;
typedef struct _wmem_allocator wmem_allocator_t;
typedef struct {
    int64_t secs;
    int32_t nsecs;
} nstime_t;

typedef struct {
    tvbuff_t *tvb;
    gint offset;
    gint bytes_left;
} protobuf_desc_t;

typedef struct {
    uint32_t field_number;
    uint32_t wire_type;
    uint32_t tag;
} protobuf_tag_t;

enum {
    STEAMDISCOVER_FN_STATUS_VERSION,
    STEAMDISCOVER_FN_STATUS_MINVERSION,
    STEAMDISCOVER_FN_STATUS_CONNECTPORT,
    STEAMDISCOVER_FN_STATUS_HOSTNAME,
    STEAMDISCOVER_FN_STATUS_ENABLEDSERVICES,
    STEAMDISCOVER_FN_STATUS_OSTYPE,
    STEAMDISCOVER_FN_STATUS_IS64BIT,
    STEAMDISCOVER_FN_STATUS_USERS,
    STEAMDISCOVER_FN_STATUS_EUNIVERSE,
    STEAMDISCOVER_FN_STATUS_TIMESTAMP,
    STEAMDISCOVER_FN_STATUS_SCREENLOCKED,
    STEAMDISCOVER_FN_STATUS_GAMESRUNNING,
    STEAMDISCOVER_FN_STATUS_MACADDRESSES,
    STEAMDISCOVER_FN_STATUS_USER_STEAMID,
    STEAMDISCOVER_FN_STATUS_USER_AUTHKEYID
};

enum {
    STEAMDISCOVER_MSGTYPE_CLIENTBROADCASTMSGSTATUS
};

#define WMEM_ALLOCATOR_SIMPLE 0
#define PROTOBUF_WIRETYPE_VARINT 0
#define PROTOBUF_WIRETYPE_64BIT 1
#define PROTOBUF_WIRETYPE_LENGTHDELIMITED 2
#define ENC_UTF_8 0
#define ENC_NA 0
#define COL_INFO 0
#define G_GUINT64_FORMAT "lu"
#define G_GUINT32_FORMAT "u"

extern int hf_steam_ihs_discovery_body_status_version;
extern int hf_steam_ihs_discovery_body_status_minversion;
extern int hf_steam_ihs_discovery_body_status_connectport;
extern int hf_steam_ihs_discovery_body_status_hostname;
extern int hf_steam_ihs_discovery_body_status_enabledservices;
extern int hf_steam_ihs_discovery_body_status_ostype;
extern int hf_steam_ihs_discovery_body_status_is64bit;
extern int hf_steam_ihs_discovery_body_status_user_steamid;
extern int hf_steam_ihs_discovery_body_status_user_authkeyid;
extern int hf_steam_ihs_discovery_body_status_euniverse;
extern int hf_steam_ihs_discovery_body_status_timestamp;
extern int hf_steam_ihs_discovery_body_status_screenlocked;
extern int hf_steam_ihs_discovery_body_status_gamesrunning;
extern int hf_steam_ihs_discovery_body_status_macaddresses;
extern int ett_steam_ihs_discovery_body_status_user;
extern const struct {
    const char *strptr;
} hf_steam_ihs_discovery_header_msgtype_strings[];

#define STEAMDISCOVER_ENSURE_WIRETYPE(wiretype) \
    if (tag.wire_type != (wiretype)) { \
        protobuf_seek_forward(&pb, len); \
        continue; \
    }

wmem_allocator_t* wmem_allocator_new(int type);
void wmem_destroy_allocator(wmem_allocator_t *allocator);
int protobuf_iter_next(protobuf_desc_t *pb, protobuf_tag_t *tag);
void protobuf_seek_forward(protobuf_desc_t *pb, int len);
gint64 get_varint64(tvbuff_t *tvb, int offset, int bytes_left, int *len);
void proto_tree_add_int(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int len, gint32 value);
void proto_tree_add_uint(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int len, guint32 value);
void proto_tree_add_item(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int len, int encoding);
guint8* tvb_get_string_enc(wmem_allocator_t *pool, tvbuff_t *tvb, int offset, int len, int encoding);
void col_add_fstr(void *cinfo, int col, const char *fmt, ...);
void proto_tree_add_boolean(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int len, gint32 value);
proto_tree* proto_tree_add_subtree(proto_tree *tree, tvbuff_t *tvb, int offset, int len, int ett, proto_item **it, const char *text);
int protobuf_verify_wiretype(protobuf_desc_t *pb, protobuf_tag_t *tag, packet_info *pinfo, proto_tree *tree, int wiretype);
guint64 tvb_get_letoh64(tvbuff_t *tvb, int offset);
void proto_tree_add_uint64(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int len, guint64 value);
void proto_item_append_text(proto_item *it, const char *fmt, ...);
int protobuf_dissect_unknown_field(protobuf_desc_t *pb, protobuf_tag_t *tag, packet_info *pinfo, proto_tree *tree, void *data);
void proto_tree_add_time(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int len, nstime_t *value);