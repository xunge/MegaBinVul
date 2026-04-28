#include <stdio.h>
#include <stdbool.h>

struct seq_file {
    FILE *file;
};

struct key {
    const char *description;
    unsigned int datalen;
};

int seq_puts(struct seq_file *m, const char *s);
int seq_printf(struct seq_file *m, const char *fmt, ...);
bool key_is_instantiated(const struct key *key);