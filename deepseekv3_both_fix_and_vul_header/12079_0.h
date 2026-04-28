#include <stddef.h>

extern size_t ksu_expected_size;
extern unsigned char *ksu_expected_hash;

int check_v2_signature(char *path, size_t expected_size, unsigned char *expected_hash);