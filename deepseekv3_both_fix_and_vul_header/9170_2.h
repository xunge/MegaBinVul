#include <stdint.h>
#include <string.h>

typedef struct tvbuff tvbuff_t;
typedef struct proto_item proto_item;
typedef struct proto_tree proto_tree;
typedef struct dcom_interface_t dcom_interface_t;

typedef int gint;
typedef uint8_t guint8;
typedef uint32_t guint32;
typedef uint64_t guint64;
typedef char gchar;

typedef struct {
    uint32_t Data1;
    uint16_t Data2;
    uint16_t Data3;
    uint8_t Data4[8];
} e_guid_t;

typedef struct {
    int type;
    struct {
        int type;
    } net_src;
} packet_info;

typedef struct {
    int dummy;
} dcerpc_info;

typedef struct {
    int dummy;
} address;

#define AT_IPv4 0
#define ENC_NA 0

extern int hf_dcom_objref;
extern int hf_dcom_objref_signature;
extern int hf_dcom_objref_flags;
extern int hf_dcom_iid;
extern int hf_dcom_clsid;
extern int hf_dcom_objref_resolver_address;
extern int ett_dcom_objref;

proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint offset, gint length, int encoding);
proto_tree* proto_item_add_subtree(proto_item *item, int ett);
void proto_item_set_len(proto_item *item, gint length);

int dissect_dcom_DWORD(tvbuff_t *tvb, gint offset, packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep, int hfindex, guint32 *u32);
int dissect_dcom_UUID(tvbuff_t *tvb, gint offset, packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep, int hfindex, e_guid_t *guid);
int dissect_dcom_STDOBJREF(tvbuff_t *tvb, gint offset, packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep, int hfindex, guint64 *oxid, guint64 *oid, e_guid_t *ipid);
int dissect_dcom_DUALSTRINGARRAY(tvbuff_t *tvb, gint offset, packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep, int hfindex, gchar *ip);
int dissect_dcom_CUSTOBJREF(tvbuff_t *tvb, gint offset, packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep, int hfindex, e_guid_t *clsid, e_guid_t *iid);
dcom_interface_t* dcom_interface_new(packet_info *pinfo, address *addr, e_guid_t *iid, guint64 oxid, guint64 oid, e_guid_t *ipid);
void SET_ADDRESS(address *addr, int type, int len, const void *data);