#include <stdlib.h>

#define XCURSOR_COMMENT_MAX_LEN 1024
#define XCURSOR_COMMENT_VERSION 1

typedef unsigned int XcursorUInt;

typedef struct {
    XcursorUInt version;
    XcursorUInt comment_type;
    char *comment;
} XcursorComment;