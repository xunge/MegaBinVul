#include <stdlib.h>
#include <stdbool.h>

struct commonio_entry {
    struct commonio_entry *prev;
    struct commonio_entry *next;
    char *line;
};

struct commonio_db {
    struct commonio_entry *head;
    struct commonio_entry *tail;
    bool changed;
};

#define KEEP_NIS_AT_END 1