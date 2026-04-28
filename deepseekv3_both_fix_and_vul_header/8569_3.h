#include <stdint.h>
#include <stdlib.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <errno.h>
#include <limits.h>

typedef struct MsgHeader {
    int token;
    int type;
    int id;
    int error;
} MsgHeader;

typedef struct pb_field_t pb_field_t;

typedef struct pb_ostream_t {
    void *state;
    bool (*callback)(pb_ostream_t *stream, const uint8_t *buf, size_t count);
    size_t bytes_written;
    size_t max_size;
    const char *errmsg;
} pb_ostream_t;

class RilSapSocket {
public:
    void sendResponse(MsgHeader* hdr);
private:
    pthread_mutex_t write_lock;
    int commandFd;
};

extern const pb_field_t MsgHeader_fields[];
extern int blockingWrite_helper(int fd, const void *buf, size_t count);
extern void RLOGD(const char *fmt, ...);
extern void RLOGI(const char *fmt, ...);
extern void RLOGE(const char *fmt, ...);
extern void log_hex(const char *tag, const void *data, size_t size);
extern bool pb_get_encoded_size(size_t *size, const pb_field_t fields[], const void *src_struct);
extern pb_ostream_t pb_ostream_from_buffer(uint8_t *buf, size_t bufsize);
extern bool pb_write(pb_ostream_t *stream, const uint8_t *buf, size_t count);
extern bool pb_encode(pb_ostream_t *stream, const pb_field_t fields[], const void *src_struct);
extern const char *PB_GET_ERROR(pb_ostream_t *stream);