#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define HPEE_MAX_LENGTH 1024
#define GFP_KERNEL 0
#define __user
#define loff_t off_t

extern unsigned char *eisa_eeprom_addr;

static inline unsigned char readb(const volatile void *addr) {
    return *(const volatile unsigned char *)addr;
}

static inline int copy_to_user(void *to, const void *from, unsigned long n) {
    memcpy(to, from, n);
    return 0;
}