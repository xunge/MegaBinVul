#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ADD_OVERFLOW(a, b, res) __builtin_add_overflow((a), (b), (res))

typedef uint32_t TEE_Result;
typedef unsigned long uaddr_t;

#define TEE_ERROR_ACCESS_DENIED 0xFFFF0006
#define TEE_SUCCESS 0x0

#define TEE_MEMORY_ACCESS_NONSECURE (1 << 0)
#define TEE_MEMORY_ACCESS_SECURE (1 << 1)
#define TEE_MEMORY_ACCESS_ANY_OWNER (1 << 2)
#define TEE_MEMORY_ACCESS_WRITE (1 << 3)
#define TEE_MEMORY_ACCESS_READ (1 << 4)

#define TEE_MATTR_SECURE (1 << 0)
#define TEE_MATTR_UW (1 << 1)
#define TEE_MATTR_UR (1 << 2)

#define CORE_MMU_USER_CODE_SIZE 4096
#define CORE_MMU_USER_PARAM_SIZE 4096

struct user_ta_ctx;

TEE_Result tee_mmu_user_va2pa_attr(const struct user_ta_ctx *utc, void *va, void **pa, uint32_t *attr);
bool tee_mmu_is_vbuf_inside_ta_private(const struct user_ta_ctx *utc, void *va, size_t size);