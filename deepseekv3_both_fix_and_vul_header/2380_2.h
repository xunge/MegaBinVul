#include <stdio.h>
#include <sys/types.h>

struct key {
    char *description;
    struct {
        void *data[1];
    } payload;
    int flags;
};

struct seq_file {
    // Minimal stub for compilation
    FILE *file;
};

struct request_key_auth {
    pid_t pid;
    size_t callout_len;
};

static inline int key_is_instantiated(const struct key *key) {
    return !(key->flags & 1);
}

static inline void seq_puts(struct seq_file *m, const char *s) {
    fputs(s, m->file);
}

static inline void seq_printf(struct seq_file *m, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(m->file, fmt, args);
    va_end(args);
}