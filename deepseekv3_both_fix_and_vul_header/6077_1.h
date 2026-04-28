#include <stdio.h>

extern int uc_dyn_load(const char *path, int mode);
extern void uc_dyn_free(void);
extern void test_arm(void);
extern void test_thumb(void);