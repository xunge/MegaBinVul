#include <stdint.h>
#include <stdlib.h>

typedef uint32_t word32;
typedef uint8_t byte;

#define UINT32_SZ sizeof(word32)
#define WS_FATAL_ERROR (-1)
#define WS_MEMORY_E (-2)
#define WOLFSSH_FTP_FAILURE 0

#define DYNTYPE_BUFFER 0

typedef struct {
    void* heap;
} WOLFSSH_CTX;

typedef struct {
    WOLFSSH_CTX* ctx;
} WOLFSSH;

typedef struct {
    byte* data;
    word32 size;
    word32 idx;
} WS_SFTP_BUFFER;

#define WMALLOC(size, heap, type) malloc(size)
#define WFREE(ptr, heap, type) free(ptr)
#define WMEMCPY(dest, src, size) memcpy(dest, src, size)
#define WLOG(level, fmt, ...)

static void ato32(const byte* buf, word32* val) {
    *val = (buf[0] << 24) | (buf[1] << 16) | (buf[2] << 8) | buf[3];
}

static word32 wolfSSH_SFTP_buffer_idx(WS_SFTP_BUFFER* buffer) {
    return buffer->idx;
}

static word32 wolfSSH_SFTP_buffer_size(WS_SFTP_BUFFER* buffer) {
    return buffer->size;
}

static byte* wolfSSH_SFTP_buffer_data(WS_SFTP_BUFFER* buffer) {
    return buffer->data;
}

static void wolfSSH_SFTP_buffer_seek(WS_SFTP_BUFFER* buffer, int origin, word32 offset) {
    buffer->idx = offset;
}