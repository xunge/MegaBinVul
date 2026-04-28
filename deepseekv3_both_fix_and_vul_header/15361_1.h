#include <stdbool.h>
#include <stdint.h>
#include <string.h>

struct RawAddress {
    uint8_t address[6];
};

namespace bluetooth {
namespace shim {
bool is_gd_shim_enabled();
bool BTM_BleVerifySignature(const RawAddress& bd_addr, uint8_t* p_orig,
                           uint16_t len, uint32_t counter, uint8_t* p_comp);
}  // namespace shim
}  // namespace bluetooth

#define BTM_CMAC_TLEN_SIZE 16
#define BTM_LE_KEY_PCSRK 0x04

namespace crypto_toolbox {
void aes_cmac(const uint8_t* key, const uint8_t* input, uint16_t length,
              uint8_t cmac_size, uint8_t* cmac);
}  // namespace crypto_toolbox

struct tBTM_SEC_DEV_REC {
    struct {
        uint8_t key_type;
        struct {
            uint32_t counter;
            uint8_t pcsrk[16];
        } keys;
    } ble;
};

tBTM_SEC_DEV_REC* btm_find_dev(const RawAddress& bd_addr);
void btm_ble_increment_sign_ctr(const RawAddress& bd_addr, bool is_local);
int CRYPTO_memcmp(const void* in_a, const void* in_b, size_t len);

#define BTM_TRACE_ERROR(...)
#define BTM_TRACE_DEBUG(...)