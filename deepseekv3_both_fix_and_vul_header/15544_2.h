#include <stdint.h>
#include <sys/types.h>
#include <string.h>

#define HTTP_MAX_HEADER_LENGTH 8192
#define FIO_LOG_WARNING(msg)

typedef struct fio_protocol_s {
    void (*on_data)(intptr_t, struct fio_protocol_s *);
    void *opaque;
} fio_protocol_s;

typedef struct {
    char *buf;
    size_t buf_len;
    struct {
        fio_protocol_s protocol;
    } p;
} http1pr_s;

extern ssize_t fio_read(intptr_t uuid, void *buf, size_t count);
extern void fio_close(intptr_t uuid);
extern void http1_consume_data(intptr_t uuid, http1pr_s *p);
extern void http1_on_data(intptr_t uuid, fio_protocol_s *protocol);