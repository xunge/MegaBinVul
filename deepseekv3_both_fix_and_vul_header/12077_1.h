#include <stdint.h>

struct kernel_param;
static unsigned int ksu_expected_hash;
extern void ksu_invalidate_manager_uid(void);
extern int param_set_uint(const char *val, const struct kernel_param *kp);