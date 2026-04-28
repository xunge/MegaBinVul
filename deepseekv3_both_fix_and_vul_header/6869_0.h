#include <stdio.h>
#include <ctype.h>

#define HEXDUMP_COLS 16

typedef struct {
    int dummy; 
} msg_info;

void print_message(msg_info msg_info, const char *format, ...);