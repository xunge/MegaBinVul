#include <stdint.h>
#include <string.h>

#define SMP_TRACE_DEBUG(format, ...)
#define SMP_TRACE_ERROR(format, ...)
#define android_errorWriteLog(tag, id)

#define BT_OCTET8_LEN 8
#define BT_OCTET16_LEN 16

#define SMP_SEC_KEY_TYPE_ENC 0
#define SMP_AUTH_BOND 0
#define BTM_LE_KEY_PENC 0

typedef struct {
    uint8_t* p_data;
} tSMP_INT_DATA;

typedef struct {
    uint8_t rcvd_cmd_len;
    uint8_t ltk[BT_OCTET16_LEN];
    uint8_t sec_level;
    uint8_t loc_enc_size;
    uint8_t peer_auth_req;
    uint8_t loc_auth_req;
    uint8_t pairing_bda[6];
} tSMP_CB;

typedef struct {
    uint16_t ediv;
    uint8_t rand[BT_OCTET8_LEN];
    uint8_t ltk[BT_OCTET16_LEN];
    uint8_t sec_level;
    uint8_t key_size;
} tBTM_LE_PENC_KEYS;

typedef struct {
    uint8_t value[1];
} tBTM_LE_KEY_VALUE;

void smp_update_key_mask(tSMP_CB* p_cb, uint8_t key_type, bool is_used);
void btm_sec_save_le_key(uint8_t* bd_addr, uint8_t key_type, tBTM_LE_KEY_VALUE* p_keys, bool is_orig);
void smp_key_distribution(tSMP_CB* p_cb, tSMP_INT_DATA* p_data);

#define STREAM_TO_UINT16(u16, p) {u16 = ((uint16_t)(*(p)) + (((uint16_t)(*((p) + 1))) << 8)); (p) += 2;}
#define STREAM_TO_ARRAY(arr, p, len) {memcpy(arr, p, len); (p) += (len);}