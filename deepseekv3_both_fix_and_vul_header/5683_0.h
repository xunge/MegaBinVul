#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LINESIZE 1024

enum {
    PFA_ASCII,
    PFA_EEXEC_TEST,
    PFA_HEX,
    PFA_BINARY
};

struct font_reader {
    void (*output_ascii)(const char *, int);
    void (*output_binary)(const unsigned char *, int);
    void (*output_end)(void);
};

int all_zeroes(const char *line);
int translate_hex_string(char *line, char *saved_orphan);