#include <linux/kernel.h>
#include <linux/string.h>
#include <linux/types.h>

#define ECRYPTFS_TAG_11_PACKET_TYPE 0x11
#define KERN_ERR "<1>"
#define KERN_WARNING "<4>"
#define unlikely(x) __builtin_expect(!!(x), 0)
#define EINVAL 22

extern int ecryptfs_parse_packet_length(unsigned char *data, size_t *body_size, size_t *length_size);

static int printk(const char *fmt, ...);