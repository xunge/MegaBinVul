#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

enum {
    POST_BINARY,
    POST_ASCII
};

static int blocktyp;
static char *font_name;

void output_current_post();
void t1mac_output_data(byte *data, int len);