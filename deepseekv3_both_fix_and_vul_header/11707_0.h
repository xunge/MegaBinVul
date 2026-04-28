#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define LOG_CONSOLE_BIT 0
#define LOG_INFO 0

extern FILE *log_op;
extern const char *terminate_banner;
extern unsigned long debug;
extern void log_message(int level, const char *format, ...);

static inline int __test_bit(int nr, const unsigned long *addr)
{
    return 1 & (addr[nr / (8 * sizeof(long))] >> (nr & (8 * sizeof(long) - 1)));
}