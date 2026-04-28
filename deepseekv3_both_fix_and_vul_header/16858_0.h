#include <stdio.h>
#include <string.h>

#define MAX_COMMENT_SIZE 256

typedef unsigned char uchar;

extern int ShowTags;

struct {
    char Comments[MAX_COMMENT_SIZE+1];
} ImageInfo;