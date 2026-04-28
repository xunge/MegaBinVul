#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define FALSE 0
#define PATH_MAX 4096

struct {
    unsigned long ThumbnailOffset;
    int ThumbnailAtEnd;
} ImageInfo;

int RegenThumbnail;
int ReplaceThumbnail(const char *FileName);
void ErrFatal(const char *msg);