#include <stddef.h>
#include <stdint.h>
#include <errno.h>

typedef int32_t key_serial_t;
typedef void* key_ref_t;
typedef const void* user_payload_t;

#define PAGE_SIZE 4096
#define KEY_NEED_WRITE 0x00000020
#define GFP_KERNEL 0

#define IS_ERR(x) ((uintptr_t)(x) > (uintptr_t)(-4095))
#define PTR_ERR(x) ((long)(x))

void* kmalloc(size_t size, int flags);
void kfree(const void* objp);
long copy_from_user(void* to, user_payload_t from, size_t n);

long lookup_user_key(key_serial_t id, int create, int perm);
long key_update(key_ref_t key_ref, const void* payload, size_t plen);
void key_ref_put(key_ref_t key_ref);

#define __user