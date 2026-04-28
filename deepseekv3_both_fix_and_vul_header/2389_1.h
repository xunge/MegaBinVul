#include <stdio.h>

struct key {
    char *description;
    struct {
        unsigned long nr_leaves_on_tree;
    } keys;
};

struct seq_file {
    FILE *file;
};

int key_is_instantiated(const struct key *key);
void seq_puts(struct seq_file *m, const char *str);
void seq_printf(struct seq_file *m, const char *fmt, ...);