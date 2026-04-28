#include <string.h>

#define BLKID_ERR_PARAM 1
#define BLKID_ERR_CACHE 2

#define DBG(type, msg)

static char *strip_line(char *s);
static char *skip_over_blank(char *s);
static char *skip_over_word(char *s);