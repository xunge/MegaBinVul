#include <stdlib.h>
#include <string.h>

struct t_irc_server {
    char *prefix_modes;
    char *prefix_chars;
};

char *weechat_strndup(const char *s, size_t n);