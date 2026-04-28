#include <stdint.h>
#include <string.h>
#include <stdbool.h>

typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct wmem_allocator_t wmem_allocator_t;

typedef int32_t gint;
typedef uint32_t guint;
typedef int64_t gint64;
typedef uint8_t guint8;
typedef bool gboolean;

typedef struct {
    void* cinfo;
} packet_info;

typedef struct {
    tvbuff_t *tvb;
    gint offset;
    gint bytes_left;
} protobuf_desc_t;

typedef struct {
    guint field_number;
    guint wire_type;
    guint tag;
} protobuf_tag_t;

#define STEAMDISCOVER_FN_AUTHREQUEST_DEVICETOKEN 1
#define STEAMDISCOVER_FN_AUTHREQUEST_DEVICENAME 2
#define STEAMDISCOVER_FN_AUTHREQUEST_ENCRYPTEDREQUEST 3

#define PROTOBUF_WIRETYPE_LENGTHDELIMITED 2
#define WMEM_ALLOCATOR_SIMPLE 0
#define ENC_NA 0
#define ENC_UTF_8 1
#define COL_INFO 0

extern gboolean protobuf_iter_next(protobuf_desc_t *pb, protobuf_tag_t *tag);
extern gint64 get_varint64(tvbuff_t *tvb, gint offset, gint bytes_left, guint *len);
extern gint protobuf_dissect_unknown_field(protobuf_desc_t *pb, protobuf_tag_t *tag, packet_info *pinfo, proto_tree *tree, void *data);
extern void protobuf_seek_forward(protobuf_desc_t *pb, gint len);
extern wmem_allocator_t* wmem_allocator_new(int allocator_type);
extern void wmem_destroy_allocator(wmem_allocator_t *allocator);
extern guint8* tvb_get_string_enc(wmem_allocator_t *pool, tvbuff_t *tvb, gint offset, gint length, int encoding);
extern void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, int encoding);
extern void col_append_fstr(void *cinfo, int column, const char *format, ...);

extern int hf_steam_ihs_discovery_body_authrequest_devicetoken;
extern int hf_steam_ihs_discovery_body_authrequest_devicename;
extern int hf_steam_ihs_discovery_body_authrequest_encryptedrequest;

#define STEAMDISCOVER_ENSURE_WIRETYPE(wiretype) \
    if (tag.wire_type != (wiretype)) { \
        len = protobuf_dissect_unknown_field(&pb, &tag, pinfo, tree, NULL); \
        break; \
    }