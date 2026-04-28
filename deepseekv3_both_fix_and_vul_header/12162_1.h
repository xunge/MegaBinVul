#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#define SHA256_DIGEST_SIZE 32
#define CERT_MAX_LENGTH 1024

struct file;
typedef long long loff_t;
typedef unsigned int u32;

extern int ksu_kernel_read_compat(struct file *file, void *buf, size_t count, loff_t *pos);
extern void *ksu_sha256(const void *data, unsigned int len, unsigned char *hash);
extern void bin2hex(char *dst, const void *src, size_t count);
extern int pr_info(const char *fmt, ...);