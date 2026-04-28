#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h>

#define FALSE false
#define TRUE true
#define G_STRFUNC __func__

typedef struct wtap {
    FILE* random_fh;
} wtap;

typedef struct wtap_rec {
    int dummy;
} wtap_rec;

typedef struct Buffer {
    int dummy;
} Buffer;

typedef struct msg_t {
    int dummy;
} msg_t;

typedef bool gboolean;
typedef char gchar;
typedef int64_t gint64;

static inline int file_seek(FILE* fh, gint64 offset, int whence, int* err) {
    return fseek(fh, offset, whence);
}

static inline char* g_strdup(const char* str) {
    return strdup(str);
}

static inline const char* g_strerror(int errnum) {
    return strerror(errnum);
}

static inline gboolean candump_parse(FILE* fh, msg_t* msg, void* unused, int* err, gchar** err_info) {
    return TRUE;
}

static inline gboolean candump_write_packet(wtap_rec* rec, Buffer* buf, msg_t* msg, ...) {
    return TRUE;
}