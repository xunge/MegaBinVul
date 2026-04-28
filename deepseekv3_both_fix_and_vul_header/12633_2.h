#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glob.h>
#include <ctype.h>
#include <unistd.h>

#define STREAM_READ 1

typedef struct bstr {
    char *start;
    int len;
} bstr;

typedef struct mf_t {
    struct mp_log *log;
    char **names;
    int nr_of_files;
} mf_t;

typedef struct mp_log {
    int dummy;
} mp_log;

typedef struct demuxer {
    struct mp_log *log;
    int stream_origin;
    void *cancel;
    void *global;
} demuxer;

typedef struct stream {
    int dummy;
} stream;

#define talloc_zero(ctx, type) ((type *)calloc(1, sizeof(type)))
#define talloc_size(ctx, size) (malloc(size))
#define talloc_free(ptr) free(ptr)
#define talloc_strdup(ctx, str) strdup(str)
#define MP_TARRAY_APPEND(ctx, arr, count, elem) do { \
    (arr) = realloc((arr), sizeof(*(arr)) * ((count) + 1)); \
    (arr)[(count)++] = (elem); \
} while (0)

#define mp_isdigit(c) isdigit(c)
#define mp_path_exists(path) (access(path, F_OK) == 0)
#define mp_path_isdir(path) (0)
#define mp_err(log, ...) fprintf(stderr, __VA_ARGS__)
#define mp_info(log, ...) fprintf(stdout, __VA_ARGS__)
#define mp_verbose(log, ...) fprintf(stdout, __VA_ARGS__)

static inline bstr bstr0(const char *s) {
    return (bstr){(char *)s, s ? (int)strlen(s) : 0};
}

static inline int bstrchr(bstr str, int c) {
    for (int i = 0; i < str.len; i++)
        if (str.start[i] == c)
            return i;
    return -1;
}

static inline bstr bstr_splice(bstr str, int start, int end) {
    if (start < 0) start += str.len;
    if (end < 0) end += str.len;
    end = end > str.len ? str.len : end;
    start = start > end ? end : start;
    return (bstr){str.start + start, end - start};
}

static inline bstr bstr_strip(bstr str) {
    while (str.len && isspace(*str.start)) {
        str.start++;
        str.len--;
    }
    while (str.len && isspace(str.start[str.len - 1]))
        str.len--;
    return str;
}

static inline char *bstrto0(void *talloc_ctx, bstr str) {
    char *s = talloc_size(talloc_ctx, str.len + 1);
    if (s) {
        memcpy(s, str.start, str.len);
        s[str.len] = '\0';
    }
    return s;
}

static inline char *bstrdup0(void *talloc_ctx, bstr str) {
    return bstrto0(talloc_ctx, str);
}

static inline void bstr_split_tok(bstr str, const char *sep, bstr *out_left, bstr *out_right) {
    int pos = bstrchr(str, *sep);
    if (pos < 0) {
        *out_left = str;
        *out_right = (bstr){NULL, 0};
    } else {
        *out_left = bstr_splice(str, 0, pos);
        *out_right = bstr_splice(str, pos + 1, str.len);
    }
}

static inline struct stream *stream_create(const char *filename, int flags, void *cancel, void *global) {
    return NULL;
}

static inline int stream_read_peek(struct stream *s, char *buf, int len) {
    return 0;
}

static inline int stream_tell(struct stream *s) {
    return 0;
}

static inline void stream_seek_skip(struct stream *s, int pos) {
}

static inline void free_stream(struct stream *s) {
}

static inline void mf_add(mf_t *mf, const char *fname) {
    MP_TARRAY_APPEND(mf, mf->names, mf->nr_of_files, talloc_strdup(mf, fname));
}