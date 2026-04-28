#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#define GCC_FMT_ATTR(n, m) __attribute__((format(printf, n, m)))

typedef struct QIOChannel QIOChannel;

#define TRACE(fmt, ...)
#define LOG(fmt, ...)

#define EIO 5

extern int nbd_negotiate_send_rep_len(QIOChannel *ioc, uint32_t type, uint32_t opt, size_t len);
extern int nbd_negotiate_write(QIOChannel *ioc, const char *buf, size_t len);

char *g_strdup_vprintf(const char *fmt, va_list ap);
void g_free(void *ptr);