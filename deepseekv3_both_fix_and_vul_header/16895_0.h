#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define HIGHLIGHT_NONE 0
#define HIGHLIGHT_COMMENT 1
#define HIGHLIGHT_COMMENT1 2
#define HIGHLIGHT_NUMBER 3
#define HIGHLIGHT_RESERVED 4

enum {
    OUTPUT_HTML
};

extern int is_reserved(const char *keyword);
extern void write_string(FILE *fp, const char *s, int output_type, size_t len);