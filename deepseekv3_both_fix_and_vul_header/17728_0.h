#include <stdint.h>
#include <sys/types.h>
#include <assert.h>

#define assert_cc(expr) static_assert(expr, #expr)

int safe_atou32(const char *s, uint32_t *ret);
int uid_is_valid(uid_t uid);

#define ENXIO 6