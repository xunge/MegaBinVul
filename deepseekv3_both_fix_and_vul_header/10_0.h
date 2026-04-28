#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>

typedef struct gss_buffer_desc_struct {
    size_t length;
    void *value;
} gss_buffer_desc, *gss_buffer_t;

#define GSTD_MAXPACKETCONTENTS 65536
#define LOG_ERR 0
#define LOG_INFO 0
#define LOG_CRIT 0
#define LOG_DEBUG 0

#define LOG(level, msg)

extern int timed_read(int fd, void *buf, size_t count, int timeout);