#include <stdint.h>
#include <stddef.h>

typedef uint8_t guint8;
typedef unsigned int guint;

typedef struct pnio_ar_t pnio_ar_t;
typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct dcerpc_info dcerpc_info;

extern int dissect_IPNIO_rqst_header(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, dcerpc_info *di, guint8 *drep);
extern int dissect_IODWriteReq(tvbuff_t *tvb, int offset, packet_info *pinfo, proto_tree *tree, guint8 *drep, pnio_ar_t **ar, ...);
extern void pnio_ar_info(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, pnio_ar_t *ar);