#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    uint16_t event;
    uint16_t len;
    uint16_t offset;
    uint16_t layer_specific;
} BT_HDR;

typedef struct {
    uint8_t op_code;
    uint16_t mdl_id;
} tMCA_HDR;

typedef struct {
    uint8_t dep_id;
    uint8_t cfg;
} tMCA_CREATE_IND;

typedef struct {
    tMCA_HDR hdr;
    tMCA_CREATE_IND create_ind;
} tMCA_CTRL;

typedef struct {
    uint8_t op_code;
    uint16_t mdl_id;
    uint8_t mdep_id;
    uint8_t dcb_idx;
} tMCA_CCB_MSG;

typedef struct {
    uint8_t dcb_idx;
} tMCA_DCB;

typedef struct {
    tMCA_CCB_MSG* p_rx_msg;
    tMCA_CCB_MSG* p_tx_req;
    uint16_t ctrl_vpsm;
    uint16_t lcid;
    uint8_t status;
    void* p_rcb;
} tMCA_CCB;

typedef struct {
    BT_HDR hdr;
} tMCA_CCB_EVT;

#define MCA_RSP_NO_RESOURCE 0
#define MCA_CCB_STAT_PENDING 1
#define MCA_CCB_STAT_NORM 2
#define MCA_OP_MDL_ABORT_REQ 3
#define MCA_RSP_BAD_OP 4
#define MCA_RSP_SUCCESS 5
#define MCA_ALL_MDL_ID 0xFFFF
#define MCA_OP_MDL_DELETE_REQ 6
#define MCA_NUM_STANDARD_OPCODE 7
#define MCA_FIRST_SYNC_OP 8
#define MCA_LAST_SYNC_OP 9
#define MCA_OP_ERROR_RSP 10
#define MCA_RSP_BAD_MDL 11
#define MCA_RSP_BAD_MDEP 12
#define MCA_RSP_MDEP_BUSY 13
#define MCA_RSP_MDL_BUSY 14
#define MCA_OP_MDL_CREATE_REQ 15
#define MCA_OP_MDL_RECONNECT_REQ 16
#define MCA_OP_SYNC_INFO_IND 17
#define MCA_OP_MDL_CREATE_RSP 18
#define MCA_OP_MDL_RECONNECT_RSP 19
#define MCA_OP_MDL_ABORT_RSP 20
#define MCA_OP_MDL_DELETE_RSP 21
#define MCA_OP_SYNC_CAP_RSP 22
#define MCA_OP_SYNC_SET_RSP 23
#define MCA_CTRL_MTU 64
#define L2CAP_MIN_OFFSET 0

#define MCA_TRACE_DEBUG(...)
#define MCA_TRACE_ERROR(...)
#define MCA_IS_VALID_MDL_ID(x) ((x) != 0)

#define BE_STREAM_TO_UINT16(v, p) do { \
    uint8_t *pp = (uint8_t *)(p); \
    (v) = ((uint16_t)(*(pp)) << 8) | (uint16_t)(*(pp + 1)); \
    (p) = pp + 2; \
} while(0)

#define UINT16_TO_BE_STREAM(p, v) do { \
    uint8_t *pp = (uint8_t *)(p); \
    *pp++ = (uint8_t)((v) >> 8); \
    *pp++ = (uint8_t)(v); \
    (p) = pp; \
} while(0)

tMCA_DCB* mca_dcb_by_hdl(uint8_t dcb_idx);
void mca_dcb_dealloc(tMCA_DCB* p_dcb, void* p_data);
void osi_free_and_reset(void** ptr);
void osi_free(void* ptr);
void mca_stop_timer(tMCA_CCB* p_ccb);
bool mca_is_valid_dep_id(void* p_rcb, uint8_t mdep_id);
bool mca_ccb_uses_mdl_id(tMCA_CCB* p_ccb, uint16_t mdl_id);
void mca_dcb_close_by_mdl_id(tMCA_CCB* p_ccb, uint16_t mdl_id);
uint8_t mca_dep_free_mdl(tMCA_CCB* p_ccb, uint8_t dep_id);
void* osi_malloc(size_t size);
int L2CA_DataWrite(uint16_t lcid, BT_HDR* p_buf);
void mca_ccb_report_event(tMCA_CCB* p_ccb, uint8_t op_code, tMCA_CTRL* p_evt);