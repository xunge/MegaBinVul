#include <stdint.h>
#include <assert.h>
#include <stdexcept>

#define SGX_AESGCM_IV_SIZE 12
#define SGX_AESGCM_MAC_SIZE 16

extern "C" {
    int sgx_is_outside_enclave(const void *addr, size_t size);
    void sgx_lfence(void);
    void encrypt(uint8_t *plaintext, uint32_t plaintext_length, uint8_t *ciphertext);
    void ocall_throw(const char *message);
}