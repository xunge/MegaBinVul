#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ASCIILINESZ 1024

typedef struct dictionary dictionary;

typedef enum {
    LINE_EMPTY,
    LINE_COMMENT,
    LINE_SECTION,
    LINE_VALUE,
    LINE_ERROR
} line_status;

typedef enum {
    HIDE_ERRORED_LINE_CONTENT = 1
} load_options;

line_status iniparser_line(const char *input_line, char *section, char *key, char *value);
dictionary *dictionary_new(int size);
void dictionary_del(dictionary *d);
int dictionary_set(dictionary *d, const char *key, const char *val);