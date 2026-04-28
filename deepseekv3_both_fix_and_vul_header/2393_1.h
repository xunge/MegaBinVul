#include <stddef.h>
#include <stdio.h>

#define BIG_KEY_FILE_THRESHOLD 0
#define big_key_len 0

struct key {
    char *description;
    union {
        void *data[1];
        unsigned long value;
    } payload;
};

struct seq_file;

int key_is_positive(const struct key *key);
int key_is_instantiated(const struct key *key);
void seq_puts(struct seq_file *m, const char *s);
void seq_printf(struct seq_file *m, const char *fmt, ...);