#include <stddef.h>
#include <sys/types.h>

#define TRACE_IO 0
#define IO_DATAIN 0
#define IO_DISCONNECTED 1

struct io {
    // 需要根据实际实现补充成员
};

struct filter_session {
    struct io *io;
    int id;
    // 需要根据实际实现补充其他成员
};