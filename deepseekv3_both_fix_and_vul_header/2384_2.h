#include <stdio.h>
#include <errno.h>

struct key {
    char *description;
    struct {
        void *data[1];
    } payload;
    unsigned datalen;
};

struct seq_file;

#define PTR_ERR(ptr) ((long)(ptr))
#define key_is_instantiated(key) (1)
#define dns_key_error 0

int seq_puts(struct seq_file *m, const char *s);
int seq_printf(struct seq_file *m, const char *fmt, ...);