#include <stdbool.h>
#include <stdint.h>
#include <string>
#include <iostream>

typedef struct {
    uint16_t len;
    uint16_t offset;
} BT_HDR;

typedef struct {
    uint8_t bd_addr[6];
} tRFC_MCB;

typedef struct {
    uint8_t ea;
    uint8_t cr;
    uint8_t type;
    uint8_t dlci;
    union {
        struct {
            uint8_t frame_type;
            uint8_t conv_layer;
            uint8_t priority;
            uint8_t t1;
            uint16_t mtu;
            uint8_t n2;
            uint8_t k;
        } pn;
        struct {
            uint8_t* p_data;
            uint16_t data_len;
        } test;
        struct {
            uint8_t signals;
            bool break_present;
            uint8_t break_duration;
        } msc;
        struct {
            uint8_t ea;
            uint8_t cr;
            uint8_t type;
        } nsc;
        struct {
            bool is_request;
            uint8_t baud_rate;
            uint8_t byte_size;
            uint8_t stop_bits;
            uint8_t parity;
            uint8_t parity_type;
            uint8_t fc_type;
            uint8_t xon_char;
            uint8_t xoff_char;
            uint16_t param_mask;
        } rpn;
        struct {
            uint8_t line_status;
        } rls;
    } u;
} MX_FRAME;

typedef struct {
    struct {
        MX_FRAME rx_frame;
    } rfc;
} rfc_cb_t;

extern rfc_cb_t rfc_cb;

#define ERROR 1
#define LOG(severity) std::cout

#define RFCOMM_EA 0x01
#define RFCOMM_CR_MASK 0x02
#define RFCOMM_SHIFT_CR 1
#define RFCOMM_EA_MASK 0x01
#define RFCOMM_SHIFT_LENGTH1 1
#define RFCOMM_SHIFT_LENGTH2 8
#define RFCOMM_PN_DLCI_MASK 0x3F
#define RFCOMM_PN_FRAME_TYPE_MASK 0x03
#define RFCOMM_PN_CONV_LAYER_MASK 0x0F
#define RFCOMM_PN_PRIORITY_MASK 0x0F
#define RFCOMM_PN_K_MASK 0x0F
#define RFCOMM_MX_PN_LEN 8
#define RFCOMM_MIN_MTU 23
#define RFCOMM_MAX_MTU 32767
#define RFCOMM_MX_FCON_LEN 0
#define RFCOMM_MX_FCOFF_LEN 0
#define RFCOMM_MX_MSC_LEN_WITH_BREAK 3
#define RFCOMM_MX_MSC_LEN_NO_BREAK 2
#define RFCOMM_MSC_BREAK_PRESENT_MASK 0x80
#define RFCOMM_MSC_BREAK_MASK 0x7F
#define RFCOMM_MSC_SHIFT_BREAK 0
#define RFCOMM_MX_NSC_LEN 1
#define RFCOMM_MX_RPN_REQ_LEN 2
#define RFCOMM_MX_RPN_LEN 8
#define RFCOMM_RPN_BITS_SHIFT 0
#define RFCOMM_RPN_BITS_MASK 0x03
#define RFCOMM_RPN_STOP_BITS_SHIFT 2
#define RFCOMM_RPN_STOP_BITS_MASK 0x01
#define RFCOMM_RPN_PARITY_SHIFT 3
#define RFCOMM_RPN_PARITY_MASK 0x01
#define RFCOMM_RPN_PARITY_TYPE_SHIFT 4
#define RFCOMM_RPN_PARITY_TYPE_MASK 0x03
#define RFCOMM_FC_MASK 0x01
#define RFCOMM_RPN_PM_MASK 0xFFFF
#define RFCOMM_MX_RLS_LEN 2
#define RFCOMM_SHIFT_DLCI 2
#define RFCOMM_VALID_DLCI(dlci) ((dlci) > 0 && (dlci) < 32)

#define RFCOMM_MX_PN 0x20
#define RFCOMM_MX_TEST 0x08
#define RFCOMM_MX_FCON 0x28
#define RFCOMM_MX_FCOFF 0x18
#define RFCOMM_MX_MSC 0x38
#define RFCOMM_MX_NSC 0x04
#define RFCOMM_MX_RPN 0x24
#define RFCOMM_MX_RLS 0x14

void osi_free(void* ptr);
void RFCOMM_TRACE_ERROR(const char* fmt, ...);
void RFCOMM_TRACE_DEBUG(const char* fmt, ...);
void android_errorWriteLog(uint32_t tag, const char* msg);
void rfc_process_pn(tRFC_MCB* p_mcb, bool is_command, MX_FRAME* p_rx_frame);
void rfc_send_test(tRFC_MCB* p_mcb, bool is_command, BT_HDR* p_buf);
void rfc_process_test_rsp(tRFC_MCB* p_mcb, BT_HDR* p_buf);
void rfc_process_fcon(tRFC_MCB* p_mcb, bool is_command);
void rfc_process_fcoff(tRFC_MCB* p_mcb, bool is_command);
void rfc_process_msc(tRFC_MCB* p_mcb, bool is_command, MX_FRAME* p_rx_frame);
void rfc_process_nsc(tRFC_MCB* p_mcb, MX_FRAME* p_rx_frame);
void rfc_process_rpn(tRFC_MCB* p_mcb, bool is_command, bool is_request, MX_FRAME* p_rx_frame);
void rfc_process_rls(tRFC_MCB* p_mcb, bool is_command, MX_FRAME* p_rx_frame);
void rfc_send_nsc(tRFC_MCB* p_mcb);