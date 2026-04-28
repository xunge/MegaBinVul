#include <stdio.h>
#include <string.h>
#include <stdarg.h>

typedef unsigned int u32;

typedef enum {
    SAX_STATE_SYNTAX_ERROR
} GF_SAXState;

typedef struct {
    char *err_msg;
    u32 line;
    char *buffer;
    u32 current_pos;
    GF_SAXState sax_state;
} GF_SAXParser;