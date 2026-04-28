#include <stdint.h>

typedef int32_t gint;
typedef uint32_t guint32;
typedef uint8_t guint8;
typedef char gchar;
typedef int gboolean;

#define G_MAXINT INT32_MAX

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct dcerpc_info dcerpc_info;
typedef struct proto_item proto_item;

extern int hf_dcom_max_count;
extern int hf_dcom_byte_length;
extern int ett_dcom_lpwstr;

int dissect_dcom_DWORD(tvbuff_t *tvb, gint offset, packet_info *pinfo,
                      proto_tree *tree, dcerpc_info *di, guint8 *drep,
                      int hfindex, guint32 *value);

int dissect_dcom_dcerpc_array_size(tvbuff_t *tvb, gint offset, packet_info *pinfo,
                                 proto_tree *tree, dcerpc_info *di, guint8 *drep,
                                 guint32 *size);

gint dcom_tvb_get_nwstringz0(tvbuff_t *tvb, gint offset, gint length,
                            gchar *str, guint32 maxlen, gboolean *printable);