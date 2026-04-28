#include <stdint.h>

typedef struct fio_protocol_s fio_protocol_s;
typedef struct http1pr_s {
    int stop;
} http1pr_s;

enum { FIO_EVENT_ON_DATA };
void fio_force_event(intptr_t uuid, int event);