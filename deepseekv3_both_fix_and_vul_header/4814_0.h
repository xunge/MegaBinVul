#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *str;
    size_t length;
    size_t allocated;
    void (*append)(void *, const char *, size_t);
    void (*append_char)(void *, char);
} mowgli_string_t;

#define XMLRPC_BUFSIZE 4096

mowgli_string_t *mowgli_string_create(void);