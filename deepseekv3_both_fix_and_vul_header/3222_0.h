#include <stdlib.h>
#include <errno.h>

#define AVERROR(e) (-(e))
#define ENOMEM 12

void *av_realloc_f(void *ptr, size_t nmemb, size_t size);