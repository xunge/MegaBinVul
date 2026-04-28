#include <stddef.h>
#include <stdint.h>
#include <assert.h>
#include <stdexcept>

extern "C" {
int sgx_is_outside_enclave(const void *addr, size_t size);
void sgx_lfence(void);
void ocall_throw(const char *what);
void external_sort(uint8_t*, size_t, uint8_t*, size_t, uint8_t**, size_t*);
}